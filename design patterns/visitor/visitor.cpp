// np. http://devman.pl/pl/techniki/wzorce/wzorce-projektowe-odwiedzajacyvisitor/

#include <iostream>
#include <string>
#include <list>

class Visitor;
class ConcreteElementA;
class ConcreteElementB;

class Element
{
public:
    virtual void accept(Visitor *visitor) = 0;
};

class Visitor
{
protected:
    std::string name;

public:
    virtual void visit(ConcreteElementA *a) = 0;
    virtual void visit(ConcreteElementB *b) = 0;
};

class ConcreteElementA : public Element
{
    virtual void accept(Visitor *visitor) override
    {
        visitor->visit(this);
    }
};
class ConcreteElementB : public Element
{
    virtual void accept(Visitor *visitor) override
    {
        visitor->visit(this);
    }
};

class ConcreteVisitor1 : public Visitor
{
public:
    ConcreteVisitor1() { name = "Visitor1"; };
    virtual void visit(ConcreteElementA *a) override
    {
        std::cout << "ConcreteElementA visited by " << name << std::endl;
    };
    virtual void visit(ConcreteElementB *b) override
    {
        std::cout << "ConcreteElementB visited by " << name << std::endl;
    };
};

class ConcreteVisitor2 : public Visitor
{
public:
    ConcreteVisitor2() { name = "Visitor2"; };
    virtual void visit(ConcreteElementA *a) override
    {
        std::cout << "ConcreteElementA visited by " << name << std::endl;
    };
    virtual void visit(ConcreteElementB *b) override
    {
        std::cout << "ConcreteElementB visited by " << name << std::endl;
    };
};

struct ObjectStructure
{
    void push_back(Element *el)
    {
        objs.push_back(el);
    }
    void detach(Element *el)
    {
        objs.remove(el);
    }
    void accept(Visitor *visitor)
    {
        for (auto &&obj : objs)
        {
            obj->accept(visitor);
        }
    }

private:
    std::list<Element *> objs;
};

int main()
{
    ObjectStructure o;

    o.push_back(new ConcreteElementA);
    o.push_back(new ConcreteElementB);

    o.accept(new ConcreteVisitor1);
    o.accept(new ConcreteVisitor2);

    return 0;
}