#include <iostream>
#include "dynamic_object.hpp"

int main()
{
    etools::DynamicObject dy = etools::getDynamicObject(true);
    std::string s = "1234";
    dy.Set("asdf", "123");
    dy.Add("asdfasdf");
    std::cout << (const char *)dy[0]->GetPtrValue() << std::endl;
}