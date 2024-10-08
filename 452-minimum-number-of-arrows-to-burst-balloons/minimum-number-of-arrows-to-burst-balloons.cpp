class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end(), cmp);
        int num_arrows = 1;
        int arrow_pos = arr[0][1];
        for(int i=1;i<n;i++){
            if(arr[i][0]>arrow_pos){
                num_arrows++;
                arrow_pos = arr[i][1];
            }
        }
        return num_arrows;
    }
};