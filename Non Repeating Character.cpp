char nonrepeatingCharacter(string S)
    {
       //Your code here
       unordered_map<char, int> mp;
       for(char c: S) mp[c]++;
       for(char c: S){
           if(mp[c]==1) return c;
       }
       
       
       return '$';
       
    }
