#include "../object.h"

bool isCollision(Teritory &t1, Teritory &t2)
{
    // TODO return wektor odbicia

    if ((t1.pointBegin.first <= t2.pointBegin.first && t1.pointBegin.second <= t2.pointBegin.second && t1.pointEnd.first >= t2.pointBegin.first && t1.pointEnd.second >= t2.pointBegin.second) ||
        (t1.pointBegin.first <= t2.pointEnd.first && t1.pointBegin.second <= t2.pointEnd.second && t1.pointEnd.first >= t2.pointEnd.first && t1.pointEnd.second >= t2.pointEnd.second) ||
        (t1.pointBegin.first <= t2.pointEnd.first && t1.pointEnd.second >= t2.pointBegin.second && t1.pointEnd.first >= t2.pointEnd.first && t1.pointBegin.second <= t2.pointBegin.second) ||
        (t1.pointBegin.first <= t2.pointBegin.first && t1.pointBegin.second <= t2.pointEnd.second && t1.pointEnd.first >= t2.pointBegin.first && t1.pointEnd.second >= t2.pointEnd.second))
        return true;
    if ((t2.pointBegin.first <= t1.pointBegin.first && t2.pointBegin.second <= t1.pointBegin.second && t2.pointEnd.first >= t1.pointBegin.first && t2.pointEnd.second >= t1.pointBegin.second) ||
        (t2.pointBegin.first <= t1.pointEnd.first && t2.pointBegin.second <= t1.pointEnd.second && t2.pointEnd.first >= t1.pointEnd.first && t2.pointEnd.second >= t1.pointEnd.second) ||
        (t2.pointBegin.first <= t1.pointEnd.first && t2.pointEnd.second >= t1.pointBegin.second && t2.pointEnd.first >= t1.pointEnd.first && t2.pointBegin.second <= t1.pointBegin.second) ||
        (t2.pointBegin.first <= t1.pointBegin.first && t2.pointBegin.second <= t1.pointEnd.second && t2.pointEnd.first >= t1.pointBegin.first && t2.pointEnd.second >= t1.pointEnd.second))
        return true;
    return false;
}
