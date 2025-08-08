// g++ -std=c++20 -o solution <file>.cpp && ./solution
#include "common/leetcode-std-includes.h"


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        memset(freq, 0, sizeof(freq_type) * CHAR_COUNT);

        for (int i = 0; i < s.length(); ++i)
        {
            freq[s[i] - CHAR_OFFSET]++;
            freq[t[i] - CHAR_OFFSET]--;
        }
        
        // All zero means both string had equal char frequencies
        for (int f : freq)
        {
            if (f != 0) return false;
        }

        return true;
    }

private:
    typedef uint16_t freq_type;

    static const int CHAR_OFFSET = 'a';
    static const int CHAR_COUNT = 'z' - CHAR_OFFSET + 1;

    freq_type freq[CHAR_COUNT];
};


int main(int argc, char** argv)
{
        std::cout << Solution().isAnagram("abcd", "dacb") << std::endl;
        return 0;
}

