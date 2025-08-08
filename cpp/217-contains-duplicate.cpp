// g++ -std=c++20 -o solution <file>.cpp && ./solution
#include "common/leetcode-std-includes.h"


class Solution {
public:
    bool containsDuplicate(vector<int> nums) {
        std::unordered_set<int> seen;
        for (int num : nums)
        {
            if (seen.contains (num)) return true;
            seen.insert(num);
        }

        return false;
    }
};


int main(int argc, char** argv)
{
        std::cout << Solution().containsDuplicate({ 1, 2, 4, 2, 4 }) << std::endl;
        return 0;
}

