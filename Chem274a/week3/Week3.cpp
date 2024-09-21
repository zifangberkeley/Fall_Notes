/* Week3 */
/* This week we will talk about structure and classes of C++.*/

#include <string>
#include <iostream>
#include <cmath>

// create and object with all the weather information
/*struct Weather
{
    double temperature;
    double relative_humidity;
    double dew_point;
    std::string description; 
    // first initiate the variables.
}; //end the structure with a semi-colon. fit everything inside the brackets.
*/
class Weather_class
{//classes have two types of data, private or public/ private only inside the class structure. public, data can be accessed from the outside.
// we can use underscores for private data to make the codes cleaner. Just put underscores after the variable.
    private:
        double temperature_; //compiler won;t be able to read it and access it. This will be good for encaspulation. data members are usually private. bad practice for them to be public.
        double relative_humidity_;
        double dew_point_;
        std::string description_;
        void calculate_dew_point(){
        double b = 18.678;
        double c = 257.14;
        double gamma = std::log(0.01*relative_humidity_) + (b*temperature_)/(c+temperature_);
        this -> dew_point_ = c * gamma / (b-gamma);
        }
    public:
        // Constructor function. you have to initialize the members of the class before you get to the body.
        Weather_class(double temperature, double relative_humidity, std::string description) : temperature_(temperature), relative_humidity_(relative_humidity), description_(description) 
        {
            calculate_dew_point();
        }
        // copy constructor. basically inheritance. 
        Weather_class(const Weather_class & other)
            : temperature_(other.temperature_), relative_humidity_(other.relative_humidity_), dew_point_(other.dew_point_), description_(other.description_)
        {
            std::cout << "In this copy constructor" << std::endl;
            temperature_ = other.temperature_; // one of the things we can copy or we can copy the initialization list.
            // it has access to private objects.
        }
        // writing our own desturctor for dealing with resources.
        ~Weather_class()// never any arguments
        {
            std::cout << "In the destructor" << std::endl;
            // called when an object is out of scope.
        }
        // Accessors, accessing private data through the use of these functions. we don't have to add self when we access the member of the class. 
        double getting_temperature()
        {
            return temperature_; //this variable is a pointer. we will have to deference is using ->
        }
        // mutator function to set the variable.
        void set_temperature(double temperature)
        {
            temperature_ = temperature;
            calculate_dew_point();
        }

        std::string & get_description(){
            return description_;
        }
        void print(){
            std::cout << "Temperature: " << temperature_ << std::endl;
            std::cout << "RD: " << dew_point_ << std::endl;
            std::cout << "RH: " << relative_humidity_ << std::endl;
            std::cout << "Description: " << description_ << std::endl;
            // there's a problem with structures like these. as temperature, dew_point and humidity is connected. So we will have to use classes.
}
};

class WeatherDate //writing constructor and destructor
{ 
  private:
    Weather_class weather_;
    std::string date_;

  public:
    WeatherDate(const Weather_class & weather, const std::string & date) : weather_(weather), date_(date){
        // we only wrote a single constructor, the compiler help us generate one, we are going to write one manually but the goal is to not write it yourself.

    }

};

int main(void){
    Weather_class now(20.0, 50.0, "sunny"); // this has a variable now of type Weather.
    //now.dew_point = 10.0;
    //now.description = "cloudy";
    //now.relative_humidity = 40.0;

    now.print();

    std::cout << "Changing temperature and description" << std::endl;
    now.set_temperature(30.0);
    now.get_description() = "raining";
    WeatherDate wd(now, "today");
    now.print();

    return 0;
}