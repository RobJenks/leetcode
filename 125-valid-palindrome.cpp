// g++ -std=c++20 -o solution <file>.cpp && ./solution
#include "common/leetcode-std-includes.h"

class Solution {
private:
    bool is_upper(char c) const { return (c >= 'A' && c <= 'Z'); }
    bool is_lower(char c) const { return (c >= 'a' && c <= 'z'); }
    bool is_num(char c) const { return (c >= '0' && c <= '9'); }

    std::string sanitize(const std::string& s) const
    {
        std::ostringstream os;
        for (const char c : s)
        {
            if (is_upper(c)) {
                os << static_cast<char>(tolower(c));
            }
            else if (is_lower(c) || is_num(c)) {
                os << c;
            }
        }

        return os.str();
    }

public:
    // Need to strip out any non-alphanumeric chars, convert uppercase to lower, and determine if
    // resulting string is a palindrome.  Inline implementation performing all operations in one 
    // pass through the string to avoid allocs/reduce runtime.  Hits 0ms runtime category and beats
    // 94% of submissions on memory, but obviously less clear
    bool isPalindrome(string s) 
    {
        int left = 0;
        int right = s.length() - 1;
        char cl = 0, cr = 0;

        while (true)
        {
            // Sanitize and find left ptr
            while (left < right)
            {
                if (is_upper(s[left])) {
                    cl = static_cast<char>(tolower(s[left]));
                    break;
                }
                else if (is_lower(s[left]) || is_num(s[left])) {
                    cl = s[left];
                    break;
                }
                left++;
            }

            // Sanitize and find right ptr
            while (left < right)
            {
                if (is_upper(s[right])) {
                    cr = static_cast<char>(tolower(s[right]));
                    break;
                }
                else if (is_lower(s[right]) || is_num(s[right])) {
                    cr = s[right];
                    break;
                }
                right--;
            }

            if (left >= right) return true;
            if (cl != cr) return false;
            left++;
            right--;
        }
    }

    // Alternative simple & clearer impl, reasonable runtime
    bool isPalindrome_Simple(string s) {
        const std::string sanitized = sanitize(s);
        const int length = sanitized.length();
        const int midpoint = length / 2;

        for (int i = 0; i < midpoint; ++i)
        {
            if (sanitized[i] != sanitized[length - i - 1])
            {
                return false;
            }
        }

        return true;
    }
};


int main(int argc, char** argv)
{
        std::cout << Solution().isPalindrome("A man, a plan, a canal: Panama") << std::endl;
        return 0;
}

