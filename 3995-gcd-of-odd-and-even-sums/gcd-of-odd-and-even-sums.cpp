class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int rug = 0;   
        int veda = 0;  

        for (int i = 1; i <= n; i++) {
            rug += 2 * i;
            veda += 2 * i - 1;
        }

        return gcd(rug, veda);
    }
};