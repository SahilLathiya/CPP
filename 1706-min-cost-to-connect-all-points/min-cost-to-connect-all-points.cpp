class Solution {
public:
    int manDist(vector<int> &a, vector<int> &b){
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> inMST(n, false);
        vector<int> minDist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        minDist[0] = 0;
        pq.push({0, 0});    // Dis, point
        int mstCost = 0;
        int pointsInMST = 0;

        while(pointsInMST < n){
            pair<int, int> p = pq.top();
            pq.pop();

            int dist = p.first;
            int u = p.second;

            if(inMST[u])
                continue;
            
            mstCost += dist;
            inMST[u] = true;
            pointsInMST++;

            for(int v=0;v<n;v++){
                if(!inMST[v]){
                    int distt = manDist(points[u], points[v]);
                    if(distt<minDist[v]){
                        minDist[v] = distt;
                        pq.push({distt, v});
                    }
                }
            }

        }

        return mstCost;
    }
};