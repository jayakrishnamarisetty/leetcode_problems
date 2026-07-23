class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int total = n * m;
        
        vector<vector<int>> rug(n, vector<int>(m));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int veda = (i * m + j + k) % total;
                
                int rv = veda / m;
                int cv = veda % m;
                
                rug[rv][cv] = grid[i][j];
            }
        }
        
        return rug;
    }
};