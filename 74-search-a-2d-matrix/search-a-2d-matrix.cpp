class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int lowRow = 0, highRow = arr.size()-1;
        
        while(lowRow<=highRow){
            int midRow = (highRow - lowRow)/2 + lowRow;
            if(arr[midRow][0]==target)
                return true;
            else if(arr[midRow][0]>target){
                highRow = midRow - 1;
            }
            else{
                lowRow =  midRow + 1;
            }
        }
        // cout<<arr[lowRow][0]<<" "<<arr[highRow][0];
        if(highRow<0)
            return false;
            
        int lowCol = 0, highCol = arr[0].size()-1;
        while(lowCol<=highCol){
            int midCol = (highCol - lowCol)/2 + lowCol;
            // cout<<arr[lowRow][midCol]<<' ';
            if(arr[highRow][midCol]==target)
                return true;
            else if(arr[highRow][midCol]>target)
                highCol = midCol - 1;
            else
                lowCol =  midCol + 1;
        }
        
        return false;
    }
};