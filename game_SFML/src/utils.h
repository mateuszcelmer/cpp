#ifndef utils_h__
#define utils_h__

template<typename T>
T toPositive(T t)
{
    return t > 0 ? t : -t;
}

template<typename T>
T toNegative(T t)
{
    return t < 0 ? t : -t;
}

#endif // utils_h__