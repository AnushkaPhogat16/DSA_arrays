class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        vector<int> grid1D;
        

        int rem = grid[0][0] % x;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] % x != rem) return -1; // Impossible case
                grid1D.push_back(grid[i][j]);
            }
        }
        
        // Sort to find median
        sort(grid1D.begin(), grid1D.end());
        int median = grid1D[grid1D.size() / 2];
        
        int operations = 0;
        for(int num : grid1D) {
            operations += abs(num - median) / x;
        }
        
        return operations;
    }
};
