class Solution {
    public long dividePlayers(int[] skill) {
        int freq[] = new int[1001];
  
        int cnt = 0;
        for(int x : skill){
            freq[x]++;
            
            cnt +=x;
        } 
        if(cnt%(skill.length/2)!=0)return -1;

        int perTeamSkill = cnt/(skill.length/2);
        long chem = 0;

        for(int s : skill){
            int partnerVal = perTeamSkill - s; 
            if(freq[partnerVal]==0)
            return -1;
            chem += (long)s*(long)partnerVal;
            freq[partnerVal]--;
        }
        return chem/2;
    }
}
