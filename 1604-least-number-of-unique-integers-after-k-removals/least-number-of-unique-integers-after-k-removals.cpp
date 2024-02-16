class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mpp;
        int n = arr.size();
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        vector<int> t;
        for(auto it:mpp){
            t.push_back(it.second);
        }
        sort(t.begin(),t.end());
        int cnt = 0;
        for(auto i:t){
            cout<<i<<' ';
            if(k>=i){
                k-=i;
                cnt++;
            }
        }
        return t.size()-cnt;
    }
};