class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        int cnt1=0, cnt2=0, ele1=INT_MIN, ele2=INT_MAX;
        for(int i=0;i<n;i++){
            if(cnt1==0 && arr[i]!=ele2){
                cnt1 = 1;
                ele1 = arr[i];
            }
            else if(cnt2==0 && arr[i]!=ele1){
                cnt2=1;
                ele2 = arr[i];
            }
            else if(arr[i]==ele1)
                cnt1++;
            else if(arr[i]==ele2)
                cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }

        int x = 0;
        for(int i=0;i<n;i++)
            if(arr[i]==ele1)
                x++;

        if(x>n/3)
            ans.push_back(ele1);
        
        x = 0;
        for(int i=0;i<n;i++)
            if(arr[i]==ele2)
                x++;
        if(x>n/3)
            ans.push_back(ele2);

        return ans;
    }
};