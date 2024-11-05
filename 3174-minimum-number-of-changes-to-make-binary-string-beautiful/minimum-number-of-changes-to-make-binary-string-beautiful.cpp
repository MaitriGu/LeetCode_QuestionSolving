class Solution {
public:
    int minChanges(string s) {
        int min_changes_req=0;
        for(int i=0;i< s.size();i+=2){
            if(s[i]!=s[i+1])min_changes_req++;
        }
        return min_changes_req;
    }
};