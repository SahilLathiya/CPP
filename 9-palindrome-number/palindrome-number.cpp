class Solution {
public:
    bool isPalindrome(int x) {
        int t = x;
        if(x<0)
			return false;
		int res = 0;
		while (x)
		{   
            if(res<=INT_MAX/10.0)
			    res = res*10 + (x%10);
			x = x /10;
		}
	if(res==t)
		return true;
	return false;
    }
};