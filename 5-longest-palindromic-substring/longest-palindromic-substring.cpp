class Solution {
public:
    bool isPalindrome(string &s, int l, int h){
        while(l<h){
            if(s[l]!=s[h])
                return false;
            l++;
            h--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans;
        int len = s.length();
        for(int i=0;i<len;i++){
            for(int j=i;j<len;j++){
                if(isPalindrome(s,i,j)){
                    if(j-i+1 > ans.length()){
                        ans = s.substr(i, (j-i+1));
                        // cout<<ans<<endl;
                    }
                }
            }
        }
        return ans;
    }
};