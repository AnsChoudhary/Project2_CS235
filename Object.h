/****************************************************************************************************************************
Title         :   Vehicle.hpp
Auhor         :   Team FBK
Description   :   header/interface file for Object and all of its subclasses
****************************************************************************************************************************/

#ifndef OBJECT_
#define OBJECT_

#include <string>
#include <iostream>

using namespace std;

class Object
{
public:
    //default object constructor
    Object() : name_{""}, manufacturer_{""}, weight_{0}
    {
    }

    //parameterized object constructor
    Object(std::string name, std::string manufacturer, double weight) : manufacturer_{manufacturer}, weight_{weight}, name_{name}
    {
    }

    double getWeight() const //returns the weight
    {
        return weight_;
    }

    std::string getManufacturer() const //returns manufacturer
    {
        return manufacturer_;
    }

    std::string getName() const //returns the name (model)
    {
        return name_;
    }

    size_t getSpaces() const //returns spaces that the object takes up in the garage
    {
        return spaces_;
    }

    bool operator==(const Object &rhs) const //overload == operator to see if objects are equal
    {
        bool manuEq = rhs.getManufacturer() == manufacturer_;
        bool nameEq = rhs.getName() == name_;
        bool spacesEq = rhs.getSpaces() == spaces_;
        bool weightEq = rhs.getWeight() == weight_;
        bool result = manuEq && nameEq && spacesEq && weightEq;
        return result;
    }

    bool operator!=(const Object &rhs) const //overload != operator to see if objects are not equal
    {
        bool manuEq = rhs.getManufacturer() != manufacturer_;
        bool nameEq = rhs.getName() != name_;
        bool spacesEq = rhs.getSpaces() != spaces_;
        bool weightEq = rhs.getWeight() != weight_;
        bool result = manuEq || nameEq || spacesEq || weightEq;
        return result;
    }

    void operator=(const Object &rhs) //overload the = operator to assign an object type to another object type
    {
        manufacturer_ = rhs.manufacturer_;
        name_ = rhs.name_;
        weight_ = rhs.weight_;
        spaces_ = rhs.spaces_;
    }

protected:
    std::string manufacturer_; //manufacturer of object/ tool
    std::string name_;         //name or model of the object/ tool
    size_t spaces_ = 1;        //how many spaces it occupies in the garage
    double weight_;            //how heavy it is
};

/****************************************************************************************************************************/
class GardenHose : public Object
{
public:
    //GardenHose Parameterized Constructor with an initializer list
    GardenHose(std::string name, std::string manufacturer, double weight, double pressure) : Object(name, manufacturer, weight), pressure_{pressure}
    {
    }

    double getPressure() const //returns pressure_
    {
        return pressure_;
    }

private:
    double pressure_; // measured in PSI
};

/****************************************************************************************************************************/
class Lawnmower : public Object
{
public:
    //Lawnmower Parameterized Contructor with an initializer list
    Lawnmower(std::string name, std::string manufacturer, double weight, double fuel) : Object(name, manufacturer, weight), fuel_{fuel}
    {
    }

    double getFuel() const //return fuel
    {
        return fuel_;
    }

private:
    double fuel_;
};

/****************************************************************************************************************************/
class Toolbox : public Object
{
public:
    //Toolbox Parameterized Constructor
    Toolbox(std::string name, std::string manufacturer, double weight, size_t tool_cap) : Object(name, manufacturer, weight), tool_cap_{tool_cap}, num_tools_{0}
    {
        tool_arr_ = new int[tool_cap_];
    }

    bool insertTool(const int tool) //checks if the toolbox isn't already full, then we insert toolbox at the end
    {
        if (!isFull())
        {
            tool_arr_[num_tools_] = tool;
            return true;
        }
        return false;
    }

    bool removeTool(const int tool) //removes tool, it finds the first instance of the tool by shifting every tool after to the left
    {
        for (int index = 0; index < num_tools_; index++)
        {
            if (tool_arr_[index] == tool)
            {
                for (int i = 1; i < num_tools_; i++)
                {
                    tool_arr_[index + i] = tool_arr_[index + i - 1];
                }
                return true;
            }
        }
        return false;
    }

    bool contains(const int tool) const //returns true if we find an instance of the tool in the array
    {
        for (int index = 0; index < num_tools_; index++)
        {
            if (tool_arr_[index] == tool)
            {
                return true;
            }
        }
        return false;
    }

    size_t getAmount() const //returns total number of tools
    {
        return num_tools_;
    }

    size_t getSize() const //returns your toolbox capacity
    {
        return tool_cap_;
    }

    bool isFull() const //checks if the toolbox is full
    {
        if (num_tools_ == tool_cap_)
            return true;
        return false;
    }

    bool isEmpty() const //checks if toolbox is empty
    {
        if (num_tools_ == 0)
        {
            return true;
        }
        return false;
    }

    void clear() //removes all the tools
    {
        if (isEmpty())
        {
            num_tools_ = 0;
        }
        else
        {
            delete[] tool_arr_;
            num_tools_ = 0;
        }
    }

    void display() //displays all items in the toolbox
    {
        for (int index = 0; index < num_tools_; index++)
        {
            std::cout << getTool(tool_arr_[index]);

            if (index == num_tools_ - 1)
            {
                std::cout << "\n";
                return;
            }

            std::cout << ", ";
        }
        return;
    }

private:
    std::string getTool(const int &tool) //we got lazy and didnt want to make tool objects so your integers represent tools, have fun
    {
        if (tool == 1)
        {
            return "Wrench";
        }
        else if (tool == 2)
        {
            return "Hammer";
        }
        else if (tool == 3)
        {
            return "Screwdriver";
        }
        else if (tool == 4)
        {
            return "Saw";
        }
        else
        {
            return "UnKnown"; // ;)
        }
    }

    int *tool_arr_;
    size_t tool_cap_;
    size_t num_tools_;
};

#endif
