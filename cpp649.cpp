// Leet
// Not worked
class Solution {
public:
    string predictPartyVictory(string senate) {
        string res;
        int cd=0, cr=0;
        queue<int> q;
        for(char c: senate) queue.emplace(c);
        // if (senate[senate.size()-1] == 'D') res = "Dire";
        // if (senate[senate.size()-1] == 'R') res = "Radiant";
        while(!q.empty()){
            if(q.front() == "R"){
                if(q.front()+1 == "D")
            }
            if(q.front() == "D"){
                cd++;
            }
        }
        return res;
    }
};


// Worked
class Solution {
public:
    string predictPartyVictory(string senate) {
        string res;
        int cd=0, cr=0, dBan=0, rBan=0;
        queue<char> q;
        for(char c: senate){
            q.push(c);
            if(c == 'R') cr++;
            else cd++;
        }
        while(cr && cd){
            char cur = q.front();
            q.pop();
            if(cur == 'D'){
                if(dBan){
                    dBan--;
                    cd--;
                } else{
                    rBan++;
                    q.push('D');
                }
            } else {
                if(rBan){
                    rBan--;
                    cr--;
                } else {
                    dBan++;
                    q.push('R');
                }
            }
        }
        return cr?"Radiant":"Dire";
    }
};
