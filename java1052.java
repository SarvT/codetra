// Partial
class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        // for(int i=0; i<customers.length; i++){

        // }
        int i=0, j=i+minutes, sum = 0, maxi = sum, prevSum = sum;
        while(i<customers.length && j<customers.length){
            prevSum = sum-customers[i++];
            sum+=customers[j++];
            maxi = Math.max(sum, prevSum);
        }
        return maxi;
    }

    public bool isGrumpy(int[] customers, int[] grumpy, int i){
        return grumpy[i];
    }
}



// worked
class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        int windowSum = 0, zeroSum = 0, maxWindowSum = 0, n = customers.length;

        for (int i = 0; i < n; i++) {
            if (!isGrumpy(grumpy, i)) zeroSum += customers[i];
            if (i < minutes) windowSum += (isGrumpy(grumpy, i) ? customers[i] : 0);
            else windowSum += (grumpy[i] == 1 ? customers[i] : 0) - (grumpy[i - minutes] == 1 ? customers[i - minutes] : 0);
            maxWindowSum = Math.max(maxWindowSum, windowSum);
        }

        return maxWindowSum + zeroSum;
    }

    public boolean isGrumpy(int[] grumpy, int i){
        if(grumpy[i]==1)return true;
        else return false;
    }
}
