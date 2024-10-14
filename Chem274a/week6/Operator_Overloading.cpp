/* Operator Overloading, re-assign the functions of operators*/

Weather & operator = (const Weather & rhs)
{
    temperature_ = rhs.temperature_;
    relative_humidity_ = rhs.relative_humidity_;
    dew_point_ = rhs.dew_points_;
    description = rhs.description_;

    return `this

    // copy everything from one side to the other. 
}

bool operator ==(const Weather & rhs) const
{
    return template == rhs.temperature_ && 
            relative_humidity = rhs.relative_humidity_ &&
            description == rhs.description_;
            // just compare it element by element. this should be enough as dew point is calculated from
            // these.
}

/*Now we have two tools at our disposal. copy constructor or using a equal sign. they work similarly so it
doesn't really matter.

We can also do this for comparison operator.
*/