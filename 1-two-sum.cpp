// g++ -std=c++20 -o solution <file>.cpp && ./solution
#include "common/leetcode-std-includes.h"

class Solution {

private:
    struct Indexed
    {
        int value;
        int index;
        Indexed() : Indexed(0, 0) {}
        Indexed(int _value, int _index)
        :
        value(_value),
        index(_index)
        {}
    };

public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int count = nums.size();

        // Create sorted value collection with indices embedded in each value
        std::vector<Indexed> data;
        data.reserve(count);
        for (int i = 0; i < count; ++i)
        {
            data.emplace_back(nums[i], i);
        }

        std::sort(data.begin(), data.end(), [](const Indexed& a, const Indexed& b)
        {
            return a.value < b.value;
        });

        // We can now binary search for all matches and don't need to return to the unsorted data
        // to locate the indices
        for (int i = 0; i < count; ++i)
        {
            const int find = target - data[i].value;
            const auto it = std::lower_bound(data.cbegin(), data.cend(), find, [](const Indexed& el, int to_find)
            {
                return el.value < to_find;
            });

            if (it == data.cend()) continue;    // No complementary value, can't be the solution

            if ((*it).value == find && (*it).index != data[i].index)
            {
                return { data[i].index, (*it).index };
            }
        }

        assert(false);
    }
};


int main(int argc, char** argv)
{
        std::cout << Solution().twoSum(INL({1, 4, 61, 12, 3, 21}), 25) << std::endl;
        return 0;
}

