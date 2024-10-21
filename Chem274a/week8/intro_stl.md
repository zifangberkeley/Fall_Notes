# compared to the language
- C++ standard is composed of two parts. the language and the standard library

Language: syntax, keywords, functions, classes, templates.
Library: file I/O, vectoer and other containers, sort math etc. 
can use the language without the library

The library is often called the STL because it heavily depends on templates. this allows it to work with any data type.

## Class Member Types:
#include <iosstream>

class MemberTypeExample
{
    public: 
        typedef int valuetype; // for this class we are defining a new class called valuetype that's based on int.
};

int main(void)
{
    MemberTypeExample::value_type num = 4; // this will create an object of the value type int. 
    return 0;
}

Not that useful unless it's a templated class
#include <iosstream>

template<typename T>
class MemberTypeExample
{
    public: 
        typedef T valuetype; // for this class we are defining a new class called valuetype that's based on int.
};

int main(void)
{
    MemberTypeExample::value_type num = 4; // this will create an object of the value type int. 
    return 0;
}

now it can be anything and you can write generic code. 

## C++ iterators

include<iostream>
include<vector>

int main(void)
{
    std::vector<int> v{1,2,3,4,5}
    // objects with random access can be iterated through for loop
    std::cout << v[0] << std::endl;
}

// if not, we can use an iterator memberclass type.

int main(void)
{
    std::list<int> v{1,2,3,4,5}
    std::list<int>::iterator it = v.begin();
    it++;
    // the iterator will behave like a pointer.
    std::cout <<*it << std::endl;
    for(std::vector<int>:: iterator it = v.begin();
    it != v.end();
    ++it) // don't try to print out v.end(). We iterate until the the end. The forloop will end it it won't be incremented anymore.
    // not commonly used anymore but the begin and end functions will be used alot. this builds much of the stl.
 
}
## Cling

for demo purposes, we will use cling. 