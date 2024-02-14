class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnt(26,0);
        int n = s1.length();
        int m = s2.length();
        for (int i=0;i<n;i++)
            cnt[s1[i]-'a']++;   
        
        int windowSize = n;
        for(int i = 0; i < m ; i++){
            vector<int> t(cnt);
            if(i+windowSize<=m){
                for(int j = i; j<i+windowSize;j++)
                    t[s2[j]-'a']--;
            }
            bool flag = true;
            for(int k = 0 ; k <26;k++){
                if(t[k]!=0){
                    flag = false;
                    break;
                }
            }
            if(flag)
                return true;
        }
        return false;
    }
};