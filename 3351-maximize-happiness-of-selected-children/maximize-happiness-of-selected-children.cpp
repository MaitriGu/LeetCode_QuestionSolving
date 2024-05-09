class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
    sort(happiness.begin(),happiness.end(),greater<int>());
    long long  output=0;
    for(int i=0;i<happiness.size() &&k>0;i++){
        if(happiness[i]-i>0 ){
        output+=happiness[i]-i;
            k--;
        }
        else break;
        }
        return output;
    }
};