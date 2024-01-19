class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int i = 0,cnt = 0,prev = 0;
        sort(reservedSeats.begin(),reservedSeats.end());
        vector<int> vec;
        cnt+=2*(n-reservedSeats[reservedSeats.size()-1][0]);
        while(i<reservedSeats.size()){
            vec = vector<int>(10,1);
            int dRow = reservedSeats[i][0];
            if((prev+1)!=dRow) cnt+=2*(dRow-prev-1);
            prev = dRow;
            while(i<reservedSeats.size()  && reservedSeats[i][0]==dRow){
                vec[reservedSeats[i][1]-1] = 0;
                i++;
            }
            int c1 = vec[1] & vec[2] & vec[3] & vec[4] & vec[5] & vec[6] & vec[7] & vec[8];
            int c2 = (vec[1] && vec[2] && vec[3] && vec[4]) | (vec[3] & vec[4] & vec[5] & vec[6]) | (vec[5] & vec[6] & vec[7] & vec[8]);

            if(c1) cnt+=2;
            else if(c2) cnt+=1;
        }
        return cnt;
    }
};
