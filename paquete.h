#ifndef PAQUETE_H
#define PAQUETE_H
#include <iostream>
using namespace std;

class Paquete
{
private:
    string id;
    string origen;
    string destino;
    float peso;

public:
    Paquete();

    string getId() const;
    void setId(string value);
    string getOrigen() const;
    void setOrigen(const string &value);
    string getDestino() const;
    void setDestino(const string &value);
    float getPeso() const;
    void setPeso(float value);

    string toString()const;

};

#endif // PAQUETE_H
