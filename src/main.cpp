#include <iostream>
#include "dynamic_object.hpp"

int main()
{
    etools::DynamicObject dy = etools::getDynamicObject(true);
    dy.Add("asdfasdf");
    std::cout << dy[0]->GetPtrValue() << std::endl;
}