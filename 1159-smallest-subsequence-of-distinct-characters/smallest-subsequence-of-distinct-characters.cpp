class Solution {
public:
    string smallestSubsequence(string s) {
        map<char, int> rug;
        map<char, bool> vedda;

        for (char c : s)
            rug[c]++;

        string ans = "";

        for (char c : s) {
            rug[c]--;

            if (vedda[c])
                continue;

            while (!ans.empty() &&
                   ans.back() > c &&
                   rug[ans.back()] > 0) {
                vedda[ans.back()] = false;
                ans.pop_back();
            }

            ans.push_back(c);
            vedda[c] = true;
        }

        return ans;
    }
};