class Solution {
public:
    bool check(unordered_map<char,int>& bl, unordered_map<char,int>& txt) {
        for (auto it : bl) {
            char c = it.first;
            int fneed = it.second;

            if (txt[c] < fneed)
                return false;
        }

        for (auto it : bl) {
            txt[it.first] -= it.second;
        }

        return true;
    }

    int maxNumberOfBalloons(string text) {
        string ball = "balloon";
        unordered_map<char,int> bl, txt;

        for (char c : ball)
            bl[c]++;

        for (char c : text)
            txt[c]++;

        int cnt = 0;
        while (check(bl, txt))
            cnt++;

        return cnt;
    }
};