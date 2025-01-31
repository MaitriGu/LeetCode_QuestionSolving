class Solution {
public:
    int getsValue(int row,int col,vector<vector<int>> & grid){
        return (row<0 || col<0 || row>=grid.size() || col>=grid[0].size()) ?0:grid[row][col];
    }
    int fillsIsland(int r,int c,int color,vector<vector<int>> & grid){
        if(getsValue(r,c,grid)!=1) return 0;
        grid[r][c]=color;
        return  1+fillsIsland(r+1,c,color,grid)+fillsIsland(r-1,c,color,grid)+fillsIsland(r,c+1,color,grid)+fillsIsland(r,c-1,color,grid);
    }
    int largestIsland(vector<vector<int>>& grid) {
       vector<int>islandSize={0,0};
       int result=0;
       int row=grid.size();
       int col=grid[0].size();
       for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]==1){
                islandSize.push_back(fillsIsland(i,j,islandSize.size(),grid));
            }
        }
       } 
       for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]==0){
                unordered_set<int>neighborIslands={ getsValue(i+1,j,grid),getsValue(i-1,j,grid),getsValue(i,j+1,grid),getsValue(i,j-1,grid)};
                int newSize=1;
                for(int color:neighborIslands){
                    newSize+=islandSize[color];
                }
                result=max(result,newSize);
            }
        }
       }
       return result==0 ? row*col : result;
    }
};