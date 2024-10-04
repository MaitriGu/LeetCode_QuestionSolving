class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int n=skill.size();
        long long chemis=0;
        int target=skill[0]+skill[n-1];
        for(int i=0;i<n/2;i++){
            int curr_skill=skill[i]+skill[n-i-1];
            if(curr_skill!=target)return -1;
            chemis+=(long long)skill[i] * (long long)skill[n-i-1];
        }
        return chemis;
    }
};