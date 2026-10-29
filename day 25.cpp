#include <string>
#include <algorithm>

class Solution {
private:
    // Helper function to expand around the center (left and right)
    int expandAroundCenter(const std::string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return the length of the palindrome found
        return right - left - 1;
    }

public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";

        int start = 0;
        int maxLength = 0;

        for (int i = 0; i < s.length(); ++i) {
            // Odd length palindrome (single character center)
            int len1 = expandAroundCenter(s, i, i);
            // Even length palindrome (two characters center)
            int len2 = expandAroundCenter(s, i, i + 1);

            int currentMax = std::max(len1, len2);

            if (currentMax > maxLength) {
                maxLength = currentMax;
                // Calculate the starting index of the longest palindrome
                start = i - (currentMax - 1) / 2;
            }
        }

        return s.substr(start, maxLength);
    }
};
