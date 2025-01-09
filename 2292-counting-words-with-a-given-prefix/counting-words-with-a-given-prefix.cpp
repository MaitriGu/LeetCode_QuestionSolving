class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int result = 0;
        for (int i = 0; i < words.size(); i++) {
            if (words[i].size() >= pref.size() && words[i].compare(0, pref.size(), pref) == 0) {
                result++;
            }
        }
        return result;
    }
};
