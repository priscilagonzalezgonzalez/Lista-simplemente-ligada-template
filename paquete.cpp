#include "paquete.h"

string Paquete::getId() const
{
    return id;
}

void Paquete::setId(string value)
{
    id = value;
}

string Paquete::getOrigen() const
{
    return origen;
}

void Paquete::setOrigen(const string &value)
{
    origen = value;
}

string Paquete::getDestino() const
{
    return destino;
}

void Paquete::setDestino(const string &value)
{
    destino = value;
}

float Paquete::getPeso() const
{
    return peso;
}

void Paquete::setPeso(float value)
{
    peso = value;
}

string Paquete::toString() const
{
    string result = "";
    result += "Id: " + id + "\n";
    result += "Origen: " + origen + "\n";
    result += "Destino: " + destino + "\n";
    result += "Peso: " + to_string(peso) + "\n";
    return result;
}

Paquete::Paquete()
{

}
