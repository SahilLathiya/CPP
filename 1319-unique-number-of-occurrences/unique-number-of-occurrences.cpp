class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        
        vector<bool>a(arr.size());
        // for(auto i:a)
        //     cout<<i;
        // return false;
        for(auto it:mpp){
            if(a[it.second])
                return false;
            a[it.second] = true;
        }
        return true;
    }
};