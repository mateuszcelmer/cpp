#ifndef common_h__
#define common_h__

#include <string>
#include "utils.h"

// using Point = std::pair<uint32_t, uint32_t>;
using PointF = std::pair<float, float>;
using Size = std::pair<uint32_t, uint32_t>;
using ObjectType = std::string;

template <class T>
auto make_optional_empty()
{
    auto ret = std::make_optional<T>();
    ret.reset();
    return ret;
}

#endif