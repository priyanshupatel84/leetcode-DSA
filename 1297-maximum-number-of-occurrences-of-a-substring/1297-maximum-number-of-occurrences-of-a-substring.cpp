class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> freq;
        unordered_map<char, int> charCount;

        int unique = 0;
        int maxFreqCount = 0;

        int left = 0;
        for (int right = 0; right < s.size(); ++right) {
            charCount[s[right]]++;
            if (charCount[s[right]] == 1) unique++;

            // Maintain window size = minSize
            if (right - left + 1 > minSize) {
                charCount[s[left]]--;
                if (charCount[s[left]] == 0) unique--;
                left++;
            }

            if (right - left + 1 == minSize && unique <= maxLetters) {
                string sub = s.substr(left, minSize);
                freq[sub]++;
                maxFreqCount = max(maxFreqCount, freq[sub]);
            }
        }

        return maxFreqCount;
    }
};