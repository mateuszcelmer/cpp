//https://www.geeksforgeeks.org/builder-design-pattern/

#include <iostream>
#include <string>
#include <memory>

class HousePlan // interface
{
public:
    virtual void setBasement(std::string basement) = 0;
    virtual void setStructure(std::string structure) = 0;
    virtual void setRoof(std::string roof) = 0;
    virtual void setInterior(std::string interior) = 0;
    virtual void setInfo(std::string info) = 0;
};

class House : public HousePlan
{
    std::string basement;
    std::string structure;
    std::string roof;
    std::string interior;
    std::string info;

public:
    void setBasement(std::string basement) { this->basement = basement; }
    void setStructure(std::string structure) { this->structure = structure; }
    void setRoof(std::string roof) { this->roof = roof; }
    void setInterior(std::string interior) { this->interior = interior; }
    void setInfo(std::string info) { this->info = info; }
    std::string getInfo() { return info; }
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

class IglooHouseBuilder : public HouseBuilder
{
    House house;

public:
    IglooHouseBuilder() { house.setInfo("Igloo House"); }
    void buildBasement() { house.setBasement("Ice Bars"); }
    void buildStructure() { house.setStructure("Ice Blocks"); }
    void bulidRoof() { house.setRoof("Ice Carvings"); }
    void buildInterior() { house.setInterior("Ice Dome"); }
    House getHouse() { return house; };
};

class TipiHouseBuilder : public HouseBuilder
{
    House house;

public:
    TipiHouseBuilder() { house.setInfo("Tipi House"); }
    void buildBasement() { house.setBasement("Wooden Poles"); }
    void buildStructure() { house.setStructure("Wood and Ice"); }
    void bulidRoof() { house.setRoof("Wood, caribou and seal skins"); }
    void buildInterior() { house.setInterior("Fire Wood"); }
    House getHouse() { return house; };
};

class CivilEngineer
{
    std::unique_ptr<HouseBuilder> houseBuilder;

public:
    CivilEngineer(std::unique_ptr<HouseBuilder> &&houseBuilder) : houseBuilder(std::move(houseBuilder)){};
    House getHouse() { return houseBuilder->getHouse(); }
    void constructHouse()
    {
        houseBuilder->buildBasement();
        houseBuilder->buildStructure();
        houseBuilder->bulidRoof();
        houseBuilder->buildInterior();
    }
};

int main()
{
    std::unique_ptr<HouseBuilder> iglooBuilder = std::make_unique<IglooHouseBuilder>();
    auto engineer = std::make_unique<CivilEngineer>(std::move(iglooBuilder));

    engineer->constructHouse();
    House house = engineer->getHouse();
    std::cout << "Builder constructed: " << house.getInfo() << std::endl;
    return 0;
}