class Solution {
public:
    int f(vector<int>& nums , int start , int end){
        int prev = 0;
       int prev2 = nums[start];
       for(int i=start+1;i<end;i++){
            int incl = nums[i] + prev;
            int excl = prev2;
            int curr = max(incl,excl);
            prev = prev2;
            prev2 = curr;
        }
        return prev2;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() == 1)return nums[0];
        if(nums.size() == 2)return max(nums[0],nums[1]);
       return max(f(nums,0,n-1),f(nums,1,n));
    }
};
