class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1.0;
        else if(n>0){
            double t = myPow(x,n/2);
            if(n%2==0)
                return t*t;
            else
                return x*t*t;
        }
        else{
            double t = myPow(x,n/2);
            if(n%2==0)
                return t*t;
            else
                return (1/x)*t*t;
        }
        return -1;
    }
};