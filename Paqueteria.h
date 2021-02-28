#ifndef PAQUETERIA_H
#define PAQUETERIA_H

#include <iostream>
#include "paquete.h"
#include <fstream>
using namespace std;

template <class T>
class Node
{
private:
    T data;
    Node *next;
public:
    Node();
    Node(const T &e);
    T getData() const;
    Node<T> *getNext()const;
    void setData(const T&);
    void setNext(Node *p);
};

template<class T>
Node<T>:: Node()
{
    next = nullptr;
}

template<class T>
Node<T>:: Node(const T &e)
{
    data = e;
    next = nullptr;
}

template<class T>
T Node<T>:: getData() const
{
    return data;
}

template<class T>
Node<T>* Node<T>:: getNext() const
{
    return next;
}

template<class T>
void Node<T>:: setData(const T &e)
{
    data = e;
}

template<class T>
void Node<T>:: setNext(Node *p)
{
    next = p;
}

template<class T>
class Paqueteria
{
private:
    Node<T> *anchor;
    bool isValidPos(Node<T>*)const;
//    void swapData(T&a, T&b);
    void swapData(Node<T>*a, Node<T>*b);
public:
    Node<T>* position;
    Paqueteria();
//    Paqueteria(const Paqueteria<T>&e);

    ~Paqueteria();

    bool isEmpty()const;
    void insertData(const T&);
    void deleteData(Node<T> *p);
    void respaldar();
    void recuperar();
    void orderByOrigen();
    void orderByWeight();

    Node<T>* getFirstPos() const;
    Node<T>* getLastPos() const;
    Node<T>* getPrevPos(Node<T> *p) const;
    Node<T>* getNextPos(Node<T> *p) const;
    Node<T>* findData(const T &e) const;

    string toString() const;
};


template<class T>
bool Paqueteria<T>::isValidPos(Node<T> *p) const
{
    Node<T>* aux(anchor);
    while(aux != nullptr){
        if(aux == p){
            return true;
        }
        aux = aux->getNext();
    }
    return false;
}

template<class T>
void Paqueteria<T>::swapData(Node<T> *a, Node<T> *b)
{
    Node<T> *aux(a);
    T dataaux = aux->getData();
    a->setData(b->getData());
    b->setData(dataaux);
}


template<class T>
Paqueteria<T>::Paqueteria()
{
    anchor = nullptr;
}

template<class T>
Paqueteria<T>::~Paqueteria()
{

}

template<class T>
bool Paqueteria<T>::isEmpty() const
{
    return anchor == nullptr;
}

template<class T>
void Paqueteria<T>::insertData(const T &e)
{
    Node<T>* aux(new Node<T>(e));
    aux->setNext(anchor);
    anchor = aux;
}

template<class T>
void Paqueteria<T>::deleteData(Node<T>* p)
{
    anchor = anchor->getNext();
    delete p;
}

template<class T>
void Paqueteria<T>::respaldar()
{
    ofstream fout("paquetes.txt");
    if(fout.is_open()){
        Node<T> *aux(anchor);
        while(aux!=nullptr){
            fout << aux->getData().getId() << endl;
            fout << aux->getData().getOrigen() << endl;
            fout << aux->getData().getDestino() << endl;
            fout << aux->getData().getPeso() << endl;
            aux = aux->getNext();
        }
    }
    fout.close();
}

template<class T>
void Paqueteria<T>::recuperar()
{
    ifstream fin("paquetes.txt");
    if(fin.is_open()){
        string linea;
        getline(fin, linea);
        while(!fin.eof()){
            Paquete p;
            p.setId(linea);
            getline(fin, linea);
            p.setOrigen(linea);
            getline(fin, linea);
            p.setDestino(linea);
            getline(fin, linea);
            p.setPeso(stof(linea));
            insertData(p);
            //Check this
            getline(fin, linea);
        }
    }
    fin.close();
}

template<class T>
void Paqueteria<T>::orderByOrigen()
{
    bool flag;
    do{
       flag = false;
       Node<T> *aux(anchor);
       Node<T> *next(aux->getNext());
       while(aux->getNext() != nullptr){
           if(aux->getData().getOrigen() > next->getData().getOrigen()){
               swapData(aux, next);
               flag = true;
           }
           aux = aux->getNext();
           next = aux->getNext();
       }

    }
    while(flag == true);
}

template<class T>
void Paqueteria<T>::orderByWeight()
{
    bool flag;
    do{
       flag = false;
       Node<T> *aux(anchor);
       Node<T> *next(aux->getNext());
       while(aux->getNext() != nullptr){
           if(aux->getData().getPeso() < next->getData().getPeso()){
               swapData(aux, next);
               flag = true;
           }
           aux = aux->getNext();
           next = aux->getNext();
       }

    }
    while(flag == true);
}

template<class T>
Node<T> *Paqueteria<T>::getFirstPos() const
{
    return anchor;
}

template<class T>
Node<T> *Paqueteria<T>::getLastPos() const
{
    if(isEmpty()){
        return nullptr;
    }
    Node<T> *aux(anchor);
    while(aux->getNext() != nullptr){
        aux = aux->getNext();
    }
    return aux;
}

template<class T>
string Paqueteria<T>::toString() const
{
    Node<T> *aux(anchor);
    string result = "";
    while(aux != nullptr){
        result+= aux->getData().toString() + "\n";
        aux = aux->getNext();
    }
    return result;
}

//Delete All

#endif // PAQUETERIA_H
