#include <iostream>
using namespace std;
#define LOG(x) std::cout << x << std::endl;

class IFlyBehavior
{
public:
    virtual void fly() = 0;
};

class IWalkBehavior
{
public:
    virtual void walk() = 0;
};

class Walk1 : public IWalkBehavior
{
public:
    void walk()
    {
        LOG("walk1");
    }
};

class Walk2 : public IWalkBehavior
{
public:
    void walk()
    {
        LOG("walk2");
    }
};

class Fly1 : public IFlyBehavior
{
public: 
   void fly()
    {
        LOG("fly1");
    }
};

class Fly2 : public IFlyBehavior
{
public:
    void fly()
    {
        LOG("fly2");
    }
};

class Duck : public Fly1, public Fly2, public Walk1, public Walk2
{
public:
    IFlyBehavior *ifb;
    IWalkBehavior *iwb;

    Duck(IFlyBehavior *f, IWalkBehavior *w)
        : ifb(f), iwb(w)
    {
    }

    void fly()
    {
        ifb->fly();
    }
    
    void walk()
    {
        iwb->walk();
    }
};

int main()
{
    Duck *obj = new Duck(new Fly1(), new Walk2());
    obj->fly();
    obj->walk();
}
