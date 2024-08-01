class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        int majEle = arr[0];
        int majCnt = 1;
        for(int i=1;i<n;i++){
            if(arr[i]==majEle){
                majCnt++;
            }else{
                majCnt--;
                if(majCnt<=0){
                    majEle = arr[i];
                    majCnt=1;
                }
            }
        }
        return majEle;
    }
};