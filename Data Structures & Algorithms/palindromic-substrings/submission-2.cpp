class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        long long ans = 0;

        for(int i=0;i<n;i++){
            int left=i,right=i;
            while(left>=0 && right<n){
                if(s[left] == s[right]){
                    ans++;
                }
                else{
                    break;
                }
                left--;
                right++;
            }
        }

        for(int i=0;i<n;i++){
            int left=i,right=i+1;
            while(left>=0 && right<n){
                if(s[left] == s[right]){
                    ans++;
                }
                else{
                    break;
                }
                left--;
                right++;
            }
        }

        return (int)ans;
    }
};
