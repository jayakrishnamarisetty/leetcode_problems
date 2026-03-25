class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        long long total = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                total += grid[i][j];
            }
        }
        
        if(total % 2) return false;
        
        long long target = total / 2;
        
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            long long rowSum = 0;
            for(int j = 0; j < m; j++) {
                rowSum += grid[i][j];
            }
            sum += rowSum;
            if(sum == target) return true;
        }
        
        sum = 0;
        for(int j = 0; j < m; j++) {
            long long colSum = 0;
            for(int i = 0; i < n; i++) {
                colSum += grid[i][j];
            }
            sum += colSum;
            if(sum == target) return true;
        }
        
        return false;
    }
};