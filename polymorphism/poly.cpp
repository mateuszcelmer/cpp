#include <iostream>
using namespace std;
/*

Polimorfizm C ++ oznacza, że ​​wywołanie funkcji składowej 
spowoduje wykonanie innej funkcji w zależności od typu obiektu, 
który wywołuje funkcję.

*/

class Animal
{
  protected:
    string name = {"Animal"};

  public:
    Animal(string n) { name = n; };
    virtual void voice() { cout << name << "'s voice" << endl; }
};

class Dog : public Animal
{
  public:
    Dog(string n) : Animal(n){};
    void voice() { cout << "Dog " << name << " barks" << endl; }
};

class Cat : public Animal
{
  public:
    Cat(string n) : Animal(n){};
    void voice() { cout << "Cat " << name << " meows" << endl; }
};

int main()
{
    Animal *anim;
    Dog dog("Dogger");
    Cat cat("Ciapek");

    anim = &dog;
    anim->voice();

    anim = &cat;
    anim->voice();

    return 0;
}