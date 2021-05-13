#include "vehiculo.h"

Vehiculo::Vehiculo()
{

}
Vehiculo::Vehiculo(string nombre,int Ruedas,int caballos,  string combustible, string color, bool rueda,bool kit,bool burbuja,bool bocinas,bool portavasos,string matricula)
{
    setNombre(nombre);
    setRuedas(Ruedas);
    setCaballos(caballos);
    setCombustible(combustible);
    setColor(color);
    if (rueda) {
        setExtra("Rueda de repuesto");

    }else if (kit) {
        setExtra("kit reparacion de pinchazos");
    }

    setBurbuja(burbuja);
    setBocinas(bocinas);
    setPortavasos(portavasos);
    setMatricula(matricula);

}

string Vehiculo::getNombre() const
{
    return nombre;
}

void Vehiculo::setNombre(const string &value)
{
    nombre = value;
}

int Vehiculo::getRuedas() const
{
    return Ruedas;
}

void Vehiculo::setRuedas(int value)
{
    Ruedas = value;
}

int Vehiculo::getCaballos() const
{
    return caballos;
}

void Vehiculo::setCaballos(int value)
{
    caballos = value;
}

string Vehiculo::getCombustible() const
{
    return combustible;
}

void Vehiculo::setCombustible(const string &value)
{
    combustible = value;
}

string Vehiculo::getColor() const
{
    return color;
}

void Vehiculo::setColor(const string &value)
{
    color = value;
}

string Vehiculo::getExtra() const
{
    return extra;
}

void Vehiculo::setExtra(const string &value)
{
    extra = value;
}

bool Vehiculo::getBurbuja() const
{
    return burbuja;
}

void Vehiculo::setBurbuja(bool value)
{
    burbuja = value;
}

bool Vehiculo::getBocinas() const
{
    return bocina;
}

void Vehiculo::setBocinas(bool value)
{
    bocina = value;
}

bool Vehiculo::getPortavasos() const
{
    return portavasos;
}

void Vehiculo::setPortavasos(bool value)
{
    portavasos = value;
}

string Vehiculo::getMatricula() const
{
    return matricula;
}

void Vehiculo::setMatricula(const string &value)
{
    matricula = value;
}

string Vehiculo::getTipoVehiculo() const
{
    return tipovehiculo;
}

void Vehiculo::setTipoVehiculo(const string &value)
{
    tipovehiculo = value;
}
string Vehiculo::CalcularTipoVehiculo(){

    string salida;
    if (getRuedas()==2) {
        this->setTipoVehiculo("Moto");
        return "Moto";
    }
    if (getRuedas()==3) {
        this->setTipoVehiculo("Triciclo");
        return "Triciclo";
    }
    if (getRuedas()==4) {
        if (getBurbuja() && getBocinas()&&getPortavasos()) {
            this->setTipoVehiculo("Coche de Homer");
            return "Coche de Homer";
        }else{
        this->setTipoVehiculo("Coche");
        return "Coche";
        }
    }
    return "";
}
string Vehiculo::toString(){
    return getNombre()  + " "+ CalcularTipoVehiculo() + " " + getMatricula();
}


