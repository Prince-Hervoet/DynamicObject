#include <iostream>
#include "dynamic_object.hpp"

int main()
{
    etools::DynamicObject *dy = new etools::DynamicObject();
    dy->Add("asdfasdf");
    std::cout << dy->Get(0)->GetPtrValue() << std::endl;
}