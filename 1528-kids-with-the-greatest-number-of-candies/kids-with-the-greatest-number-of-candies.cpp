class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int maxCandies = 0;
        for (int candy : candies) {
            maxCandies = max(maxCandies, candy);
        }
    vector<bool> result;
    for(int i=0;i<candies.size();i++){
        if(candies[i]+extraCandies>=maxCandies)
        result.push_back(true);
        else
        result.push_back(false);
    } 
    return result;   
    }
};