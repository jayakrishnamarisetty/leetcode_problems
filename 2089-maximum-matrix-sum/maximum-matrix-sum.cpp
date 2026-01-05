class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        long long s = 0;
        int neg = 0;
        int mn = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x = matrix[i][j];
                if (x < 0) neg++;
                s += abs(x);
                mn = min(mn, abs(x));
            }
        }

        if (neg % 2 == 1) {
            s -= 2 * mn;
        }

        return s;
    }
};
