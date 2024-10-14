// didn't worked
class Solution {
    public long maxKelements(int[] nums, int k) {
        int score=0;
        int i=0;
        Arrays.sort(nums);
        while(k>0
        //  && (i>=0 && i<nums.length-1)
         ){
            k--;
            for(int j=0; j<nums.length-1; j++){
                if(nums[j]>nums[j+1]){
                    score+=nums[j];
                    nums[j]=(int)(Math.ceil(nums[j]/3));
                }
            }
        }
        return score;
    }
}




// worked
class Solution {
    public long maxKelements(int[] nums, int k) {
        long score=0;
        // Arrays.sort(nums);
        PriorityQueue<Integer> pq = new PriorityQueue<>(
            Collections.reverseOrder()
        );
        for(int it:nums) pq.add(it);

        while(k>0){
        //  && (i>=0 && i<nums.length-1)
            k--;
            int maxi = pq.poll();
            score+=maxi;
            pq.add((int)(Math.ceil(maxi/3.0)));

            // for(int j=0; j<nums.length-1; j++){
            //     if(nums[j]>nums[j+1]){
            //         nums[j]=(int)(Math.ceil(nums[j]/3));
            //     }
            // }
        }
        return score;
    }
}




// Logic was all same just using appropriate data structures is so important as PQ was solving the problem of sorting again after every iteration which was a show stopper to my solution.
