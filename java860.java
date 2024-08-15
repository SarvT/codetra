//worked
class Solution {
    public boolean lemonadeChange(int[] bills) {
        int[] cnt={0, 0, 0};
        for(int i:bills){
            if(i==5) cnt[0]++;
            else if(i==10){
                cnt[1]++;
                if(cnt[0]>0)cnt[0]--;
                else return false;
            } 
            else if(i==20){
                if(cnt[1]>0 && cnt[0]>0){
                    cnt[1]--;
                    cnt[0]--;
                } else if(cnt[0]>=3)cnt[0]-=3;
                else return false;

            }
        }
        return true;
    }
}
