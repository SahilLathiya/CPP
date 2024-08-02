class Solution {
public:
    void reverse(string* s, int l, int h){
        while(l<h){
            swap((*s)[l],(*s)[h]);
            h--;
            l++;
        }
    }
    string reverseWords(string s) {
        int l = s.length();
        reverse(&s,0,l-1);
        // return s;

        int first, last;
        for(int i=0;i<l;i++){
            if(s[i]==' ')
                continue;
            first = i;
            while(i<l && s[i]!=' ')
                i++;
            last = i;
            reverse(&s, first, last-1);
        }

        string s2;
        bool flag = false;
        for(int i=0;i<l;i++){
            while(i<l && s[i]==' ')
                i++;
            if(i==l)
                break;
            if(flag && s[i-1]==' ')
                s2.push_back(' ');
            s2.push_back(s[i]);
            flag = true;
        }
        return s2;
    }
};