//https://www.geeksforgeeks.org/builder-design-pattern/

#include <iostream>
#include <string>

class HousePlan // interface
{
public:
    virtual void setBasement(std::string basement) = 0;
    virtual void setStructure(std::string structure) = 0;
    virtual void setRoof(std::string roof) = 0;
    virtual void setInterior(std::string interior) = 0;
};

class House : HousePlan
{
    std::string basement;
    std::string structure;
    std::string roof;
    std::string interior;

public:
    void setBasement(std::string basement) { this->basement = basement; }
    void setStructure(std::string structure) { this->structure = structure; }
    void setRoof(std::string roof) { this->roof = roof; }
    void setInterior(std::string interior) { this->interior = interior; }
};

class HouseBuilder // interface
{
public:
    virtual void buildBasement() = 0;
    virtual void buildStructure() = 0;
    virtual void bulidRoof() = 0;
    virtual void buildInterior() = 0;
    virtual House getHouse() = 0;
};

class IglooHouseBuilder : HouseBuilder
{
    House house;

public:
    IglooHouseBuilder() {}
    void buildBasement() { house.setBasement("Ice Bars"); }
    void buildStructure() { house.setStructure("Ice Blocks"); }
    void bulidRoof() { house.setRoof("Ice Carvings"); }
    void buildInterior() { house.setInterior("Ice Dome"); }
    House getHouse() { return house; };
};
class IglooHouseBuilder : HouseBuilder
{
    House house;

public:
    IglooHouseBuilder() {}
    void buildBasement() { house.setBasement("Ice Bars"); }
    void buildStructure() { house.setStructure("Ice Blocks"); }
    void bulidRoof() { house.setRoof("Ice Carvings"); }
    void buildInterior() { house.setInterior("Ice Dome"); }
    House getHouse() { return house; };
};

int main()
{

    return 0;
}