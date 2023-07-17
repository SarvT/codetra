// gfg
string FirstNonRepeating(string A){
		    // Code here
		   queue<char> op;
           unordered_map<char,int> mp;
           string ans="";
           for(auto ptr : A){
               mp[ptr]++;
               if(mp[ptr]==1) op.push(ptr);
               while(!op.empty() && mp[op.front()]>1) op.pop();
               if(op.empty()) ans+="#";
               else ans+=op.front();
           }
    return ans;
		}
