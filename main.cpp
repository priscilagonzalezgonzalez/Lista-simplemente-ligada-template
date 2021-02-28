#include "menu.h"
#include "Paqueteria.h"

int main()
{
    Menu menu;
    Paqueteria<Paquete> paqueteria;
    menu.showMenu(paqueteria);

    return 0;
}
