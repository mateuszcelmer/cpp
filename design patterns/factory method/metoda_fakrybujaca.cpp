/* acknowledgements to: https://www.p-programowanie.pl/wzorce-projektowe/fabryka-abstrakcyjna/#more-3197 */

#include <iostream>

using namespace std;

class IShape
{
};

class Square : public IShape
{
};
class Triangle : public IShape
{
};

class ShapeFactory
{
public:
    virtual IShape *createShape() = 0;
};

class SquareFactory : public ShapeFactory
{
    IShape *createShape()
    {
        return new Square();
    }
};

class TriangleFactory : public ShapeFactory
{
    IShape *createShape()
    {
        return new Triangle();
    }
};

int main()
{
    ShapeFactory *shapeFactory = new SquareFactory();
    IShape *square = (*shapeFactory).createShape();

    ShapeFactory *triangleFactory = new TriangleFactory();
    IShape *triangle = triangleFactory->createShape();

    return 0;
}