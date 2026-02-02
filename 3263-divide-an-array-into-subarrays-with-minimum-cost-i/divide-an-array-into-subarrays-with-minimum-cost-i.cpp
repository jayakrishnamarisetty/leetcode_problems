class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int rug = nums[0];
        sort(nums.begin() + 1, nums.end());
        int sum = rug + nums[1] + nums[2];
        
        return sum;
    }
};