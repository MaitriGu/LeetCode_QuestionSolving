

class Solution {
public:
    vector<int> twoSum(std::vector<int>& nums, int target) {
    vector<int> newnum(2, -1);
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && nums[i] + nums[j] == target) {
                    newnum[0] = i;
                    newnum[1] = j;
                    return newnum;
                }
            }
        }
        return newnum;
    }
};
