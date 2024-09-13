typedef pair<int, int> p;
class Solution {
public:
    vector<int> frequencySort(vector<int>& arr) {
        unordered_map<int, int> mpp;
        int n = arr.size();
        for(int i=0;i<n;i++)
            mpp[arr[i]]++;
        
        priority_queue<p> maxH;
        for(auto it:mpp){
            maxH.push({it.second, -it.first});
        }

        vector<int> ans;
        while(!maxH.empty()){
            p pi = maxH.top();
            maxH.pop();
            for(int i=0;i<pi.first;i++)
                ans.push_back(-pi.second);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};