#include <iostream>
#include "dynamic_object.hpp"

etools::DynamicObject &test()
{
    etools::DynamicObject &dy = etools::getDynamicObject(true);
    int *res = new int[10];
    double s = 1.2;
    dy.Add(res);
    dy.Add(s);
    dy.Add(123124);
    return dy;
}

int main()
{
    etools::DynamicObject dy = test();
    std::cout << (int *)dy[0]->GetPtrValue() << std::endl;
    std::cout << dy[1]->GetDoubleValue() << std::endl;
    delete[] (int *)dy[0]->GetPtrValue();
    dy.Clear();
    std::cout << sizeof(dy) << std::endl;
    return 0;
}