class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n =favorite.size();
        vector<int> inDegree(n,0);
        for(int person=0;person<n;person++){
            inDegree[favorite[person]]++;
        }
        queue<int>q;
        for(int person=0;person<n;person++){
            if(inDegree[person]==0){
                q.push(person);
            }
        }
        vector<int> depth(n,1);
        while(!q.empty()){
            int currNode=q.front();
            q.pop();
            int nextNode=favorite[currNode];
            depth[nextNode]=max(depth[nextNode],depth[currNode]+1);
            if(--inDegree[nextNode]==0){
                q.push(nextNode);
            }
        }
        int longestCycle=0;
        int twoCycle=0;
        for(int person=0;person<n;person++){
            if(inDegree[person]==0)continue;
            int cycleLen=0;
            int curr=person;
            while(inDegree[curr]!=0){
                inDegree[curr]=0;
                cycleLen++;
                curr=favorite[curr];
            }
            if(cycleLen==2){
                twoCycle+=depth[person]+depth[favorite[person]];
                }
            else{
                longestCycle=max(longestCycle,cycleLen);
            }
        }
        return max(longestCycle,twoCycle);
    }
};