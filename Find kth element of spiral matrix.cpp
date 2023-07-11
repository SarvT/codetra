gfg
not worked
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int t = 0, b = n-1;
 		int l = 0, r = m-1;
 		while(t<=b && l<=r){
 		    for(int i=l; i<=r; i++){
 		        if(--k == 0) return a[t][i];
 		    }
 		    t++;
 		    for(int i=t; i<=b; i++){
 		        if(--k == 0) return a[i][r];
 		    }
 		    r--;
 		    if(t<=b){
     		    for(int i=r; i>=l; i++){
     		        if(--k == 0) return a[b][i];
     		    }
     		    b--;
 		    }
 		    if(l<=r){
     		    for(int i=b; i>=t; i++){
     		        if(--k == 0) return a[i][l];
     		    }
     		    l++;
 		    }
 		    
 		}
 		return -1;
    }
};

worked
int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int top = 0, bottom = n - 1, left = 0, right = m - 1;

        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; i++)
            {
                if (--k == 0) return a[top][i];
            }
            top++;

            for (int i = top; i <= bottom; i++)
            {
                if (--k == 0) return a[i][right];
            }
            right--;

            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    if (--k == 0) return a[bottom][i];
                }
                bottom--;
            }

            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    if (--k == 0) return a[i][left];
                }
                left++;
            }
        }

        return a[0][0];
    }
