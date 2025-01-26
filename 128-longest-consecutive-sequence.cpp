// g++ -std=c++20 -o solution <file>.cpp && ./solution
#include "common/leetcode-std-includes.h"


// Required: Must run in O(n), no sort operations allowed
class Solution {
private:
    typedef std::pair<int, int> Seq;

public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        std::vector<Seq> seq;
        std::unordered_map<int, int> seq_map;

        for (int num : nums)
        {
            const auto seq_start_after = seq_map.find(num + 1);
            const auto seq_end_before = seq_map.find(num - 1);

            if (seq_start_after != seq_map.end())
            {
                if (seq_end_before != seq_map.end())
                {
                    /* This number joins two sequences together, so union them */
                    const int seq_before = seq_end_before->second;
                    const int seq_after = seq_start_after->second;

                    // Turn the 'before' sequence into the union, and discard the 'after' sequence
                    const int new_end = seq[seq_after].second;
                    seq[seq_before].second = new_end;
                    for (int i = num; i <= new_end; ++i)
                    {
                        seq_map[i] = seq_before;
                    }
                }
                else
                {
                    /* This number is just before the start of an existing range, so expand the range */
                    const int ix = seq_start_after->second;
                    seq[ix].first = num;
                    seq_map[num] = ix;
                }
            }
            else
            {
                if (seq_end_before != seq_map.end())
                {
                    /* This number is just after the end of an existing range, so expand the range */
                    const int ix = seq_end_before->second;
                    seq[ix].second = num;
                    seq_map[num] = ix;
                }
                else
                {
                    /* This number is not adjacent to any existing range.  Insert a new single-value range,
                       as long as it isn't already part of a range */
                    if (seq_map.contains(num)) continue;

                    seq_map[num] = seq.size();
                    seq.emplace_back(num, num);
                }
            }
        }

        // Return the length of the longest sequence
        int max_length = 0;
        for (const auto& sequence : seq)
        {
            const int length = sequence.second - sequence.first;
            if (length > max_length)
            {
                max_length = length;
            }
        }

        return max_length + 1;
    }
};


int main(int argc, char** argv)
{
        std::cout << Solution().longestConsecutive(INL({100,4,200,1,3,2})) << std::endl;
        return 0;
}

