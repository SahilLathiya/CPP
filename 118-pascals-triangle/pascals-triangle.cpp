class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> prevRow = {1};
        vector<vector<int>> ans;
        ans.push_back(prevRow);
        if(numRows==1){
            return ans;
        }

        for(int i=1;i<numRows;i++){
            vector<int> currRow;
            currRow.push_back(1);
            for(int j=1;j<prevRow.size();j++){
                currRow.push_back(prevRow[j-1] + prevRow[j]);
            }
            currRow.push_back(1);
            ans.push_back(currRow);
            prevRow = currRow;
        }
        return ans;
    }
};