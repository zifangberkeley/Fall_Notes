/* Introduction to C++ templates
This is a non-type function.*/

#include <iostream>
#include <complex>

template<typename T>
T sum(T a, T b, T c)
{   
    std::cout << "IN the templated sum" << std::endl;
    return a + b + c;
}

/*double sum(double a, double b, double c){
    std::cout << "In the sum of double" << std::endl;
    return a+b+c;
}

int sum(int a, int b, int c){
    std::cout << "In the sum of int" << std::endl;
    return a+b+c;
}

std::complex<double> sum(std::complex<double> a, std::complex<double> b, std::complex<double> c);
{
    std::cout << "In sum of complex<doule" < std::endl;
    return a + b + c;
}*/


int main(void)
{
    std::cout << sum(1.1,2.2,3.3) << std:: endl;
    std::cout << sum(1,2,3) << std::endl;
    return 0;
}

/* this will print out the sum of floats. But if you want to print out integers, 
just write another line for integers. This is standard function overloading. Generally, it's bad to duplicate code.
Python doesn't have this type problem. We are going to wrtie a single sum function using a template. syntax
template keyword<typename T> same thing as keyword<class T>. The compiler finds and replace the captial T with double and link the function to the call
it's taking the template and duplicate the code for other types. When we have a function that already matches the type, it will go
specifically for the double type first. if it's too ambiguious, it will find a function that takes three doubles and uses that
rather than hte more general template version,*/

/* we can create one for standard library types.

template<typename  T>
std::<complex T>*/

