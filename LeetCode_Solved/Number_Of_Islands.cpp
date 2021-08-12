/*

Problem Link : https://leetcode.com/problems/number-of-islands/

Problem Statement: Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1


*/


// Program Code:


/*

DFS Solution : 

Time Complexity : O( m*n )
Space : O( 1 )

*/


class Solution {
public:
    
     void dfs( vector<vector<char>>& matrix, int x_coord, int y_coord, int row, int column ) {
        
        // Boundary Condition for the matrix
        if( x_coord < 0 || x_coord >= row || y_coord < 0 || y_coord >= column || matrix[x_coord][y_coord] != '1' ) {
            return;
        }
        
        // Mark the current cell as visited
        matrix[x_coord][y_coord] = 'V';
        
        // Now make recursive calls in all 4 directions ( horizontally and vetically )
        dfs( matrix, x_coord + 1, y_coord, row, column );  // Down
        dfs( matrix, x_coord, y_coord + 1, row, column );  // Right
        dfs( matrix, x_coord - 1, y_coord, row, column );  // Top
        dfs( matrix, x_coord, y_coord - 1, row, column );  // Left
        
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        
        // Base Case
        if( grid.size() == 0 )
            return 0;

        int row_size = grid.size();
        int column_size = grid[0].size();
        
        int max_area_count = 0;
        
        for( int row = 0; row < row_size; ++row ) {
            for( int col = 0; col < column_size; ++col ) {
                if( grid[row][col] == '1' ) {
                    dfs( grid, row, col, row_size, column_size );
                    max_area_count++;
                }
            }
        }
        return max_area_count;
    }
};