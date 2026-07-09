class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long curr = mass;
        for(int &num : asteroids){
            if(curr >= num){
                curr+=num;
            }
            else{
                return false;
            }
        }
        return true;
    }
};