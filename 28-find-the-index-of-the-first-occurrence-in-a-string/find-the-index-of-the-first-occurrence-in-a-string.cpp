class Solution {
public:
    int strStr(string str1, string str2) {
        int l1 = str1.length();
        int l2 = str2.length();
        bool flag = true;
        for(int i=0; i<=(l1-l2); i++){
            flag = true;
            for(int j=0;j<l2;j++)
                if(str1[i+j]!=str2[j]){
                    flag = false;
                    break;
                }
            if(flag)
                return i;
        }
        return -1;
    }
};