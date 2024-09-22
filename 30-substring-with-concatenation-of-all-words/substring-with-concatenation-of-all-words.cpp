#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLength = words[0].length();
        int totalLength = wordLength * words.size();
        if (s.length() < totalLength) return result;

        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            wordCount[word]++;
        }

        for (int i = 0; i < wordLength; ++i) {
            unordered_map<string, int> seenWords;
            int left = i, count = 0;
            for (int j = i; j <= s.length() - wordLength; j += wordLength) {
                string word = s.substr(j, wordLength);
                if (wordCount.find(word) != wordCount.end()) {
                    seenWords[word]++;
                    count++;
                    while (seenWords[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLength);
                        seenWords[leftWord]--;
                        count--;
                        left += wordLength;
                    }
                    if (count == words.size()) {
                        result.push_back(left);
                    }
                } else {
                    seenWords.clear();
                    count = 0;
                    left = j + wordLength;
                }
            }
        }

        return result;
    }
};