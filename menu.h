#ifndef MENU_H
#define MENU_H
#include "Paqueteria.h"

class Menu
{
private:
    Paquete getPaquete();
public:
    Menu();
    void showMenu(Paqueteria<Paquete> &p);
};

#endif // MENU_H
