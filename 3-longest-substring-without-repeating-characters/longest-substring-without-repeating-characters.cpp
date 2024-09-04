class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    if(s==" ") return 1;
    int size =s.size();
    if(size==1)return 1;
    unordered_map<char,int> mpp;
    int left=0;
    int right=0;
    int n =s.size()-1;
    int length=0;
    while(right<=n){
      if(mpp.find(s[right])!=mpp.end()){
        left=max(mpp[s[right]]+1,left);
      }
      mpp[s[right]]=right;
      length=max(length, (right-left+1));
      right++;
    }
    return length;
    }
};