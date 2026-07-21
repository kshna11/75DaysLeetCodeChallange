class Solution {
public:
    bool check(unordered_map<char,int>have,unordered_map<char,int>need){
        for(auto it : need){
            char c = it.first;
            int fneed = it.second;
            int fhave = have[c];
            if(fhave < fneed) return false;
        }
        return true;
    }


    bool canConstruct(string ransomNote, string magazine) {
        if(magazine.size() < ransomNote.size()) return false;
        unordered_map<char,int> have;
        unordered_map<char,int> need;
        for(int i = 0;i < magazine.size();i++) have[magazine[i]]++;
        for(int i = 0;i < ransomNote.size();i++) need[ransomNote[i]]++;
        return check(have,need);
    }
};
