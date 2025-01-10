class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxCharFreq(26, 0);
        for (const string& word : words2) {
            vector<int> tempFreq = countFrequencies(word);
            for (int i = 0; i < 26; ++i) {
                maxCharFreq[i] = max(maxCharFreq[i], tempFreq[i]);
            }
        }
        vector<string> universalWords;
        for (const string& word : words1) {
            vector<int> wordFreq = countFrequencies(word); 
            bool isUniversal = true;
            for (int i = 0; i < 26; ++i) {
                if (wordFreq[i] < maxCharFreq[i]) {
                    isUniversal = false;
                    break;  
                }
            }
            if (isUniversal) {
                universalWords.push_back(word);  
            }
        }

        return universalWords;
    }

private:
    vector<int> countFrequencies(const string& word) {
        vector<int> freq(26, 0); 
        for (char ch : word) {
            freq[ch - 'a']++; 
        }
        return freq;
    }
};
