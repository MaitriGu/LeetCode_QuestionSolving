class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char>letters;
        for(char c:s){
            letters.insert(c);
        }
        int result=0;
        for(char letter:letters){
            int i=-1;
            int j=0;
            for(int k=0;k<s.size();k++){
                if(s[k]==letter){
                    if(i==-1)i=k;
                j=k;
            }
            }
        unordered_set<char>betweens;
        for(int k=i+1;k<j;k++){
            betweens.insert(s[k]);
        }
        result+=betweens.size();
        }
        return result;
    }
};