#ifndef VEHICULO_H
#define VEHICULO_H

#include<iostream>

using namespace std;

class Vehiculo
{


private:
    string nombre,combustible,color,extra,matricula,tipovehiculo;
    bool burbuja,bocina,portavasos;
    int Ruedas,caballos;



public:
    Vehiculo();
    Vehiculo(string nombre,int Ruedas,int caballos,  string combustible, string color, bool rueda,bool kit,bool burbuja,bool bocinas,bool portavasos,string matricula);
    string CalcularTipoVehiculo();
    string toString();

    string getNombre() const;
    void setNombre(const string &value);
    int getRuedas() const;
    void setRuedas(int value);
    int getCaballos() const;
    void setCaballos(int value);
    string getCombustible() const;
    void setCombustible(const string &value);
    string getColor() const;
    void setColor(const string &value);
    string getExtra() const;
    void setExtra(const string &value);
    bool getBurbuja() const;
    void setBurbuja(bool value);
    bool getBocinas() const;
    void setBocinas(bool value);
    bool getPortavasos() const;
    void setPortavasos(bool value);
    string getMatricula() const;
    void setMatricula(const string &value);
    string getTipoVehiculo() const;
    void setTipoVehiculo(const string &value);
};

#endif // VEHICULO_H
