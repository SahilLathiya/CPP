class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& arr) {
        int n = arr.size();

        vector<vector<int>> adj(numCourses);
        vector<int> in_degree(numCourses, 0);
        for(int i=0;i<n;i++){
            int course = arr[i][0];
            int prereq = arr[i][1];
            adj[prereq].push_back(course);
            in_degree[course]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(in_degree[i]==0){
                q.push(i);
            }
        }

        int completed_course = 0;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            completed_course++;
            for(int i=0;i<adj[course].size();i++){
                in_degree[adj[course][i]]--;
                if(in_degree[adj[course][i]]==0){
                    q.push(adj[course][i]);
                }
            }
        }

        return completed_course==numCourses;
    }
};