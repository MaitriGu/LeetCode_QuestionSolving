class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       int pos=0;
       int neg=1;
       vector<int>rearranged(nums.size());
       for(int i=0;i<nums.size();i++){
        if(nums[i]>=0){
            rearranged[pos]=nums[i];
            pos+=2;
        }
        else{
            rearranged[neg]=nums[i];
            neg+=2;
        }
       }
        return rearranged;
    }
};