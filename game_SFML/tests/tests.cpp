#include <iostream>
#include <memory>
#include <gtest/gtest.h>
#include "../src/map.h"
#include "../src/object.h"
#include "../src/objects/object.cpp"
#include "../src/objects/ball.h"
#include "../src/objects/ball.cpp"

using namespace std;

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(map, pointF)
{
    PointF p{1, 2};
    auto [x, y] = p;
    ASSERT_FLOAT_EQ(x, 1.f);
    ASSERT_FLOAT_EQ(y, 2.f);
}

TEST(map, insert)
{
    auto a = std::make_shared<Ball>(PointF{800, 800});
    Map<Ball, Obstacle> m;
    auto calc = m.calcPart(a);
    m.insert(a);
    EXPECT_TRUE(m.hasObject(a));
}

TEST(map, no_element_found)
{
    Map<Ball, Obstacle> m;
    auto el = m.findElemByPtr(std::make_shared<Ball>());
    ASSERT_FALSE(el.has_value());
}

TEST(map, elements_found)
{
    Map<Ball, Obstacle> m;
    auto a = std::make_shared<Ball>(PointF{800, 800});
    auto b = std::make_shared<Ball>(PointF{800, 800});
    auto c = std::make_shared<Ball>(PointF{800, 800});
    m.insert(a);
    m.insert(b);
    m.insert(c);
    ASSERT_TRUE(m.findElemByPtr(a).has_value());
    ASSERT_TRUE(m.findElemByPtr(b).has_value());
    ASSERT_TRUE(m.findElemByPtr(c).has_value());
}

TEST(map, which_part_calculation)
{
    mapSize_t size{1000, 1000};
    Map<Ball, Obstacle> m(size, 4);
    auto a = std::make_shared<Ball>(PointF{800, 800});
    auto b = std::make_shared<Ball>(PointF{200, 800});
    auto c = std::make_shared<Ball>(PointF{800, 200});
    auto d = std::make_shared<Ball>(PointF{200, 200});
    m.insert(a);
    m.insert(b);
    m.insert(c);
    m.insert(d);
    EXPECT_EQ(m.calcPart(a), 3);
    EXPECT_EQ(m.calcPart(b), 2);
    EXPECT_EQ(m.calcPart(c), 1);
    EXPECT_EQ(m.calcPart(d), 0);
}