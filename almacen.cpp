#include "almacen.h"

vector<Vehiculo> Almacen::getTotalCoches() const{

    return totalCoches;
}

void Almacen::setTotalCoches(const vector<Vehiculo> &value){
    totalCoches = value;
}

Almacen::Almacen()
{



}

void Almacen::nuevoVehiculo(Vehiculo c){

    this->totalCoches.push_back(c);

}



string Almacen::toString(){
    string ret;

    for(int i = 0; i < totalCoches.size();i++){
        ret.append(totalCoches[i].toString() + "\n");
    }

    return ret;
}
