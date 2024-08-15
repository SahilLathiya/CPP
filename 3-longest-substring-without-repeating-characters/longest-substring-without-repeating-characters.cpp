class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mpp[256] = {0};
        int len = s.length();
        if(len<=1)
            return len;

        int ans = 0;
        int cnt = 0;
        int l = 0;
        for(int i=0;i<len;i++){
            if(mpp[s[i]]){
                mpp[s[l]] = 0;
                l++;
                cnt--;
                i--;
            }
            else{
                mpp[s[i]]++;
                cnt++;
            }
            ans = max(ans, cnt);
        }

        return ans;
    }
};