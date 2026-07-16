class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> rug;

        int mx = 0;


        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            rug.push_back(gcd(nums[i], mx));
        }

        
        sort(rug.begin(), rug.end());

        long long veda = 0;

    
        int l = 0;
        int r = n - 1;

        while (l < r) {
            veda += gcd(rug[l], rug[r]);
            l++;
            r--;
        }

        return veda;
    }
};