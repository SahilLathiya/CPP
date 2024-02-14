class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int ansInd = 0;
        int n = chars.size();

        while(i<n){
            int j = i + 1;
            while(j<n && chars[i]==chars[j])
                j++;
            
            chars[ansInd++] = chars[i];
            int cnt = j - i;
            if(cnt>1){
                string s = to_string(cnt);
                for(auto c:s){
                    chars[ansInd++] = c;
                }
            }
            i=j;
        }
        return ansInd;
    }
};