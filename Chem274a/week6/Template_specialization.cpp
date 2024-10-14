/* Template part 2 */
#include <iostream>

// template keyword. 
template<typename T>
// class definition
class Wrapper
{
    //in private member data, we store a type T and we call it data.
    private:
        // privately define 
        T data_;

    public:
    // write a constructor, we take something that is a type of data and store it into our data.
        Wrapper(const T & data)
            // intializer list. This will assume type T has a copy constructor.
            : data_(data)
        {}
        // points to thte data_
        T & data()
        {
            return data_;
        }
};
/* how do we split these into multiple files. In templates you can't generally do that.
WHen a compiler reaches code like this, then goes to try to find the template, it creates an instantiation of that tempalte
This is called template instantiation. In order for the compiler to do that, t has to have all the code of that template
when a compiler is compiling a single source file, it compiles all at once. */



/* lets say we want the class to be general but specific when it comes to a string.*/
template<>
// give it the same name and structure.
class Wrapper<std::string> // we are specializing the wrapper class in the case of a string
{
    private:
        std::string data_;
    public:
        Wrapper(const std::string & data)
            : data_(data)
        {}
        std::string & data()
        {
            return data_;
        }
        size_t size() const
        {
            return data_.size();
        }
};      

int main(void)
{
    /*To give the class a type, we can identify the type*/
    Wrapper<int> w1(10);
    Wrapper<std::string> s1("Hello");
    
    std::cout << w1.data() << std::endl;
    std::cout << s1.data() << std::endl;
    std::cout << s1.size() << std::endl;
    return 0;
}