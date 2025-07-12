class Solution:
    def maxGold(self, mat):
        # code here
        res=0
        for j in range(1,len(mat[0])):
            for i in range(len(mat)):
                mat[i][j]+=max(mat[i-1][j-1] if i-1>=0 else 0,mat[i][j-1],mat[i+1][j-1] if i+1<len(mat) else 0)
                if j==len(mat[0])-1:
                    res=max(res,mat[i][j])
        return res
