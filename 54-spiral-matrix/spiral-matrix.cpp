class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        
        vector<int> ans;
        int s_row = 0;
        int e_col = arr[0].size()-1;
        int e_row = arr.size()-1;
        int s_col = 0;

        while(s_row<=e_row && s_col<=e_col){
            
            for(int i=s_col;i<=e_col;i++){
                ans.push_back(arr[s_row][i]);
            }
            s_row++;

            if(s_row<=e_row && s_col<=e_col){
                for(int i=s_row;i<=e_row;i++){
                    ans.push_back(arr[i][e_col]);
                }
                e_col--;
            }

            if(s_row<=e_row && s_col<=e_col){
                for(int i=e_col;i>=s_col;i--){
                    ans.push_back(arr[e_row][i]);
                }
                e_row--;
            }

            if(s_row<=e_row && s_col<=e_col){
                for(int i=e_row;i>=s_row;i--){
                    ans.push_back(arr[i][s_col]);
                }
                s_col++;
            }

        }

        return ans;
    }
};