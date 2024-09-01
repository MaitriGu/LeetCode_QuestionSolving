class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        // Sort the intervals based on the starting times
        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < n; i++) {
            // If ans is empty or the last interval in ans does not overlap with intervals[i]
            if (ans.empty() || ans.back()[1] < intervals[i][0]) {
                ans.push_back(intervals[i]); // Add the current interval
            } else {
                // There is an overlap, so merge the intervals
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};
