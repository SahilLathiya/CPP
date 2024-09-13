class Solution {
public:
    
    // Comparator function for custom sorting
    bool customCompare(int a, int b, unordered_map<int, int>& freq) {
        // Compare by frequency first
        if (freq[a] != freq[b]) {
            return freq[a] < freq[b]; // Lower frequency first
        }
        // If frequencies are the same, sort by value in decreasing order
        return a > b; // Higher value first
    }

    vector<int> frequencySort(vector<int>& arr) {
        // Step 1: Count the frequency of each number
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }

        // Step 2: Sort using custom comparator
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            return customCompare(a, b, freq);
        });

        return arr;
    }
};