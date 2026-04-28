class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> rug;
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rug.push_back(grid[i][j]);
            }
        }

        sort(rug.begin(), rug.end());
        int veda = rug[rug.size() / 2], jk = 0;

        for (int num : rug) {
            int diff = abs(num - veda);
            if (diff % x != 0) return -1;
            jk += diff / x;
        }

        return jk;
    }
};
