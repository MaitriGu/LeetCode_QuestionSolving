class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col_0 = -2;  // Marker to check if the first column should be zeroed
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // First pass: mark the rows and columns that should be zeroed
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;  // Mark the first cell of the row
                    if(j != 0) matrix[0][j] = 0;  // Mark the first cell of the column (if not the first column)
                    else col_0 = 0;  // Special marker for the first column
                }
            }
        }
        
        // Second pass: use the markers to set the appropriate cells to zero
        for (int i = 1; i < rows; i++) {
            for(int j = 1; j < cols; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // If the first row needs to be zeroed
        if(matrix[0][0] == 0) {
            for(int i = 0; i < cols; i++) {
                matrix[0][i] = 0;
            }
        }
        
        // If the first column needs to be zeroed
        if(col_0 == 0) {
            for(int i = 0; i < rows; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
