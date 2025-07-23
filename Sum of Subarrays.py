class Solution:
    def subarraySum(self, arr):
        # code 
        n=len(arr)
        return sum((i+1)*(n-i)*arr[i] for i in range(n))

