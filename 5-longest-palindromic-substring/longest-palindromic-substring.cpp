class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<=1)
            return s;
        string ans = "";
        int max_len = 0;
        int n = s.size();
        for(int i=1;i<n;i++){
            int low = i;
            int high = i;

            while(s[low]==s[high]){
                low--;
                high++;

                if(low==-1 || high==n)
                    break;
            }
                int prev_ans_len = max_len;
                max_len = max(max_len, (high - (low+1)));
                if(max_len>prev_ans_len){
                    ans = s.substr(low+1, max_len);
                }


            // For Even Length String
            low = i-1;
            high = i;

            while(s[low]==s[high]){
                low--;
                high++;

                if(low==-1 || high==n)
                    break;
            }
        
                prev_ans_len = max_len;
                max_len = max(max_len, (high - (low+1)));
                if(max_len>prev_ans_len){
                    ans = s.substr(low+1, max_len);
                }
        }
        return ans;
    }
};