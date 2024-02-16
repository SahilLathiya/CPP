class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        vector<int> ans;

        int startRow = 0, endCol = arr[0].size()-1, endRow = arr.size()-1, startCol = 0;

        int cnt = 0;
        int total = (endRow+1)*(endCol+1);

        while(cnt<total){
            //Print Start Row
            for(int i=startCol;cnt<total && i<=endCol;i++){
                ans.push_back(arr[startRow][i]);
                cnt++;
            }
            startRow++;
            //Print End Col
            for(int i=startRow;cnt<total && i<=endRow;i++){
                ans.push_back(arr[i][endCol]);
                cnt++;
            }
            endCol--;

            for(int i=endCol;cnt<total && i>=startCol;i--){
                ans.push_back(arr[endRow][i]);
                cnt++;
            }
            endRow--;

            for(int i=endRow;cnt<total&&i>=startRow;i--){
                ans.push_back(arr[i][startCol]);
                cnt++;
            }
            startCol++;

        }

        return ans;
    }
};