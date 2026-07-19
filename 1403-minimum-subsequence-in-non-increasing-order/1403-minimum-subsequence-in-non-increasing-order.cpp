class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int total = 0;

        for (int x : nums)
            total += x;

        sort(nums.begin(), nums.end(), greater<int>());

        vector<int> ans;
        int sum = 0;

        for (int x : nums) {
            ans.push_back(x);
            sum += x;

            if (sum > total - sum)
                break;
        }

        return ans;
    }
};