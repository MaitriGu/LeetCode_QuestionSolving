class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses,0);
        for(auto edge:prerequisites){
            graph[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0)q.push(i);
        }
        vector<unordered_set<int>> preqs(numCourses);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int neighbor:graph[node]){
                preqs[neighbor].insert(node);
                for(int prereq:preqs[node]){
                    preqs[neighbor].insert(prereq);
                }
                if(--inDegree[neighbor]==0)q.push(neighbor);
            }
        }
        vector<bool>results;
        for(const auto &query:queries){
            results.push_back(preqs[query[1]].count(query[0]));
        }
        return results;
    }
};