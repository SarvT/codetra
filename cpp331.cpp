class Solution {
public:
    bool isValidSerialization(string preorder) {
        int cnt = 1;
        stringstream ss(preorder); 
        string node;
        while(getline(ss, node, ',')) {
            cnt--;
            if(cnt < 0)return false;
            if(node != "#")cnt += 2;
        }
        return cnt == 0; 
    }
};
