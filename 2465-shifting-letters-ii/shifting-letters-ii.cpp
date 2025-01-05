class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> shift(s.size() + 1, 0);

        for (int i = 0; i < shifts.size(); i++) {
            int start = shifts[i][0], end = shifts[i][1], direction = shifts[i][2];
            if (direction == 1) {
                shift[start] += 1;
                shift[end + 1] -= 1;
            } else {
                shift[start] -= 1;
                shift[end + 1] += 1;
            }
        }

        int currentShift = 0;
        for (int i = 0; i < s.size(); i++) {
            currentShift += shift[i];
            s[i] = 'a' + ((s[i] - 'a' + currentShift) % 26 + 26) % 26;
        }
        
        return s;
    }
};
