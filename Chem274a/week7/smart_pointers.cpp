#include <iostream>
#include <vector> 
template<typename T>
class Pointer
{
    private:
        T* data_;
    
    public:
        Pointer(T * p)
        {
            data_ = p;
        }

        ~Pointer()
        {
            delete data_;
            std::cout << "Pointer deleted" << std::endl;
        }
        
        // using operator overloading, we can return the value of pointer

        T & operator*()
        {
            return *data_;
        }
};

int main(void)
{
    Pointer<int> ptr(new int);
    *ptr = 50;
    return 0;
    // make sure to note delete here. it will result in a double delete.
    // it doesn't have to be an integer, it can be a vector since this is templated.
    // this is called a smart pointer, because it deals with almost every type of object you put in there. 

}