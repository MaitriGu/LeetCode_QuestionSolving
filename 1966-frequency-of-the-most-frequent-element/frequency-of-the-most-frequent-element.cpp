class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
      sort(nums.begin(), nums.end());
        int left = 0;
        int max_freq = 0;
        long curr_sum = 0;
        for (int right = 0; right < nums.size(); right++) {
            long target = nums[right];
            curr_sum += target; 
            while ((right - left + 1) * target - curr_sum > k) {
                curr_sum -= nums[left];
                left++;
            }
            max_freq = max(max_freq, right - left + 1);
        }
        return max_freq;
    }
};