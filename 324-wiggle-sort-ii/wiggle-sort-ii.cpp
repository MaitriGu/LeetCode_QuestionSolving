class Solution {
public:
    void wiggleSort(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<int>result=nums;
     int left=0;
     int right=nums.size()-1;
     int mid=(left+right)/2 +1;
     while(right >= 0) {
    if (right % 2 == 1) {
        nums[right] = result[mid];
        mid++;
    } else {
        nums[right] = result[left];
        left++;
    }
    right--;
    }
    }
};