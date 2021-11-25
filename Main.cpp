#include <iostream>
#include <vector>
#include "Vehicle.h"
#include "Object.h"
#include "Garage.h"



int main()
{
    Car c("Civic", "Honda", 140.0, 2000.0, 55);

    Car mus("Mustang", "Ford", 200.0, 2000.0, 80);

    Bus b("XD60", "Xcelsior", 60.0, 8000.0, 30.0, 50);

    Car Tes("model x", "Tesla", 200.0, 2000.0, 80);

    Car BMW("beamer", "Bmw", 200.0, 2000.0, 80);

    GardenHose gh("Gardenhose", "lowes", 10.0, 5.0);

    Lawnmower lm("lawnmower", "depot", 30.0, 10.0);

    Garage<Vehicle> g;
    g.add(c);
    g.add(mus);
    g.add(BMW);
    //g.getFrequencyOf(c);

    Garage<Vehicle> a;
    a.add(b);
    a.add(BMW);
    cout << "Garage A : ----" << endl;
    a.display();
    cout << "Garage G: >>>>" << endl;
    g.display();

    g += a;
    cout << " after += " << endl;
    g.display();
    g -=a;
    cout << " after -= " << endl;
    g.display();
    cout << "Finished -= " << endl;
    g /= a;
    cout << " after /= " << endl;
    g.display();

    Garage<Object>h;
    h.add(gh);
    h.add(lm);

    return 0;
}
