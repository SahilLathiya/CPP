class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0, n = s.size();
        // Step 1: Ignore leading whitespaces
        while (i < n && s[i] == ' ') i++;
        
        // Step 2: Determine the sign
        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Read the number and handle invalid cases
        long result = 0; // Use long to handle overflow during the calculation
        while (i < n && std::isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            if (result * sign > INT_MAX) return INT_MAX;
            if (result * sign < INT_MIN) return INT_MIN;
            i++;
        }

        // Step 4: Return the final result within the 32-bit range
        return static_cast<int>(result * sign);
    }
};