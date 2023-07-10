gfg
not worked 
void transpose(vector<vector<int> >& matrix, int n)
    { 
        // code here 
        for(int i=0; i<n; i++){
            int j=i+1, k=i+1;
            while(j < n && k < n){
                int tmp = matrix[j][k];
                matrix[j][k] = matrix[k][j];
                matrix[k][j] = tmp;
              j++;
              k++;
            }
        }
    }


worked
void transpose(vector<vector<int> >& matrix, int n)
    { 
        // code here 
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++) swap(matrix[i][j], matrix[j][i]);
        }

    }
