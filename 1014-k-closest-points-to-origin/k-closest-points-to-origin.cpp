typedef pair<double, vector<int>> pov;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pov> maxH;
        int n = points.size();
        for(int i=0;i<n;i++){
            pov x = {sqrt(pow(points[i][0], 2) + pow(points[i][1], 2)), points[i]};
            // cout<<x.first<<endl;
            maxH.push(x);
            if(maxH.size()>k)
                maxH.pop();
        }

        while(!maxH.empty()){
            ans.push_back(maxH.top().second);
            maxH.pop();
        }
        return ans;
    }
};