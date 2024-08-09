class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& arr1, vector<int>& arr2) {
        stack<int> st;
        int n = arr1.size();
        int m = arr2.size();
        vector<int> ans(m);
        for(int i=m-1;i>=0;i--){
            if(st.size()==0 || st.top()>arr2[i]){
                if(st.size()==0)
                    ans[i] = -1;
                else
                    ans[i] = st.top();
                st.push(arr2[i]);
            }
            else {
                while(st.size()>0 && st.top()<arr2[i])
                    st.pop();
                if(st.size()==0)
                    ans[i] = -1;
                else
                    ans[i] = st.top();
                st.push(arr2[i]);
            }
        }
        vector<int> ans2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr1[i]==arr2[j]){
                    ans2.push_back(ans[j]);
                    break;
                }
            }
        }
        return ans2;
    }
};