class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp;
        for (int num : nums) {
            if (mp[num] >= 1)
                return true;
            mp[num]++;
        }
        return false;
    }
};