class Solution {
public:
    int countSubstrings(string s) {
        long long ans = 0;

        string t = "@#";

        for(char c : s){
            t += c;
            t += '#';
        }

        t += '*';
        int n = t.size();
        vector<int> P(n,0);

        int C = 0,R = 0;

        for(int i=1;i<n-1;i++){
            int mirror = 2*C - i;

            if(i < R){
                P[i] = min(R-i,P[mirror]);
            }

            while(t[i+P[i]+1] == t[i-P[i]-1]){
                P[i]++;
            }

            if(i+P[i]>R){
                C=i;
                R=i+P[i];
            }

            ans += (P[i] + 1)/2;
        }

        return (int)ans;
    }
};
