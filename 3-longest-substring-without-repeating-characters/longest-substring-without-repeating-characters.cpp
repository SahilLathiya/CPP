class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int mpp[256] = {0};
        int l = 0, h = 0;
        while(h<s.size()){
            if(l==h){
                ans = max(ans, 1);
                mpp[s[h]] = 1;
                h++;
            }
            else{
                while(l<h && mpp[s[h]]){
                    mpp[s[l]] = 0;
                    l++;
                }
                mpp[s[h]] = 1;
                ans = max(ans, h-l+1);
                h++;
            }
        }
        return ans;
    }
};