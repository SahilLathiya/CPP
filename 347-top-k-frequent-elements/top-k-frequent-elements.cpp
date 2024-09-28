typedef pair<int, int> p;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int, int> mpp;
        priority_queue<p, vector<p>, greater<p>> minH;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto i:mpp){
            minH.push({i.second, i.first});
            if(minH.size()>k)
                minH.pop();
        }
        vector<int> ans;
        while(!minH.empty()){
            p x = minH.top();
            minH.pop();
            ans.push_back(x.second);
        }
        return ans;
    }
};