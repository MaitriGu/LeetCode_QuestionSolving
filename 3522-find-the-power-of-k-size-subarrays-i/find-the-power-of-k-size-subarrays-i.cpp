class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n =nums.size();
        vector<int>result(n-k+1,-1);
        deque<int>indexDeq;
        for(int curr=0;curr<n;curr++){
            if(!indexDeq.empty() && indexDeq.front()< curr-k+1) indexDeq.pop_front();
            if(!indexDeq.empty() && nums[curr]!=nums[curr-1]+1) indexDeq.clear();
            indexDeq.push_back(curr);
            if(curr>=k-1){
                if(indexDeq.size()==k) result[curr-k+1]=nums[indexDeq.back()];
                else result[curr-k+1]=-1;
            }
        }
        return result;
    }
};