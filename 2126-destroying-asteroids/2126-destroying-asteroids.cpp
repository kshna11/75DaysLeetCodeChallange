class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        for(int &num : asteroids){
            if(mass >= num){
                mass+=num;
            }
            else{
                return false;
            }
        }
        return true;
    }
};