class Solution {
public:
    // vector<vector<int>> fourSum(vector<int>& arr, int tgt) {
    //     int n = arr.size();
    //     set<vector<int>> ans;

    //     unordered_map<long long int,vector<int>> mpp;

    //     for(int i=0;i<n;i++){
    //         mpp[arr[i]].push_back(i);
    //     }

    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             for(int k=j+1;k<n;k++){
    //                     long long int x = (long long int)tgt - ((long long int)arr[i]+arr[j]+arr[k]);
    //                     if(mpp.find(x)!=mpp.end()){
    //                         bool flag = false;
    //                         int len = mpp[x].size();
    //                         int a=0;
    //                         for(;a<len;a++){
    //                             if(mpp[x][a]!=i &&
    //                                 mpp[x][a]!=j &&
    //                                 mpp[x][a]!=k ){
    //                                     flag = true;
    //                                     break;
    //                             }
    //                         }
    //                         if(flag){
    //                             vector<int> t(4);
    //                             t[0] = arr[i];
    //                             t[1] = arr[j];
    //                             t[2] = arr[k];
    //                             t[3] = arr[mpp[x][a]];
    //                             sort(t.begin(),t.end());
    //                             ans.insert(t);
    //                         }
    //                     }
                    
    //             }
    //         }
    //     }

    //     vector<vector<int>> vc;
    //     // Iterate through each set<int> in the set<set<int>>
    //     for (auto innerSet : ans){
    //         // Convert each set<int> to a vector<int>
    //         vector<int> innerVector(innerSet.begin(), innerSet.end());
    //         // Add the vector<int> to the vector<vector<int>>
    //         vc.push_back(innerVector);
    //     }

    //     return vc;
    // }
    vector<vector<int>> fourSum(vector<int>& arr, int tgt) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i>0 && arr[i-1]==arr[i])
                continue;

            for(int j=i+1;j<n;j++){
                if(j>i+1 && arr[j-1]==arr[j])
                    continue;
                    
                int k=j+1, l=n-1;
                while(k<l){
                    if((long long int)tgt == (long long int)arr[i]+arr[j]+arr[k]+arr[l])
                    {
                        ans.push_back({arr[i],arr[j],arr[k],arr[l]});
                        int z = arr[k];
                        int c = arr[l];
                        while(k<l && arr[k]==z)
                            k++;
                        while(k<l && arr[l]==c)
                            l--;
                            
                    }
                    else if((long long int)tgt > (long long int)arr[i]+arr[j]+arr[k]+arr[l])
                        k++;
                    else
                        l--;
                }
            }

        }
        return ans;
    }
};