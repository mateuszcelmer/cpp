#include <iostream>
#include <memory>
#include <string>

class Person
{
    std::string m_name;
    std::weak_ptr<Person> m_sibling; // initially created empty

public:
    Person(const std::string &name) : m_name(name)
    {
        std::cout << m_name << " created\n";
    }
    ~Person()
    {
        std::cout << m_name << " destroyed\n";
    }

    friend bool siblingUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2)
    {
        if (!p1 || !p2)
            return false;

        p1->m_sibling = p2;
        p2->m_sibling = p1;

        std::cout << p1->m_name << " is now a sibling of " << p2->m_name << "\n";

        return true;
    }
};

int main()
{
    {
        auto lucy = std::make_shared<Person>("Lucy");   // create a Person named "Lucy"
        auto ricky = std::make_shared<Person>("Ricky"); // create a Person named "Ricky"

        siblingUp(lucy, ricky); // Make "Lucy" point to "Ricky" and vice-versa
    }
    return 0;
}