class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for(int i=0;i<n;i++){
            int course = arr[i][0];
            int prereq = arr[i][1];
            adj[prereq].push_back(course);
            inDegree[course]++;
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(!inDegree[i])
                q.push(i);
        }

        int completed_courses = 0;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            
            completed_courses++;
            
            for(int i=0;i<adj[course].size();i++){
                inDegree[adj[course][i]]--;
                if(inDegree[adj[course][i]]==0){
                    q.push(adj[course][i]);
                }
            }
        }
        return completed_courses==numCourses;
    }
};