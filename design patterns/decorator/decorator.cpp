#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Beverage
{
protected:
  string description = "unknown beverage";

public:
  virtual string getDescription() { return description; }
  virtual double cost() = 0;
};

class CondimentDecorator : public Beverage
{
protected:
  shared_ptr<Beverage> beverage;
};

class Espresso : public Beverage
{
public:
  Espresso() { description = "Espresso"; }
  double cost() { return 1.99; }
};

class HouseBlend : public Beverage
{
public:
  HouseBlend() { description = "HouseBlend"; }
  double cost() { return 0.89; }
};

class Mocha : public CondimentDecorator
{
public:
  Mocha(shared_ptr<Beverage> beverage) { this->beverage = beverage; }
  string getDescription() { return beverage->getDescription() + " Mocha"; }
  double cost() { return .20 + beverage->cost(); }
};

class Soy : public CondimentDecorator
{
  shared_ptr<Beverage> beverage;

public:
  Soy(shared_ptr<Beverage> beverage) { this->beverage = beverage; }
  string getDescription() { return beverage->getDescription() + " Soy"; }
  double cost() { return .15 + beverage->cost(); }
};

class Whip : public CondimentDecorator
{
  shared_ptr<Beverage> beverage;

public:
  Whip(shared_ptr<Beverage> beverage) { this->beverage = beverage; }
  string getDescription() { return beverage->getDescription() + " Whip"; }
  double cost() { return .10 + beverage->cost(); }
};

int main()
{
  shared_ptr<Beverage> beverage1 = make_shared<Espresso>();
  cout << beverage1->getDescription() << " $" << beverage1->cost() << endl;

  shared_ptr<Beverage> beverage2 = make_shared<HouseBlend>();
  cout << beverage2->getDescription() << " $" << beverage2->cost() << endl;
  beverage2 = make_shared<Mocha>(beverage2);
  beverage2 = make_shared<Mocha>(beverage2);
  beverage2 = make_shared<Soy>(beverage2);
  beverage2 = make_shared<Whip>(beverage2);
  cout << beverage2->getDescription() << " $" << beverage2->cost() << endl;

  return 0;
}