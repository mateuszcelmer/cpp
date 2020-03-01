#ifndef map_h__
#define map_h__

#include <cstdint>
#include <vector>
#include <unordered_map>
#include <memory>
#include "common.h"
#include <optional>
#include <cassert>
#include <iostream>
#include <variant>
#include <cmath>

using Int = uint32_t;
using mapSize_t = std::pair<Int, Int>;
template <class T, class K>
class Map
{
public:
    using ptrT_t = std::shared_ptr<T>;
    using ptrK_t = std::shared_ptr<K>;
    std::unordered_multimap<Int, ptrT_t> m_mapBouncers;
    std::unordered_multimap<Int, ptrK_t> m_mapBounceables;
    using iteratorT_t = decltype(m_mapBouncers.begin());
    using iteratorK_t = decltype(m_mapBounceables.begin());
    mapSize_t m_size;
    Int m_numberOfParts;
    Int m_numberOfDivisions;
    template <class L>
    bool hasEnteredNewPart(L &ptr)
    {
        return calcPart(ptr->getPosition()) != calcPart(ptr->getPrevPosition());
    }

public:
    Map(mapSize_t size = mapSize_t{1000, 1000}, Int numberOfParts = 4) : m_size{size}
    {
        m_numberOfDivisions = sqrt((float)numberOfParts);
        m_numberOfParts = m_numberOfDivisions * m_numberOfDivisions;
    };
    Int getNumberOfParts() { return m_numberOfParts; };

    template <class P>
    bool hasObject(P ptr) { return findElemByPtr(ptr).has_value(); }
    template <class P>
    void insert(P ptr)
    {
        if (hasObject(ptr))
            return;
        getMap<P>().insert({calcPart(ptr), ptr});
    }
    template <class P>
    void remove(P ptr)
    {
        auto it = findElemByPtr(ptr);
        if (!it.has_value())
            return;
        getMap<P>().erase(it.value());
    }
    template <class P>
    void updateElement(P ptr)
    {
        auto opt_it = findElemByPtr(ptr);
        if (!opt_it.has_value())
            return;
        getMap<P>().erase(opt_it.value());
        getMap<P>().insert({calcPart(ptr), ptr});
    }
    template <class P>
    void updateElementIfNeeded(P ptr)
    {
        if (hasEnteredNewPart(ptr))
            updateElement(ptr);
    }
    void printAll(std::ostream &stream = std::cout)
    {
        for (auto &[key, val] : m_mapBouncers)
            stream << "{" << key << ", " << val << "}" << std::endl;
        for (auto &[key, val] : m_mapBounceables)
            stream << "{" << key << ", " << val << "}" << std::endl;
    }
    template <class P>
    auto getObjectsOfPart(const Int part)
    {
        return getMap<P>().equal_range(part);
    }
    template <class P>
    auto getObjectsOfSamePart(P ptr)
    {
        return getMap<P>().equal_range(calcPart(ptr));
    }
    Int calcPart(ptrT_t ptr);
    Int calcPart(ptrK_t ptr);
    Int calcPart(PointF position);
    template <class P>
    auto findElemByPtr(P ptr)
    {
        auto [begin, end] = getObjectsOfSamePart(ptr);
        for (auto it = begin; it != end; ++it)
            if (auto &currentPtr = it->second; currentPtr == ptr)
                return std::make_optional(it);
        return make_optional_empty<iteratorT_t>();
    }
    template <class P>
    void handleElementMove(P ptr)
    {
        updateElementIfNeeded(ptr);
        // handleCollisionIfHappened(ptr);
    }
    template <class P, class = class std::enable_if<std::is_same_v<P, ptrT_t>, P>::type>
    std::unordered_multimap<Int, ptrT_t>& getMap()
    {
        return m_mapBouncers;
    } template <class P, class = class std::enable_if<std::is_same_v<P, ptrK_t>, P>::type>
    std::unordered_multimap<Int, ptrK_t>& getMap()
    {
        return m_mapBounceables;
    }
};

template <class T, class K>
Int Map<T, K>::calcPart(ptrT_t ptr)
{
    return calcPart(ptr->getPosition());
}

template <class T, class K>
Int Map<T, K>::calcPart(ptrK_t ptr)
{
    return calcPart(ptr->getPosition());
}

template <class T, class K>
Int Map<T, K>::calcPart(PointF position)
{
    auto const [x, y] = position;
    auto const limitX = m_size.first / m_numberOfDivisions;
    auto const limitY = m_size.second / m_numberOfDivisions;
    return (Int)(x / limitX) + (Int)(y / limitY) * m_numberOfDivisions;
}

#endif