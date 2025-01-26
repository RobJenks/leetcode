// g++ -std=c++20 -o solution <file>.cpp && ./solution
#include "common/leetcode-std-includes.h"


class Solution {
private:
    struct NumFreq
    {
        int16_t num;
        int16_t freq;
        NumFreq() {}
        NumFreq(int16_t _num, int16_t _freq) : num(_num), freq(_freq) {}
    };

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {    
        // Freq per potential input number
        std::unordered_map<int, int> data;
        for (int num : nums)
        {
            if (auto it = data.find(num); it != data.end())
            {
                it->second++;
            }
            else
            {
                data[num] = 1;
            }
        }

        // Determine top k
        std::vector<NumFreq> freq;
        freq.reserve(data.size());
        for (const auto& it : data)
        {
            freq.emplace_back(it.first, it.second);
        }

        std::sort(freq.begin(), freq.end(), [](const NumFreq& a, const NumFreq& b)
        {
            return a.freq > b.freq;
        });

        std::vector<int> result;
        result.reserve(k);
        for (int i = 0; i < k; ++i)
        {
            result.push_back(freq[i].num);
        }

        return result;
    }
};


int main(int argc, char** argv)
{
        std::cout << Solution().topKFrequent(INL({1,1,1,2,2,3}), 2) << std::endl;
        return 0;
}

