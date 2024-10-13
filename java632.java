class Solution {

    public int[] smallestRange(List<List<Integer>> nums) {
        PriorityQueue<int[]> pq=new PriorityQueue<>(
            Comparator.comparingInt(a -> a[0])
        );

        int maxi=Integer.MIN_VALUE, st=0, en=Integer.MAX_VALUE;

        for (int i=0; i < nums.size(); i++) {
            pq.offer(new int[] { nums.get(i).get(0), i, 0 });
            maxi=Math.max(maxi, nums.get(i).get(0));
        }

        while (pq.size()==nums.size()) {
            int[] data=pq.poll();
            int mini=data[0], row=data[1], col=data[2];

            if (maxi - mini < en - st) {
                st=mini;
                en=maxi;
            }

            if (col + 1 < nums.get(row).size()) {
                int nextVal=nums.get(row).get(col + 1);
                pq.offer(new int[] { nextVal, row, col + 1 });
                maxi=Math.max(maxi, nextVal);
            }
        }

        return new int[] { st, en };
    }
}
