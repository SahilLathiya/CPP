class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end(), greater<int>());
        sort(g.begin(), g.end(), greater<int>());

        int ans = 0;
        int n = g.size(), m = s.size();
        int i = 0, j = 0;
        while(i<n && j<m){
            if(g[i]<=s[j]){
                ans++;
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};