class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        vector<int> parent(n,-1);
        vector<int> depth(n,0);
        for(auto edge:edges){
            adjList[edge[0]-1].push_back(edge[1]-1);
            adjList[edge[1]-1].push_back(edge[0]-1);
            Union(edge[0]-1,edge[1]-1,parent,depth);
        }
        unordered_map<int,int> numGroupsComponents;
        for(int node=0;node<n;node++){
            int numGroups=getGroups(adjList,node,n);
            if(numGroups==-1)return -1;
            int rootNode=find(node,parent);
            numGroupsComponents[rootNode]=max(numGroupsComponents[rootNode],numGroups);
        }
        int totalGroups=0;
        for(auto[rootNode,numGroups]:numGroupsComponents){
            totalGroups+=numGroups;
        }
        return totalGroups;
    }
private:
     int find(int node,vector<int> & parent){
        while(parent[node]!=-1) node=parent[node];
        return node;
     } 
     void Union(int node1,int node2,vector<int> & parent,vector<int> & depth){
        node1=find(node1,parent);
        node2=find(node2,parent);
        if(node1==node2) return;
        if(depth[node1]<depth[node2]) swap(node1,node2);
        parent[node2]=node1;
        if(depth[node1]==depth[node2])depth[node1]++;
     }  
     int getGroups(vector<vector<int>> & adjList,int srcNode,int n ){
        queue<int> nodeQueue;
        vector<int> layer(n,-1);
        nodeQueue.push(srcNode);
        layer[srcNode]=0;
        int deepest=0;
        while(!nodeQueue.empty()){
            int numNodesLayer=nodeQueue.size();
            for(int i=0;i<numNodesLayer;i++){
                int currNode=nodeQueue.front();
                nodeQueue.pop();
                for(int neighbor:adjList[currNode]){
                    if(layer[neighbor]==-1){
                        layer[neighbor]=deepest+1;
                        nodeQueue.push(neighbor);
                    }
                    else{
                        if(layer[neighbor]==deepest) return -1;
                    }
                }
            }
            deepest++;
        }
        return deepest;
     }
};