class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n =nums.size();
        int result=0;
        sort(nums.begin(),nums.end());
        int median=nums[n/2];
        for(int i=0;i<n;i++){
            result+=abs(nums[i]-median);
        }
        return result;
    }
};