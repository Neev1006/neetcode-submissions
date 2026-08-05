class Solution {
public:
    int f(int i , int bought , vector<int>& prices , vector<vector<int>> &dp){
        if(i == prices.size())return 0;
        if(dp[i][bought]!=-1)return dp[i][bought];
        int res = f(i+1,bought,prices,dp);
        if(bought == 1){
            res = max(res , prices[i] + f(i+1,0,prices,dp));
        }
        else{
            res = max(res,-prices[i] + f(i+1,1,prices,dp));
        }
        return dp[i][bought] = res;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,0,prices,dp);
    }
};