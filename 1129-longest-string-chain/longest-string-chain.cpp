class Solution {
public:
    bool check(string &s1, string &s2){
        if(s1.size() != s2.size()+1)
            return false;

        int i=0, j=0;
        while(i<s1.size()){
            if(j<s2.size() && s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(i==s1.size() && j==s2.size())
            return true;
        return false;
    }
    bool static cmp(string &s1, string &s2){
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        int n = arr.size();
        vector<int> dp(n, 1);
        int ans = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(arr[i], arr[j]) && dp[j]+1 > dp[i])
                    dp[i] = dp[j] + 1;
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};