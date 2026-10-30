class Solution {
public:
    vector<int> countBits(int n) {
       vector<int> ans(n+1);
       if(n == 0)return {0};

       for(int i=0;i<=n;i++){
        int ones = 0;
        for(int j=0;j<32;j++){
            if(i & (1 << j))ones++;
        }
        ans[i] = ones;
       }

       return ans;
    }
};
