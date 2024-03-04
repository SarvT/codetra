// conditional, data structure

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        sort(tokens.begin(), tokens.end());
        deque<int> deque(tokens.begin(), tokens.end());//performing start and end pos ops
        while (!deque.empty()) {
            if (power >= deque.front()) {
                power -= deque.front();
                deque.pop_front();
                score++;
            } else if (deque.size() > 1 && score > 0) {
                power += deque.back();
                deque.pop_back();//taking the high score from back
                score--;
            } else return score;
        }
            return score;
    }
};
