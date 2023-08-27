// worked haha
class Solution
{
    public:
    string reverseWord(string str)
    {
        // Your code goes here
        int i=0, n=str.size()-1;
        while(i<n){
            char temp = str[i];
            str[i++]=str[n];
            str[n--]=temp;
        }
        return str;
    }
};
