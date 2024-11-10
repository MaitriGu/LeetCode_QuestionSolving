class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> hash(32, 0);  
        int left = 0;
        int right = 0;    
        int n = nums.size(); 
        int currentOR = 0;          
        int ans = INT_MAX;    
        while (right < n) {
            currentOR |= nums[right];
            for (int i = 0; i < 32; i++) {
                if (nums[right] & (1 << i)) { 
                    hash[i]++;
                }
            } 
            while (left <= right && currentOR >= k) {
                ans = min(ans, right - left + 1);
                for (int i = 0; i < 32; i++) {
                    if (nums[left] & (1 << i)) { 
                        hash[i]--;
                        if (hash[i] == 0) {
                            currentOR-= (1 << i);
                        }
                    }
                }
                left++;
            }
            right++;
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};