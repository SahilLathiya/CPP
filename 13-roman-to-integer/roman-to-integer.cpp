class Solution {
public:
    int romanToInt(string arr) {
        int ans = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]=='I')
                ans+=1;
            else if(arr[i]=='V')
                ans+=5;
            else if(arr[i]=='X')
                ans+=10;
            else if(arr[i]=='L')
                ans+=50;
            else if(arr[i]=='C')
                ans+=100;
            else if(arr[i]=='D')
                ans+=500;
            else if(arr[i]=='M')
                ans+=1000;

            if(i+1<n){
                if(arr[i]=='I' && (arr[i+1]=='V' || arr[i+1]=='X')){
                    // cout<<ans<<endl;
                    ans -= 1;
                    if(arr[i+1]=='V')
                        ans+=4;
                    else
                        ans+=9;
                    i++;
                    // cout<<"HERE";
                }
                else if(arr[i]=='X' && (arr[i+1]=='L' || arr[i+1]=='C')){
                    ans -= 10;
                    if(arr[i+1]=='L')
                        ans+=40;
                    else
                        ans+=90;
                    i++;
                }
                else if(arr[i]=='C' && (arr[i+1]=='D' || arr[i+1]=='M')){
                    ans -= 100;
                    if(arr[i+1]=='D')
                        ans+=400;
                    else
                        ans+=900;
                    i++;
                }
            }
        }
        return ans;
    }
};