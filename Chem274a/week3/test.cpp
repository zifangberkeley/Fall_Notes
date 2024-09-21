#include <iostream>
#include <cmath> // for pi

/* Similar to the previous exercise, write a class representing a circle. This time, the class
 * member functions should be const correct. Also, there will be another function for
 * setting the radius after an object has been constructed.
 *
 * The constructor should take only the radius
 *
 * There should be other funtions:
 * 1.) radius         (Allows for setting and getting the radius. Should not take an argument)
 * 2.) area           (returns the area of the circle)
 * 3.) circumference  (returns the circumference)
 *
 * Hint: For const correctness, you will have 4 functions
 * Hint #2: Use M_PI for the value of pi. This is defined in the <cmath> header
 */

class Circle
{
    private:
        double radius_;
        const double pi_ = M_PI;
        void area() const
        {
            double area = pi_*radius_*radius_;
        }
        void circumference() const
        {
            double circumference = pi_ * 2 * radius_;  
        }
    public:
        Circle(double radius) : radius_(radius)
        {
            area();
            circumference();
        }
        //accesssor and mutator
        void radius(double radius)
        {
            radius_ = radius;
            area();
            circumference();
        }

};

int main(){
    return 0;
}