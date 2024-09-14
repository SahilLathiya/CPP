typedef pair<pair<int, int>, int> pp;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& arr) {
        int ans = 0;
        int m = arr.size();
        int n = arr[0].size();
        vector<vector<int>> isVisited(m, vector<int>(n, 0));
        queue<pp> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==2){
                    q.push({{i, j}, 0});
                    isVisited[i][j] = 2;
                }
            }
        }

        while(!q.empty()){
            pp a = q.front();
            q.pop();
            int i = a.first.first;
            int j = a.first.second;
            int time = a.second;
            // cout<<i<<' '<<j<<' '<<time<<endl;
            ans = max(ans, time);
            //up
            if(i>0 && isVisited[i-1][j]==0 &&arr[i-1][j]==1){
                isVisited[i-1][j] = 2;
                q.push({{i-1, j}, time+1});
            }
            //down
            if(i<m-1 && isVisited[i+1][j]==0 && arr[i+1][j]==1){
                isVisited[i+1][j] = 2;
                q.push({{i+1, j}, time+1});
            }
            //left
            if(j>0 && isVisited[i][j-1]==0 && arr[i][j-1]==1){
                // cout<<"JI";
                isVisited[i][j-1] = 2;
                q.push({{i, j-1}, time+1});
            }
            //right 
            if(j<n-1 && isVisited[i][j+1]==0 && arr[i][j+1]==1){
                isVisited[i][j+1] = 2;
                q.push({{i, j+1}, time+1});
            }

        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                if(arr[i][j]==1 && isVisited[i][j]!=2){
                    // cout<<isVisited[i][j]<<endl;
                    return -1;
                }
        }
        return ans;
    }
};