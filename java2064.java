class Solution {

    public int minimizedMaximum(int n, int[] quantities) {
        int m = quantities.length;

        List<int[]> typeStorePairsArray = new ArrayList<>();

        for (int i = 0; i < m; i++) {
            typeStorePairsArray.add(new int[] { quantities[i], 1 });
        }

        PriorityQueue<int[]> typeStorePairs = new PriorityQueue<>((a, b) ->
            Long.compare((long) b[0] * a[1], (long) a[0] * b[1])
        );

        typeStorePairs.addAll(typeStorePairsArray);

        for (int i = 0; i < n - m; i++) {
            int[] pairWithMaxRatio = typeStorePairs.poll();
            int totalQuantityOfType = pairWithMaxRatio[0];
            int storesAssignedToType = pairWithMaxRatio[1];

            typeStorePairs.offer(
                new int[] { totalQuantityOfType, storesAssignedToType + 1 }
            );
        }

        int[] pairWithMaxRatio = typeStorePairs.poll();
        int totalQuantityOfType = pairWithMaxRatio[0];
        int storesAssignedToType = pairWithMaxRatio[1];

        return (int) Math.ceil(
            (double) totalQuantityOfType / storesAssignedToType
        );
    }
}
