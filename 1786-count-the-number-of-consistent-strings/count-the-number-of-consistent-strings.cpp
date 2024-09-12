class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        bool all[256] = {false};
        for(int i=0;i<allowed.size();i++)
            all[allowed[i]] = true;
        for(int i=0;i<words.size();i++){
            int j=0;
            for(;j<words[i].size();j++){
                if(!all[words[i][j]]){
                    break;
                }
            }
            ans += (j==words[i].size());
        }
        return ans;
    }
};