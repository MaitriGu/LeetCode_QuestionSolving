class Solution {
public:
    vector<string> stringMatching(vector<string> &words) {
        vector<string> match;
        for (int curr = 0; curr< words.size();curr++) {
            for (int j = 0; j < words.size();j++) {
                if (curr == j)
                    continue; 
                if (isSubstringOf(words[curr],words[j])) {
                    match.push_back(words[curr]);
                    break; 
                }
            }
        }
        return match;
    }

private:
    bool isSubstringOf(string &curr, string &j) {
        for (int i = 0; i < j.size(); i++) {
            bool check = true;
            for (int k= 0; k < curr.size(); k++) {
                if (i + k >= j.size() || j[i + k] != curr[k]) {
                    check = false;  
                    break;
                }
            }
            if (check) {
                return true;
            }
        }
        return false; 
    }
};