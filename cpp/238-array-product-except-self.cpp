// g++ -std=c++20 -o solution <file>.cpp && ./solution
#include "common/leetcode-std-includes.h"


// Required: must run in O(n) and cannot use division operation
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Compute prefix & suffix product for each element
        const int count = nums.size();
        
        std::vector<int> prefixes, suffixes;
        prefixes.reserve(count);
        suffixes.reserve(count);

        int prefix_acc = 1, suffix_acc = 1;
        for (int i = 0; i < count; ++i)
        {
            prefixes[i] = prefix_acc;
            prefix_acc *= nums[i];

            const int suffix_ix = (count - i) - 1;
            suffixes[suffix_ix] = suffix_acc;
            suffix_acc *= nums[suffix_ix];
        }

        // Each result element is now the product of prefix & suffix products
        std::vector<int> result;
        result.reserve(count);

        for (int i = 0; i < count; ++i)
        {
            result.push_back(prefixes[i] * suffixes[i]);
        }

        return result;
    }
};


int main(int argc, char** argv)
{
        std::cout << Solution().productExceptSelf(INL({-1,1,0,-3,3})) << std::endl;
        return 0;
}

