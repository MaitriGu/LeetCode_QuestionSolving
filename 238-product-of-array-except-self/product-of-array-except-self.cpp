class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    int n =nums.size();
    int p=1;
    int f=0;
    for(int i=0;i<n;i++){
        if(nums[i]==0){
            f++;
            continue;
        }
        p*=nums[i];
    } 
    if(f>1)
    p=0;
    for(int i=0;i<n;i++){
        if(nums[i]==0)
        nums[i]=p;
        else if(f==0)
        nums[i]=p/nums[i];
        else
        nums[i]=0;
    }   
    return nums;
    }
};