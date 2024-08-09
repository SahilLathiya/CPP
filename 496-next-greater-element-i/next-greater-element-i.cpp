class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& arr1, vector<int>& arr2) {
        stack<int> st;
        unordered_map<int,int> mpp;
        int n = arr1.size();
        int m = arr2.size();

        for(int i=m-1;i>=0;i--){
            if(st.size()==0 || st.top()>arr2[i]){
                if(st.size()==0)
                    mpp[arr2[i]] = -1;
                else
                    mpp[arr2[i]] = st.top();
                st.push(arr2[i]);
            }
            else {
                while(st.size()>0 && st.top()<arr2[i])
                    st.pop();
                if(st.size()==0)
                    mpp[arr2[i]] = -1;
                else
                    mpp[arr2[i]] = st.top();
                st.push(arr2[i]);
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(mpp[arr1[i]]);
        }
        return ans;
    }
};