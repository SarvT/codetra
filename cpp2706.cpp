class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int leftOver = money;
        leftOver -= prices[0];
        leftOver -= prices[1];
        if(leftOver>=0) return leftOver;
        return money;
    }
};
