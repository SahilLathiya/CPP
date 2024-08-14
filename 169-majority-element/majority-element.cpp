class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        int ele = arr[0];
        int cnt = 1;
        for(int i=1;i<n;i++){
            if(arr[i]==ele)
                cnt++;
            else{
                cnt--;
                if(cnt==0){
                    cnt = 1;
                    ele = arr[i];
                }
            }
        }

        return ele;
    }
};