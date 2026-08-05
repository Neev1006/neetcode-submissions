class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int l = 0;
        for(int r=1;r<prices.size();r++){
            if(prices[r] < prices[l]){
                l = r;
            }
            else{
                maxi = max(maxi , prices[r] - prices[l]);
            }
        }
        return maxi;
    }
};
