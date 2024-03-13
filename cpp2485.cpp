//not worked
class Solution {
public:
    int pivotInteger(int n) {
        int sum=0, s1=1, s2=n, i=1, j=n;
        while(i<=n&&j>=1){
            if(s1==s2 && i==j) return i;
            else if(s1<s2){
                s1+=i;
                i++;
            }
            else if(s1>s2){
                s2+=j;
                j--;
            }
        }
        return -1;
    }
};



//worked
class Solution {
public:
    int pivotInteger(int n) {
        int sum = (n * (n + 1) / 2), pivot = sqrt(sum);
        return pivot * pivot == sum ? pivot : -1;
    }
};
