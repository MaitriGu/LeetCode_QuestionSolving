class Solution {
private:
    const vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}}; 
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || visited[r][c] || grid[r][c] == 0) 
            return 0;
        visited[r][c] = true; 
        int fishes = grid[r][c];
        for (const auto& dir : dirs) {
            fishes += dfs(r + dir[0], c + dir[1], grid, visited);
        }
        return fishes; 
    }   
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int result = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false)); 
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    result = max(result, dfs(i, j, grid, visited));
                }
            }
        }
        return result;
    }
};
