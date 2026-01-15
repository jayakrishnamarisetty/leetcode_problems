class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int rug = 1, veda = 1;

        
        int cnt = 1;
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == hBars[i - 1] + 1) {
                cnt++;
            } else {
                cnt = 1;
            }
            rug = max(rug, cnt);
        }

        
        cnt = 1;
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == vBars[i - 1] + 1) {
                cnt++;
            } else {
                cnt = 1;
            }
            veda = max(veda, cnt);
        }

        int rv = min(rug + 1, veda + 1);
        return rv * rv;
    }
};
