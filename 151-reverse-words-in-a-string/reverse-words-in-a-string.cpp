#include <iostream>
#include <string>
#include <sstream>

class Solution {
public:
void reverse(string &s, int l, int h){
    while(l<h){
        swap(s[l],s[h]);
        l++;
        h--;
    }
}
std::string removeExtraSpaces(const std::string& input) {
    std::istringstream iss(input);
    std::string result, word;

    while (iss >> word) {
        result += word + " ";
    }

    // Remove trailing space
    if (!result.empty()) {
        result.pop_back();
    }

    return result;
}
    string reverseWords(string s) {
        int n = s.size();
        reverse(s,0,n-1);
        int l = 0,i=0;
        while(i<n){
            if(s[i]==' '){
                reverse(s,l,i-1);
                l = i+1;
            }
            i++;
        }
        reverse(s,l,n-1);
        s = removeExtraSpaces(s);
        
        return s;
    }
};