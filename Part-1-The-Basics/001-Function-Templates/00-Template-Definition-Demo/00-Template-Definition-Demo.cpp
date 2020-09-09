//*******************************************************************************
// Author     : Vaibhv Bendre                                                   *
// Book       : C++ Template - The Complete Guide by Nicolai Josuttis           *
// Assumption : C++17 compatible compiler is used                               *
// Email      : vaibhav.bendre7520@gmail.com                                    *
// Date       : 09/09/2020                                                      *
//*******************************************************************************
#include <iostream>
#include <string>

template<typename T>
T max(T x, T y) {
    return (x < y ? y : x);
}


int main()
{
    int a{}, b{};
    std::cout << "Please provide input : ";
    std::cin >> a >> b;
    std::cout << "\nThe maximum of " << a << " & " << b << " is : " << max(a, b) << std::endl;
    
    double d1{ 12.89 }, d2{98.99};
    std::cout << "\n\nThe maximum of " << d1 << " & " << d2 << " is : " << max(d1, d2) << std::endl;
    
    std::string s1 = "Vaibhav";
    std::string s2 = "Apurwa";
    std::cout << "\n\nThe maximum of " << s1 << " & " << s2 << " is : " << ::max(s1, s2) << std::endl;
}
