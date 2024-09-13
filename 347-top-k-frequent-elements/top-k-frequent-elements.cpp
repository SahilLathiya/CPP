class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& arr, int k) {
        map<int,int> mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> > minH;
        for(auto it:mpp){   
            minH.push({it.second, it.first});
            if(minH.size()>k)
                minH.pop();
        }
        vector<int> ans;
        while(!minH.empty()){
            ans.push_back(minH.top().second);
            minH.pop();
        }
        return ans;
    }
};