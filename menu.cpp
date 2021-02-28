#include "menu.h"

Paquete Menu::getPaquete()
{
    Paquete p;
    string id, origen, destino;
    float peso;
    cout << "Id: ";
    getline(cin, id);
    p.setId(id);

    cout << "Origen: ";
    getline(cin, origen);
    p.setOrigen(origen);

    cout << "Destino: ";
    getline(cin, destino);
    p.setDestino(destino);

    cout << "Peso: ";
    cin >> peso; cin.ignore();
    p.setPeso(peso);

    return p;
}

Menu::Menu()
{

}

void Menu::showMenu(Paqueteria<Paquete> &p)
{
    while(true){
        string op;
        cout << endl;
        cout << "1) Agregar paquete"<<endl;
        cout << "2) Eliminar paquete"<<endl;
        cout << "3) Ordenar por origen"<<endl;
        cout << "4) Ordenar por peso"<<endl;
        cout << "5) Mostrar"<<endl;
        cout << "6) Guardar"<<endl;
        cout << "7) Recuperar"<<endl;
        cout << "8) Salir"<<endl;
        getline(cin, op);

        if(op == "1"){
            Paquete paquete = getPaquete();
            p.insertData(paquete);
        }
        else if(op == "2"){
            p.deleteData(p.getFirstPos());
        }
        else if(op == "3"){
            p.orderByOrigen();
        }
        else if(op == "4"){
            p.orderByWeight();
        }
        else if(op == "5"){
            string list = p.toString();
            cout << list;
        }
        else if(op == "6"){
            p.respaldar();
        }
        else if(op == "7"){
            p.recuperar();
        }
        else if(op == "8"){
            break;
        }
    }
}
