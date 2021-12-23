#include <iostream>
#include <string>

template <class T>
class Array
{
private:
    T var;
public:
    Array(T arg)
    : var(arg)
    {
    }

    void print()
    {
        std::cout << var << "\n";
    }
};

int main()
{
    Array<int> obj1(5);// = new<int> obj(5);
    Array<std::string> obj2("sldlfds");// = new obj("sljfsld");

    obj1.print();
    obj2.print();

    Array<float>* obj3 = new Array<float>(5.5f);
    obj3->print();

    return 0;
}
