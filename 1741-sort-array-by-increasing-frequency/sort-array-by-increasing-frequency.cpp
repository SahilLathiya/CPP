typedef pair<int, int> p;
class Solution {
public:
    vector<int> frequencySort(vector<int>& arr) {
        unordered_map<int, int> mpp;
        int n = arr.size();
        for(int i=0;i<n;i++)
            mpp[arr[i]]++;
        
        priority_queue<p, vector<p> , greater<p>> minH;
        for(auto it:mpp){
            minH.push({it.second, -it.first});
        }

        vector<int> ans;
        while(!minH.empty()){
            p pi = minH.top();
            minH.pop();
            for(int i=0;i<pi.first;i++)
                ans.push_back(-pi.second);
        }
        
        return ans;
    }
};