#include <iostream>
#include "dynamic_object.hpp"

int main()
{
    etools::DynamicObject dy = etools::getDynamicObject(true);
    std::string s = "1234";
    dy.Set(s, 340);
    dy.Add("asdfasdf");
    std::cout << dy[0]->GetIntValue() << std::endl;
}