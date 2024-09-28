class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        int arr[256] = {0};
        int n = s.size();
        for(int i=0;i<n;i++){
            arr[s[i]]++;
            arr[t[i]]--;
        }

        for(int i=0;i<256;i++)
            if(arr[i])
                return false;
        return true;
    }
};