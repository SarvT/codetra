// partial
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int k=0;
        int[] sol = new int[arr1.length];
        int[] sol2 = new int[arr1.length];
        int n = 0;
        for(int i=0; i<arr2.length; i++){
            for(int j=0; j<arr1.length; j++){
                if(arr1[j]==arr2[i]){
                    sol[k] = arr1[j];
                    k++;
                } else {
                    sol2[n] = arr2[i];
                    n++;
                }
            }

        }
        int x=0;
        while(sol2[x]!=0 || k<sol.length){
            sol[k++] = sol2[x];
        }
        return sol;
    }
}



class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        List<Integer> ans = new ArrayList<>();
        int n1 = arr1.length, n2 = arr2.length;
        
        for (int j = 0; j < n2; j++) {
            for (int i = 0; i < n1; i++) {
                if (arr1[i] == arr2[j]) {
                    ans.add(arr1[i]);
                    arr1[i] = -1;
                }
            }
        }
        
        List<Integer> remaining = new ArrayList<>();
        for (int i = 0; i < n1; i++) {
            if (arr1[i] > -1) remaining.add(arr1[i]);
        }
        
        remaining.sort(null);
        ans.addAll(remaining);
        
        int[] result = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) result[i] = ans.get(i);
        
        return result;
    }
}
