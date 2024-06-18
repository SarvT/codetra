class Solution {
    public int floorBinSearch(int[][] work, int worker, int n)
    {
        int ind = -1, low = 0, high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(work[mid][0] <= worker){
                ind = mid;
                low = mid + 1;
            }
            else if(work[mid][0] > worker)high = mid - 1;
        }
        return ind;
    }
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
int totalProfit = 0;
        int n = profit.length, m = worker.length;
        int[][] work = new int[n][2];
        for(int i = 0; i < n; i ++){
            work[i][0] = difficulty[i];
            work[i][1] = profit[i];
        }
        Arrays.sort(work, Comparator.comparingDouble(o -> o[0]));
        int[] prefixProfit = new int[n];
        for(int i = 0, mp = Integer.MIN_VALUE; i < n; i ++){
            mp = Math.max(mp, work[i][1]);
            work[i][1] = mp;
        }
        for(int i = 0; i < m; i ++){
            int ind = floorBinSearch(work, worker[i], n);
            if(ind != -1)totalProfit = totalProfit + work[ind][1];
        }
        return totalProfit;
    }
}
