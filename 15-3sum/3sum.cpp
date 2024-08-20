class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        int x = 0;
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        for(int i=0;i<n;i++){
            if(i>0 && arr[i-1]==arr[i])
                continue;
            int j = i+1, k = n-1;
            while(j<k){
                if(j>i+1 && arr[j-1]==arr[j]){
                    j++;
                    continue;
                }
                if(k<n-1 && arr[k]==arr[k+1]){
                    k--;
                    continue;
                }

                int sum = arr[i]+arr[j]+arr[k];
                // cout<<arr[i]<<' '<<arr[j]<<' '<<arr[k]<<' '<<sum<<endl;
                if(sum==x){
                    vector<int> t(3);
                    t[0] = arr[i];
                    t[1] = arr[j];
                    t[2] = arr[k];
                    ans.push_back(t);
                    j++;
                    k--;
                }
                else if(sum<x){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return ans;
    }
};