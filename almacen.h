#ifndef ALMACEN_H
#define ALMACEN_H
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "vehiculo.h"

class Almacen
{

private:
    vector<Vehiculo> totalCoches;
public:
    Almacen();


    vector<Vehiculo> getTotalCoches() const;
    void setTotalCoches(const vector<Vehiculo> &value);
    void nuevoVehiculo(Vehiculo c);
    string toString();

};

#endif // ALMACEN_H
