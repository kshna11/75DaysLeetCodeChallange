class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> indexMap;
        vector <int> result;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (indexMap.find(complement) != indexMap.end()) {
                result.push_back(indexMap[complement]);
                result.push_back(i);
                return result;
            }
            indexMap[nums[i]] = i;
        }
        return result;
    }
};
