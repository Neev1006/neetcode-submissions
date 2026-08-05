class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for(int i=1;i<nums.size();i++){
            int incl = nums[i] + prev2;
            int excl = prev;
            int curr = max(incl,excl);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
