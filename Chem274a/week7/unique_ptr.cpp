#include <iostream>
#include <vector>
#include <memory>

// memory is part of the std. and it contains a smart pointer

int main(void)
{
    //std::unique_ptr<int> ptr(new int); //to point to an array unique_ptr<int []> ptr(new int[])
    auto ptr = std::make_unique<int>(99); // ptr[0] = 50;
    std::cout << *ptr << std::endl;
    std::cout << ptr.get() << std::endl; //this will get us the pointer.
    return 0;

    // don't try to pass it through a funciton normally, you have to pass it by reference using const.
    // make_unieq will automaticaly make the new pointer, you don't need to write new now.
}