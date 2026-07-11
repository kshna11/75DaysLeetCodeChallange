#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSame(string &word, string &str2, int start, int m) {
        for (int j = 0; j < m; j++) {
            if (word[start + j] != str2[j])
                return false;
        }
        return true;
    }

    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int N = n + m - 1;

        string word(N, '%');
        vector<bool> canChange(N, false);

        // Place all mandatory T substrings
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] != '%' && word[i + j] != str2[j])
                        return "";
                    word[i + j] = str2[j];
                }
            }
        }

        // Fill remaining positions with 'a'
        for (int i = 0; i < N; i++) {
            if (word[i] == '%') {
                word[i] = 'a';
                canChange[i] = true;
            }
        }

        // Handle F substrings
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F' && isSame(word, str2, i, m)) {

                bool changed = false;

                // Change from rightmost position
                for (int k = i + m - 1; k >= i; k--) {
                    if (canChange[k]) {
                        int idx = k - i;

                        // Make this character different from str2
                        word[k] = (str2[idx] == 'a') ? 'b' : 'a';
                        changed = true;
                        break;
                    }
                }

                if (!changed)
                    return "";
            }
        }

        return word;
    }
};