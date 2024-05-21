class Solution {
public:
static bool cmp(pair<int, int>& a,
        pair<int, int>& b)
{
    return a.second > b.second;
}
    vector<int> topKFrequent(vector<int>& arr, int k) {
        map<int,int> mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        vector<pair<int, int> > Ans;
        for(auto it:mpp){
            Ans.push_back(it);
        }
        sort(Ans.begin(),Ans.end(),cmp);
        
        vector<int> ans;

        int i = 0;
        for(auto it:Ans){
            if(i>=k)
                break;
            i++;
            ans.push_back(it.first);
        }
        return ans;
    }
};