class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
     int element1=0;
     int element2=0;
     int cnt_1=0;
     int cnt_2=0;
     for(int i=0;i<nums.size();i++){
        if(cnt_1==0 && element2!=nums[i]){
            cnt_1=1;
            element1=nums[i];
        }
        else if(cnt_2==0 && element1!=nums[i]){
            cnt_2=1;
            element2=nums[i];
        }
        else if(element1==nums[i]) cnt_1++;
        else if(element2==nums[i]) cnt_2++;
        else{
            cnt_1--;
            cnt_2--;
        }
     } 
     vector<int>result;
     int base=nums.size()/3;
     cnt_1=0;
     cnt_2=0;
     for(int i=0;i<nums.size();i++){
        if(element1==nums[i])cnt_1++;
        else if(element2==nums[i])cnt_2++;
     }
     if(cnt_1>base) result.push_back(element1);
     if(cnt_2>base) result.push_back(element2);
     return result;
    }
};