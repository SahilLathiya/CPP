class Solution {
public:

    void solve(string digits, string output, int index, vector<string> &ans, map<int,string> mpp){
        if(index>=digits.length()){
            if(output.length()>0)
                ans.push_back(output);
            return;
        }

        int digit = digits[index]-'0';
        for(int i=0;i<mpp[digit].length();i++){
            output.push_back(mpp[digit][i]);
            solve(digits,output,index+1,ans,mpp);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        map<int,string> mpp;
        mpp[2] = "abc";
        mpp[3] = "def";
        mpp[4] = "ghi";
        mpp[5] = "jkl";
        mpp[6] = "mno";
        mpp[7] = "pqrs";
        mpp[8] = "tuv";
        mpp[9] = "wxyz";
        string output;
        int index = 0;
        solve(digits, output, index, ans, mpp);
        return ans;
    }
};