class Solution {
public:
    bool isPalindrom(string &s, int l, int h){
        while(l<h){
            if(s[l]!=s[h])
                return false;
            l++;
            h--;
        }
        return true;
    }
    void solve(string &str, int ind, int n, vector<string> &t, vector<vector<string>> &ans){
        if(ind==n){
            ans.push_back(t);
            return;
        }
        for(int i=ind;i<n;i++){
            if(isPalindrom(str, ind, i)){
                string s = "";
                for(int j=ind;j<=i;j++)
                    s += str[j];
                t.push_back(s);
                solve(str, i+1, n, t, ans);
                t.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string str) {
        vector<string> t;
        vector<vector<string>> ans;
        solve(str, 0, str.length(), t, ans);
        return ans;
    }
};