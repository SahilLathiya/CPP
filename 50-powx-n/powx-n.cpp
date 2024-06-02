class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1;
        if(n>0){
            double t = myPow(x,n/2);
            if(n%2)
                return x*t*t;
            return t*t;
        }
            
        double t = myPow(x,n/2);
        if(n%2)
            return (1/x)*t*t;
        return t*t;
    }
};