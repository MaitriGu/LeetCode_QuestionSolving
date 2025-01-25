class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> sorted(nums);
        sort(sorted.begin(),sorted.end());
        int currG=0;
        unordered_map<int,int> numToG;
        numToG.insert(pair<int,int>(sorted[0],currG));
        unordered_map<int,vector<int>> gToList;
        gToList.insert(pair<int,vector<int>>(currG,vector<int>(1,sorted[0])));
        for (int i = 1; i < nums.size(); i++) {
            if (abs(sorted[i] - sorted[i - 1]) > limit) {
                currG++;
            }
            numToG.insert(pair<int, int>(sorted[i], currG));
            if (gToList.find(currG) == gToList.end()) {
                gToList[currG] = vector<int>();
            }
            gToList[currG].push_back(sorted[i]);
        }
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int group = numToG[num];
            nums[i] = *gToList[group].begin();
            gToList[group].erase(gToList[group].begin());
        }
        return nums;
    }
};