// g++ -std=c++20 -o solution <file>.cpp && ./solution
#include "common/leetcode-std-includes.h"


class Solution {
private:
    typedef size_t string_id;
    static constexpr auto hash_fn = std::hash<std::string>{};

    // Accepts copy of a string since it will be modified in-place
    string_id getStringId(std::string str) const
    {
        std::sort(str.begin(), str.end());
        return hash_fn(str);
    }

    struct Ref
    {
        int index;
        string_id id;
        Ref() : Ref(0, 0U) {}
        Ref(int _index, string_id _id) : index(_index), id(_id) {}
    };
    

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Create ~hash of each string which is equal for any anagram
        const int count = strs.size();
        std::vector<Ref> refs;
        refs.reserve(count);
        for (int i = 0; i < count; ++i)
        {
            refs.emplace_back(i, getStringId(strs[i]));
        }

        // Sort based on anagram-hash to determine output groups
        std::sort(refs.begin(), refs.end(), [](const Ref& a, const Ref& b)
        {
            return a.id < b.id;
        });

        // Generate groups array based on all matching anagram-hashes
        std::vector<std::vector<std::string>> result;
        string_id current_id = -1;
        for (const auto& ref : refs)
        {
            if (ref.id != current_id)
            {
                result.push_back({});
                current_id = ref.id;
            }

            result.back().push_back(strs[ref.index]);
        }

        return result;
    }
};


int main(int argc, char** argv)
{
        std::cout << Solution().groupAnagrams(INL({"eat","tea","tan","ate","nat","bat"})) << std::endl;
        return 0;
}

