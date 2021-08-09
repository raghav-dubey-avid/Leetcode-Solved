/*In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.
*/





class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int, int>> rotten;
        int row = grid.size();
        int column = grid[0].size();
        int fresh = 0, time = 0;
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                if(grid[i][j] == 2)
                    rotten.push({i, j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }
        
        while(!rotten.empty()){
            
            int num = rotten.size();
            for(int i = 0; i < num; i++){
                
                int x_coord = rotten.front().first;
                int y_coord = rotten.front().second;
                rotten.pop();
                
                //Now we look at all the neighbours (4 directions)
                if(x_coord > 0 && grid[x_coord-1][y_coord] == 1)
                    {grid[x_coord-1][y_coord] = 2; fresh--; rotten.push({x_coord-1, y_coord});};
                
                if(y_coord > 0 && grid[x_coord][y_coord-1] == 1)
                    {grid[x_coord][y_coord-1] = 2; fresh--; rotten.push({x_coord, y_coord-1});};
                
                if(x_coord < row-1 && grid[x_coord+1][y_coord] == 1)
                    {grid[x_coord+1][y_coord] = 2; fresh--; rotten.push({x_coord+1, y_coord});};
                
                if(y_coord < column-1 && grid[x_coord][y_coord+1] == 1)
                    {grid[x_coord][y_coord+1] = 2; fresh--; rotten.push({x_coord, y_coord+1});};
            }
            
            //If we didn't rot any orange then only we increase the time
            if(!rotten.empty())
                time++;
        }
        
        return (fresh == 0) ? time : -1;
        
    }
};