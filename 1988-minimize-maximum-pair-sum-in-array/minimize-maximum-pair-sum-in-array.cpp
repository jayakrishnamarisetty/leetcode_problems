class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //int n=nums.size();
        int rug=0;
        for(int i=0;i<nums.size();i++)
        {
            rug=max(rug,nums[i]+nums[nums.size()-1-i]);
        }
        return rug;

    }
};