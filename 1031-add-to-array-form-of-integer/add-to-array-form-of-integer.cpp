class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int ind = num.size()-1;
        int sum = 0, carry = 0;
        while(ind>=0){
            int last_digit = k%10;
            sum = num[ind] + last_digit + carry;
            carry = sum/10;
            sum = sum % 10;
            num[ind] = sum;
            k/=10;
            ind--;
        }
        
        while(k){
            int last_digit = k%10;
            sum = last_digit + carry;
            carry = sum/10;
            sum = sum % 10;
            k/=10;
            num.insert(num.begin(), sum);
        }
        if(carry){
            num.insert(num.begin(), carry);
        }
        return num;
    }
};