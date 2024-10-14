/*There are three different access modifiers 
- public: Anything can access(inside and outside class)
- private: only this class can access (even derived classes cannot access)
- protected: only this class and derived classes can access*/

/*Inheritance modifiers
- There are three ways to inherit a base class
    - also named public, protected and private
By far the most common is public inheritance
-   puublic members of the base class stays public
- protected members of the base class stay protected
- private members of the base class stay private 
public inheritance = "is a" relationship
protected and private = "has a" relationship. useful in rare cases (adapters)

just inherit it as a normal class member. 

Rule of thumb
class member variables (data) - almost always private
- if derived classes have to access data through existing interfaces, changes in base  class are less likely
to break derived classes
- protected is also acceptable some cases
- class methods - depends on the use case
    - keep access as limited as possible
- inheritance - most of the time, use public.*/

#include <iostream>
#include <string>

class Employee
{
    private:
        int id_;
        std::string name_;
    public:
        // constructor
        Employee(int id, std::string name)
            // initializer
            : id_(id), name_(name)
        {}

        int id() const {return id_;}
        std::string name() const {return name_;}
        void display() const
        {
            std::cout << "[" << id_ << "]" << name_ << std::endl;
        }
}; 

// lets set up a inheritance.

class Scientist: public Employee
{
    private:
        std::string field_;
    public:
        Scientist(int id, std::string name, std::string field)
        : Employee(id, name), field_(field)
        {}
        void display() const
        {
            //std::cout << "[" << id_ << "]" << name_ << "{" << field_ << "}"<< std::endl;
            // in this case, since name is in private, we can't call it. we have to use the accessor funciton instead.
            // or we can change the information from private to protected.
            std::cout << "[" << id() << "]" << name() << "{" << field_ << "}"<< std::endl;
        }      
};

// slicing of derived classes 
void print(const Employee & emp)
{       
    std::cout << "Name:" << emp.name() << std::endl;
    // we take it from the employee class. we cast bill and emily to this class, this is a constant function
    // due to public inheritance, a scientist is a employee, this works.
    emp.display(); // it will only print from the base class. slices off the derived class. 

}





int main(void)
{
    Employee bill(1, "Bill");
    bill.display();

    Scientist emily(2, "Emily", "Chemistry");
    emily.display();

// in a constructor setting, it will actually go from top to bottom. In the case of destructor,
// it will go from bottom to top. A constructor must be called inside the derived class. 

// what if we want to split the scientist display functio and the employee display function?
// we can override it with a static cast 
    //static_cast<Employee>(Emily).display(); // this will be the function specifcally to the base class.
// or we can turn this inot a variable 
    //Employee & emily_as_employee = static_cast<Employee &>(Emily).display(); // this will be the function specifcally to the base class.
    print(bill);
    print(emily);
}; 