class Solution {
public:
    int mirrorDistance(int n) {
        int x = n;   
        int rug = 0;

        while (n != 0) {
            int v = n % 10;
            rug = rug * 10 + v;
            n = n / 10;
        }

        return abs(rug - x);
    }
};