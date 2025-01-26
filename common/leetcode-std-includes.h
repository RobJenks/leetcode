/* Standard includes and definitions from the leetcode harness */

#include <bits/stdc++.h>
using namespace std;



/* Utility functions to make solutions independently-executable */

// Convert rvalue to lvalue for simpler test harness code
template <typename T>
std::vector<T>& INL(std::initializer_list<T> list) 
{
    static std::vector<T> vec;
    vec.assign(list);
    return vec;
}

template <typename T>
std::vector<T>& INL(std::vector<T> && v) 
{
    static std::vector<T> vec;
    vec.assign(v);
    return vec;
}

// Specialization for { const char*, ... } to vec<string>
std::vector<std::string>& INL(std::initializer_list<const char*> list)
{
    static std::vector<std::string> vec;
    vec.clear();
    for (const auto& x : list)
    {
        vec.emplace_back(x);
    }
    return vec;
}

// Output stream for common types
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) 
{
    os << "[ ";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) {
            os << ", ";
        }
    }
    os << " ]";
    return os;
}

