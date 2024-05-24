class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> prevLevel;
        prevLevel.push_back(1);
        if(numRows==1){
            ans.push_back(prevLevel);
            return ans;
        }
        else if(numRows==2){
            ans.push_back(prevLevel);
            ans.push_back({1,1});
            return ans;
        }
        ans.push_back(prevLevel);
        prevLevel.push_back(1);
        ans.push_back(prevLevel);
        for(int i=3;i<=numRows;i++){
            vector<int> currLevel;
            currLevel.push_back(1);
            for(int j=0;j<prevLevel.size()-1;j++){
                currLevel.push_back(prevLevel[j]+prevLevel[j+1]);
            }
            currLevel.push_back(1);
            ans.push_back(currLevel);
            prevLevel = currLevel;
        }
        return ans;
    }
};