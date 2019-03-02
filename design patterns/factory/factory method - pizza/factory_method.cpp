#include <iostream>
#include <string>
#include <memory>
#include <list>

using namespace std;

class Pizza
{
  protected:
    string name;
    string dough;
    string sauce;
    list<string> toppings;

  public:
    void prepare() {}
    void bake() {}
    void cut() {}
    void box() {}
};

class NYStyleCheesePizza : public Pizza
{
};

class NYStyleVeggiePizza : public Pizza
{
};

class ChicagoStyleCheesePizza : public Pizza
{
};

class ChicagoStyleVeggiePizza : public Pizza
{
};

class CaliforniaStyleCheesePizza : public Pizza
{
};

class CaliforniaStyleVeggiePizza : public Pizza
{
};

class PizzaStore
{
  protected:
    virtual Pizza createPizza(string type) = 0;

  public:
    Pizza orderPizza(string type)
    {
        Pizza pizza;
        pizza = createPizza(type);
        pizza.prepare();
        pizza.bake();
        pizza.cut();
        pizza.box();

        return pizza;
    }
};

class NYPizzaStore : public PizzaStore
{
  protected:
    Pizza createPizza(string type)
    {
        if (type == "cheese")
            return NYStyleCheesePizza();
        if (type == "veggie")
            return NYStyleVeggiePizza();
        else
            return Pizza();
    }
};

class ChicagoPizzaStore : public PizzaStore
{
  protected:
    Pizza createPizza(string type)
    {
        if (type == "cheese")
            return ChicagoStyleCheesePizza();
        if (type == "veggie")
            return ChicagoStyleVeggiePizza();
        else
            return Pizza();
    }
};

class CaliforniaPizzaStore : public PizzaStore
{
  protected:
    Pizza createPizza(string type)
    {
        if (type == "cheese")
            return CaliforniaStyleCheesePizza();
        if (type == "veggie")
            return CaliforniaStyleVeggiePizza();
        else
            return Pizza();
    }
};

int main()
{
    shared_ptr<PizzaStore> nyStore = make_shared<NYPizzaStore>();
    shared_ptr<PizzaStore> chicagoStore = make_shared<ChicagoPizzaStore>();

    Pizza pizza = nyStore->orderPizza("cheese");
    pizza = chicagoStore->orderPizza("veggie");

    
    return 0;
}