#include <iostream>
#include "dynamic_object.hpp"

int main()
{
    etools::DynamicObject *dy = new etools::DynamicObject();
    dy->Add((void *)("asdf"));
    dy->Add((void *)("345"));
    dy->Add((void *)("11111"));
    dy->Add((void *)("56"));
    dy->Add((void *)("fgfgd"));
    dy->Remove(0);
    dy->Remove(0);
    dy->Remove(0);
    std::cout << dy->Size() << std::endl;
}