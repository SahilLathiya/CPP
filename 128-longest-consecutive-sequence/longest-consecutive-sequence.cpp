class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        map<int, bool> mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]] = true;
        }

        int ans = 0;
        int cnt = 0;
        int prev;
        bool flag = true;
        for(auto i : mpp){
            cout<<i.first<<' ';
            if(flag){
                prev = i.first;
                cnt = 1;
                flag = false;
            }
            if(i.first==prev+1){
                cnt++;
            }
            else{
                cnt = 1;
            }
            prev = i.first;
            ans = max(ans,cnt);
        }
        return ans;
    }
};