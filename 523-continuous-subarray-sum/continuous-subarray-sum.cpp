class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        int n = nums.size();
        int mod;
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            mod = sum % k;
            if (mod < 0) mod += k;
            
            if (mp.find(mod) == mp.end()) {
                mp[mod] = i;
            } else {
                if ((i - mp[mod]) > 1) return true;
            }
        }  
        return false;  
    }
};
