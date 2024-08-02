class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int len = strs.size();
        int minLen = INT_MAX;
        for(int i=0;i<len;i++){
            minLen = min((int)strs[i].length(), minLen);
        }

        for(int i=0;i<minLen;i++){
            bool flag = true;
            for(int j=1;j<len;j++){
                if(strs[j-1][i]!=strs[j][i]){
                    flag = false;
                    break;
                }
            }
            // cout<<i<<' '<<flag<<endl;
            if(flag){
                ans = strs[0].substr(0,i+1);
            }else{
                break;
            }
        }
        return ans;
    }
};