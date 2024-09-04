class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mpp;
    int index_1=0;
    int index_2=0;
    for (int i = 0; i < nums.size(); i++) {
        int num =nums[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            index_1=mpp[moreNeeded];
            index_2=i;
            return {mpp[moreNeeded],i};
        }
        mpp[num] = i;
    }
    return {index_1,index_2};
    }
};