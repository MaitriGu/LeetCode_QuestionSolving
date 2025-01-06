class Solution {
public:
    int firstUniqChar(string s) {
     unordered_map<char, int> elements;
        for (char c : s) {
            elements[c]++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (elements[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};