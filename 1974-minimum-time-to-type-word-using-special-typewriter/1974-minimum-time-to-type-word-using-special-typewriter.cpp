class Solution {
public:
    int minTimeToType(string word) {

        char current = 'a';
        int time = 0;

        for(char ch : word){

            int diff = abs(ch-current);
                                        
            time += min(diff,26-diff);

            time++;

            current = ch;
        }

        return time;
    }
};