class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long leftS = 0, rightS= 0;
        for (int num : nums) {
            rightS += num;
        }
        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            leftS += nums[i];
            rightS -= nums[i];
            if (leftS >= rightS) {
                count++;
            }
        }

        return count;
    }
};