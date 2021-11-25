/****************************************************************************************************************************
Title         :   Vehicle.hpp
Auhor         :   Team FBK
Description   :   header/interface file for Vehicle and all of its subclasses
****************************************************************************************************************************/

#ifndef VEHICLE_
#define VEHICLE_

#include <iostream>
#include <string>

class Vehicle
{
public:
    //default constructor
    //set name and manufacturer to ""
    //set all numerical values to 0
    Vehicle() : name_{""}, manufacturer_{""}, top_speed_{0}, weight_{0}, mpg_{0}, curr_gas_amt_{1}, garage_spaces_{0}, num_wheels_{0}
    {
    }


    /**
        Parameterized Constructor
        @param name   : name/model of said vehicle
        @param manufacturer  : the name of the manufacturer
        @param topSpeed : a double letting us know the fastest speed of the vehicle in Miles Per Hour
        @param weight : weight of the car pounds
        @param milesPerGallon : how many miles your car gets on a single gallon
        @param currentAmountGas : your vehicle's current gas capacity
    */
    Vehicle(std::string name, std::string manufacturer, double top_speed, double weight, double mpg, double curr_gas_amt) : name_{name}, manufacturer_{manufacturer}, top_speed_{top_speed}, weight_{weight}, mpg_{mpg}, curr_gas_amt_{curr_gas_amt}, garage_spaces_{0}, num_wheels_{0}
    {
    }


    /**
        given your vehicles top speed and @param float duration,
        calculate the distance traveled during the specified time;
        increment distance_traveled_ by this amount
        @param float duration: time traveled
        @return: the distance traveled in the given duration
    */
    double travelMaxSpeed(float duration)
    {
        if (duration <= 0)
        {
            return 0;
        }

        float curr_distance_traveled = top_speed_ * duration;
        distance_traveled_ += curr_distance_traveled;
        curr_gas_amt_ = (14 - curr_distance_traveled * mpg_) / 14;

        if (curr_gas_amt_ < 0)
        {
            curr_gas_amt_ = 0;
        }

        return curr_distance_traveled;
    }


    /**
        Filling up a tank sets it to 1
        @post   :   returns true if your tank has been filled and was not already full
    */
    bool fillUpTank()
    {
        if (curr_gas_amt_ < 1)
        {
            curr_gas_amt_ = 1;
            return true;
        }
        return false;
    }


    double getTopSpeed() const          // returns top_speed_
    {
        return top_speed_;
    }


    double getWeight() const            // returns weight_
    {
        return weight_;
    }


    double getMilesPerGallon() const    // returns milesPerGallon_
    {
        return mpg_;
    }


    size_t getGaragePositions() const   // returns garagePositions_
    {
        return garage_spaces_;
    }


    double getDistanceTraveled() const  // returns distance_traveled_
    {
        return distance_traveled_;
    }


    double getCurrentAmountGas() const  // return how much gas we currently have
    {
        return curr_gas_amt_;
    }


    std::string getName() const         // returns name_
    {
        return name_;
    }


    std::string getManufacturer() const // returns manufacturer_
    {
        return manufacturer_;
    }


    void turn(float degrees)            // adds to current direction
    {
        curr_direction_ += degrees;

        while (curr_direction_ >= 360)
        {
            curr_direction_ -= 360;
        }

        while (curr_direction_ < 0)
        {
            curr_direction_ += 360;
        }
    }


    std::string getDirection()          // gets current direction of vehicle based on degrees
    {
        if (curr_direction_ == 0)
        {
            return "East";
        }
        else if (curr_direction_ < 90)
        {
            return "Northeast";
        }
        else if (curr_direction_ == 90)
        {
            return "North";
        }
        else if (curr_direction_ < 180)
        {
            return "Northwest";
        }
        else if (curr_direction_ == 180)
        {
            return "West";
        }
        else if (curr_direction_ < 270)
        {
            return "Southwest";
        }
        else if (curr_direction_ == 270)
        {
            return "South";
        }
        else if (curr_direction_ < 360)
        {
            return "Southeast";
        }
        else
        {
            return "Out of Bounds";     // ;)
        }
    }


    const size_t getSpaces() const      // returns garage_spaces_
    {
        return garage_spaces_;
    }


    const size_t getNumWheels() const   // returns num_wheels_
    {
        return num_wheels_;
    }


    void setGarageSpaces(size_t spaces) // sets the amount of available garage spaces
    {
        garage_spaces_ = spaces;
    }


    void setNumWheels(size_t wheels)    // sets the number of wheels the vehicle has
    {
        num_wheels_ = wheels;
    }


    bool operator!=(const Vehicle &rhs) const
    {
        bool nameNotEq = rhs.getName() != name_;
        bool manuNotEq = rhs.getManufacturer() != manufacturer_;
        bool result = nameNotEq || manuNotEq;
        return result;
    }


    bool operator==(const Vehicle &rhs) const // Comparison operator overload
    {
        bool nameEq = rhs.getName() == name_;
        bool manuEq = rhs.getManufacturer() == manufacturer_;
        bool result = nameEq && manuEq;
        return result;
    }


    void operator=(const Vehicle &rhs)        // Assignment operator overload
    {
        name_ = rhs.name_;
        manufacturer_ = rhs.manufacturer_;
        top_speed_ = rhs.top_speed_;
        weight_ = rhs.weight_;
        mpg_ = rhs.mpg_;
        curr_gas_amt_ = rhs.curr_gas_amt_;
        garage_spaces_ = rhs.garage_spaces_;
        num_wheels_ = rhs.num_wheels_;
    }

protected:
    std::string manufacturer_;
    std::string name_;
    double top_speed_;
    double weight_;
    double mpg_;
    double curr_gas_amt_;      // <- describe units that gas is measured in [0, 1]  0 <- empty, 1 <- full
    double curr_direction_;    // describes which direction (in degrees) vehicle is facing on a compass
    double distance_traveled_; // how far you have traveled with your vehicle
    size_t garage_spaces_;     // number of garage slots this vehicle takes up
    size_t num_wheels_;

}; // end Vehicle

/***************************************************************************************************************************/
class Car : public Vehicle
{
public:
    Car(std::string name, std::string manufacturer, double top_speed, double weight, double mpg) : Vehicle(name, manufacturer, top_speed, weight, mpg, 0)
    {
        setGarageSpaces(2);
        setNumWheels(4);
    }
}; // end Car

/***************************************************************************************************************************/
class Bus : public Vehicle
{
public:
    Bus(std::string name, std::string manufacturer, double top_speed, double weight, double mpg, size_t number_seats) : Vehicle(name, manufacturer, top_speed, weight, mpg, 0)
    {
        number_seats_ = number_seats;
        setGarageSpaces(4);
        setNumWheels(8);
    }


    size_t getNumSeats() const
    {
        return number_seats_;
    }

private:
    size_t number_seats_;
}; // end Bus

/***************************************************************************************************************************/
class Motorcycle : public Vehicle
{
public:
    Motorcycle(std::string name, std::string manufacturer, double top_speed, double weight, double mpg) : Vehicle(name, manufacturer, top_speed, weight, mpg, 0)
    {
        setGarageSpaces(1);
        setNumWheels(2);
    }
}; // end Motorcycle


/***************************************************************************************************************************/
class Truck : public Vehicle
{
public:
    Truck(std::string name, std::string manufacturer, double top_speed, double weight, double mpg, double cargo_capacity) : Vehicle(name, manufacturer, top_speed, weight, mpg, 0), cargo_capacity_{cargo_capacity}
    {
        setGarageSpaces(8);
        setNumWheels(18);
        weight_of_held_cargo_ = 0;
    }


    bool add_cargo(double weight_of_cargo)
    {
        if (weight_of_cargo + weight_of_held_cargo_ > cargo_capacity_)
        {
            return false;
        }

        weight_of_held_cargo_ += weight_of_cargo;
        return true;
    }


    bool clear()
    {
        try
        {
            weight_of_held_cargo_ = 0;
            return true;
        }
        catch (...)
        {
            return false;
        }
    }


    double getCargoCapacity() const
    {
        return cargo_capacity_;
    }


    double getHeldCargoWeight() const
    {
        return weight_of_held_cargo_;
    }


private:
    double cargo_capacity_;
    double weight_of_held_cargo_;
}; // end Truck


#endif
