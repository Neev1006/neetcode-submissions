class Solution {
public:
    string longestPalindrome(string s) {
        string t = "@#";
        for(char c : s){
            t += c;
            t += '#';
        }
        t += '*';
        
        int n = t.size();
        vector<int> P(n,0);

        int start = 0,maxLen = 1;
        int center = 0,R = 0;
        int C = 0;

        for(int i=1;i<n-1;i++){
            int mirror = 2*C - i;

            if(i < R){
                P[i] = min(R-i,P[mirror]);
            }
            
            while(t[i+P[i]+1] == t[i-P[i]-1]){
                P[i]++;
            }

            if(i + P[i] > R){
                C = i + P[i];
                R = i;
            }

            if(P[i] > maxLen){
                maxLen = P[i];
                center = i;
            }
        }

        start = (center - maxLen)/2;
        return s.substr(start,maxLen);
    }
};
