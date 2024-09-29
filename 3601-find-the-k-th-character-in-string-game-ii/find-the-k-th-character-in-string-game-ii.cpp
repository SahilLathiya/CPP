class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int n = operations.size();
        vector<long long> lengths(n + 1);
        lengths[0] = 1; // Initial length of "a"

        // Compute lengths after each operation, cap at k to prevent overflows
        for (int i = 0; i < n; ++i) {
            lengths[i + 1] = min(lengths[i] * 2, k);
        }

        // Recursive function to get the character at position pos after op_index operations
        function<char(long long, int)> getChar = [&](long long pos, int op_index) -> char {
            if (op_index == -1) {
                return 'a';
            }
            int op = operations[op_index];
            long long length_before = lengths[op_index];
            if (op == 0) {
                if (pos <= length_before) {
                    return getChar(pos, op_index - 1);
                } else {
                    return getChar(pos - length_before, op_index - 1);
                }
            } else if (op == 1) {
                if (pos <= length_before) {
                    return getChar(pos, op_index - 1);
                } else {
                    char c = getChar(pos - length_before, op_index - 1);
                    // Return the next character
                    return c == 'z' ? 'a' : c + 1;
                }
            }
            return 'a'; // Default case, should not reach here
        };

        return getChar(k, n - 1);
    }
};
