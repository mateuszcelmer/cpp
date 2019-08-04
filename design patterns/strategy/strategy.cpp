#include <iostream>
#include <vector>

using namespace std;

class FlyBehaviour
{
public:
    virtual void fly() = 0;
};

class QuackBehaviour
{
public:
    virtual void quack() = 0;
};

class Duck
{
    FlyBehaviour *flyBehaviour;
    QuackBehaviour *quackBehaviour;

public:
    void swim() { std::cout << "I'm swimming" << std::endl; };
    virtual void display() = 0;
    void performFly() { flyBehaviour->fly(); }
    void performQuack() { quackBehaviour->quack(); }
    void setFlyBehaviour(FlyBehaviour *flyBehaviour) { this->flyBehaviour = flyBehaviour; }
    void setQuackBehaviour(QuackBehaviour *quackBehaviour) { this->quackBehaviour = quackBehaviour; }
    virtual ~Duck()
    {
        delete flyBehaviour;
        delete quackBehaviour;
    }
};

// --- QuackBehaviour concretions

class Quack : public QuackBehaviour
{
public:
    void quack() { std::cout << "Quack!" << std::endl; }
};

class Squeak : public QuackBehaviour
{
public:
    void quack() { std::cout << "Squeak!" << std::endl; }
};

class MuteQuack : public QuackBehaviour
{
public:
    void quack() { std::cout << "---mute---" << std::endl; }
};

// --- Fly Behaviour concretions

class FlyWithWings : public FlyBehaviour
{
public:
    void fly() { std::cout << "I'm flying!!!" << std::endl; }
};

class FlyNoWay : public FlyBehaviour
{
public:
    void fly() { std::cout << "I can't fly" << std::endl; }
};

// --- Ducks concretions

class MallardDuck : public Duck
{
public:
    void display() { std::cout << "MallardDuck" << std::endl; }
    MallardDuck()
    {
        setFlyBehaviour(new FlyWithWings);
        setQuackBehaviour(new Quack);
    }
};

class RedheadDuck : public Duck
{
public:
    void display() { std::cout << "RedheadDuck" << std::endl; }
    RedheadDuck()
    {
        setFlyBehaviour(new FlyWithWings);
        setQuackBehaviour(new Quack);
    }
};

class RubberDuck : public Duck
{
public:
    void display() { std::cout << "RubberDuck" << std::endl; }
    RubberDuck()
    {
        setFlyBehaviour(new FlyNoWay);
        setQuackBehaviour(new Squeak);
    }
};

class DecoyDuck : public Duck
{
public:
    void display() { std::cout << "DecoyDuck" << std::endl; }
    DecoyDuck()
    {
        setFlyBehaviour(new FlyNoWay);
        setQuackBehaviour(new MuteQuack);
    }
};

int main()
{
    std::vector<Duck *> ducksVector{
        new MallardDuck,
        new RedheadDuck,
        new RubberDuck,
        new DecoyDuck};

    for (auto &&duck : ducksVector)
    {
        duck->display();
        duck->performFly();
        duck->performQuack();
        std::cout << "" << std::endl;
        delete duck;
    }

    ducksVector.clear();

    return 0;
}