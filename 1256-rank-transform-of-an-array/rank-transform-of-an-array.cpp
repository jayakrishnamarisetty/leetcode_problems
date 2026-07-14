class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> rug = arr;
        sort(rug.begin(), rug.end());
        unordered_map<int, int> jk;
        
        int rank = 1;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || rug[i] != rug[i - 1]) {
                jk[rug[i]] = rank++;
            }
        }
        
        for (int &x : arr) {
            x = jk[x];
        }

        return arr;
    }
};
