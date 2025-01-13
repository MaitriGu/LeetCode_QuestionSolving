class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>freq;
        int result=0;
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }
        for( const auto & pair:freq){
            if(pair.second<=2)result+=pair.second;
            else if( pair.second%2==1 && pair.second>=3)result+=1;
            else if(pair.second%2==0 && pair.second>=3) result+=2;
        }
        return result;
    }
};