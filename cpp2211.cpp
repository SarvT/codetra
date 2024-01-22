class Solution {
public:
    int countCollisions(string directions) {
        int cnt = 0;
        for (int j = 0; j < directions.size(); j++) {
            if (directions[j] == 'S') continue;
            if (j + 1 < directions.size() && directions[j] == 'R' && directions[j + 1] != 'R') {
                if (directions[j + 1] == 'L') {
                    directions[j + 1] = 'S';
                    cnt += 1;
                }
                directions[j] = 'S';
                cnt += 1;

            }
            if (j - 1 >= 0 && directions[j] == 'L' && directions[j - 1] != 'L') {
                if (directions[j - 1] == 'R'){
                    directions[j - 1] = 'S';
                    cnt += 1;
                }
                directions[j] = 'S';
                cnt +=  1;
            } 
            if (directions[j] == 'S') {
                int i = j - 1;
                while (i >= 0 && directions[i] == 'R') {
                    cnt++;
                    i--;
                }   
            }
        }
        
        return cnt;
    }
};
