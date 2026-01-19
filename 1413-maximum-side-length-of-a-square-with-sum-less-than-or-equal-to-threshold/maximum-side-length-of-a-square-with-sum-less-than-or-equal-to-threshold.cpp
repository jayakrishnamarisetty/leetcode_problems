class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> rug(n + 1, vector<int>(m + 1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                rug[i][j] = mat[i-1][j-1] + rug[i-1][j] + rug[i][j-1] - rug[i-1][j-1];
            }
        }

        int low = 0, high = min(n, m), ans = 0;

        while(low <= high){
            int veda = (low + high) / 2;
            bool ok = false;

            for(int i = veda; i <= n; i++){
                for(int j = veda; j <= m; j++){
                    int sum = rug[i][j] - rug[i-veda][j] - rug[i][j-veda] + rug[i-veda][j-veda];
                    if(sum <= threshold){
                        ok = true;
                        break;
                    }
                }
                if(ok) break;
            }

            if(ok){
                ans = veda;
                low = veda + 1;
            } else {
                high = veda - 1;
            }
        }

        return ans;
    }
};
