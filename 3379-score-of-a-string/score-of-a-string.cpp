class Solution {
public:
    int scoreOfString(string s) {
        unordered_map<char,int> rug;

        for(auto c : s){
            rug[c] = int(c);
        }

        int veda = 0;

        for(int i = 1; i < s.size(); i++){
            int rv = abs(rug[s[i]] - rug[s[i-1]]);
            veda += rv;
        }

        return veda;
    }
};