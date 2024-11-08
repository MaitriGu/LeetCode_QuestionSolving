class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n =nums.size();
        int j=nums.size()-1;
        int maxi=pow(2,maximumBit)-1;
        vector<int> result(n,0);
        int xored=0;
        for(int i=0;i<n;i++){
            xored=xored^nums[i];
            result[j]=xored^maxi;
            j--;
        }
        return result;
    }
};