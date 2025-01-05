class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long result=0;
        vector<vector<long long>>minCost(26,vector<long long>(26,INT_MAX));
        if(source==target)return 0;
        for(int i=0;i< original.size();i++){
            int start=original[i]-'a';
            int end=changed[i]-'a';
            minCost[start][end]=min(minCost[start][end],(long long)cost[i]);
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    minCost[i][j]=min(minCost[i][j],minCost[i][k]+minCost[k][j]);
                }
            }
        }
        for(int i=0;i<source.size();i++){
            if(source[i]==target[i]){
                continue;
            }
            int sourceC=source[i]-'a';
            int targetC=target[i]-'a';
            if(minCost[sourceC][targetC]>=INT_MAX) return -1;
            result+=minCost[sourceC][targetC];
        }
        return result;
    }
};