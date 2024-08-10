class Solution {
public:
    void solve(vector<char>& s, int i, int n){
        if(i>n/2)
            return;

        swap(s[i], s[n-i]);
        solve(s, i+1, n);
    }
    void reverseString(vector<char>& s) {
        solve(s, 0, s.size()-1);
    }
};