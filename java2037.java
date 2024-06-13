// worked
class Solution {
    public int minMovesToSeat(int[] seats, int[] students) {
        Arrays.sort(seats);
        Arrays.sort(students);
        int cnt=0;
        for(int i=0; i<seats.length; i++){
            if(seats[i]<students[i]){
                cnt+=(students[i]-seats[i]);
            } else {
                cnt+=(seats[i]-students[i]);
            }
        }
        return cnt;
    }
}
