class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        map<string,int>m;
        
        m["I"]=1,m["IV"]=4,m["V"]=5,m["IX"]=9,m["X"]=10;
        m["XL"]=40,m["L"]=50,m["XC"]=90,m["C"]=100,m["CD"]=400,m["D"]=500;
        m["CM"]=900,m["M"]=1000;
        
            int  i=0,ans=0,j=0;
            while(i<str.length()){
                
                if(i+1<str.length() && m.find(str.substr(i,2))!=m.end())
                  j=2;
                else j=1;
                ans+=m[str.substr(i,j)];
                i+=j;
            }
            return ans;
    }
};
