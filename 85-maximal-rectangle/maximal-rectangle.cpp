class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> rug(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') rug[j] += 1;
                else rug[j] = 0;
            }

            stack<int> st;
            for (int j = 0; j <= m; j++) {
                int jk = (j == m ? 0 : rug[j]);
                while (!st.empty() && rug[st.top()] > jk) {
                    int veda = rug[st.top()];
                    st.pop();
                    int width = st.empty() ? j : j - st.top() - 1;
                    maxArea = max(maxArea, veda * width);
                }
                st.push(j);
            }
        }

        return maxArea;
    }
};
