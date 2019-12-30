#ifndef map_h__
#define map_h__

#include <cstdint>
#include <vector>
#include <unordered_map>
#include <memory>
#include "common.h"

using division_t = uint16_t;
using parts_t = uint32_t;

template <class T>
class Map
{
    division_t m_numberOfDivisions;
    std::unordered_multimap<division_t, T*> m_mapByPart;
    using iterator_t = decltype(m_mapByPart.cbegin());
    std::unordered_map<T *, iterator_t> m_mapByPtr;
    std::pair<uint32_t, uint32_t> m_size;
    auto begin = m_mapByPart.cbegin();

public:
    Map(std::pair<uint32_t, uint32_t> size, division_t numberOfDivisions) : m_size{size}, m_numberOfDivisions{numberOfDivisions} {};
    bool hasObject(T*);
    parts_t getNumberOfParts() { return m_numberOfDivisions * m_numberOfDivisions; };
    void insert(T*);
    void remove(T*);
    void updatePosition(T*, Point);
    auto getObjectsOfPart(const parts_t part)
    {
        return m_mapByPart.equal_range(part);
    }
    division_t calcPart(T* ptr)
    {
        return ptr->getPosition();
    }
};

template <class T>
bool Map<T>::hasObject(T* ptr)
{
    return m_mapByPtr.find(ptr) != m_mapByPtr.end();
}

template <class T>
void Map<T>::insert(T* ptr)
{
    static_assert(m_mapByPtr.find(ptr) != m_mapByPtr.end());
    m_mapByPart.insert({calcPart(ptr), ptr});
    auto distance = std::distance(m_mapByPart.begin() - iter);
    m_mapByPtr[ptr] = distance;
}

#endif