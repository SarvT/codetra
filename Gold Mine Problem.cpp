 int ans=0;
        for (int j=1; j<m;j++){
            for (int i=0; i<n;i++ ){
                int maximum=INT_MIN;
                if (i-1>=0 and j-1>=0) maximum=max(maximum,M[i-1][j-1]);
                if (j-1>=0) maximum=max(maximum,M[i][j-1]);
                if (i+1<n and j-1>=0)  maximum=max(maximum,M[i+1][j-1]);
                M[i][j]+=maximum;
                ans=max(ans,M[i][j]);
                
            }
        }
        return ans;
