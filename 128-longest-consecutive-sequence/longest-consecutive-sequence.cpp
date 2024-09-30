class Solution {

public:
    int longestConsecutive(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        unordered_set<int> st;
        for(int i=0;i<n;i++)
            st.insert(arr[i]);
        for(auto i:st){
            if(st.find(i-1)!=st.end())
                continue;
            int cnt = 1;
            while(st.find(i+1)!=st.end()){
                cnt++;
                i++;
            }
            ans = max(ans, cnt);
        }
        return ans;
        
        
    }
};