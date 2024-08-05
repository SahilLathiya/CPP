class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>> ans;
        int n= arr.size();
        sort(arr.begin(), arr.end());
        for(int i=0;i<n;i++){
            if(i>0 && arr[i-1]==arr[i])
                continue;
            int sum = arr[i];
            int j=i+1, k=n-1;
            while(j<k){
                
                if(sum + arr[j]+arr[k] <0){
                    j++;
                }
                else if(sum + arr[j]+arr[k] >0){
                    k--;
                }
                else{
                    vector<int> t(3);
                    t[0] = arr[i];
                    t[1] = arr[j];
                    t[2] = arr[k];
                    ans.push_back(t);
                    do{
                        j++;
                    }while(j<k && arr[j-1]==arr[j]);
                    
                    do{
                        k--;
                    }while(j<k && arr[k+1]==arr[k]);
                        
                }
            }
        }

        return ans;
    }
};