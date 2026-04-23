class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int rug = 0;
        
        for(int i = n-1; i >= 0; i--){
            if(colors[i] != colors[0]){
                rug = max(rug, i);
                break;
            }
        }

        for(int i = 0; i < n; i++){
            if(colors[i] != colors[n-1]){
                rug = max(rug, n-1-i);
                break;
            }
        }

        return rug;
    }
};