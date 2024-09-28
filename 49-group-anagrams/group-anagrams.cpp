class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mpp;
        int n = strs.size();
        for(int i=0;i<n;i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            if(mpp.find(s)==mpp.end()){
                mpp[s] = {};
            }
            mpp[s].push_back(strs[i]);
        }
        for(auto i:mpp)
            ans.push_back(i.second);
        return ans;
    }
};