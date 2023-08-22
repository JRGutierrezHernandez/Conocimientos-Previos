// Gutierrez Hernandez Jose Rafael

#include <iostream>
#include <string>

using namespace std;

struct CD
{
    int codigo;
    string artista;
    string album;
    int num_canciones;
    float precio;
    int existencias;
};

// Prototipos de funciones
void agregarCD(CD[], int&);
void mostrarCDs(CD[], int);
void buscarPorCodigo(CD[], int);
void modificarCD(CD[], int);
void realizarVenta(CD[], int);

int main()
{
    CD cds[50];
    int numCDs = 0;
    int opcion;

    while (true)
    {
        cout<<"\t *****[Menu CDs]*****"<<endl;
        cout<<""<<endl;
        cout<<"1. Agregar CD"<<endl;
        cout<<"2. Mostrar todos los CDs"<<endl;
        cout<<"3. Buscar por Codigo"<<endl;
        cout<<"4. Modificar"<<endl;
        cout<<"5. Realizar una venta"<<endl;
        cout<<"6. Salir"<<endl;

        cout<<"\n Seleccione una opcion: ";cin>>opcion;

        system("cls");

        switch (opcion)
        {
        case 1:
            agregarCD(cds, numCDs);
            break;
        case 2:
            mostrarCDs(cds, numCDs);
            break;
        case 3:
            buscarPorCodigo(cds, numCDs);
            break;
        case 4:
            modificarCD(cds, numCDs);
            break;
        case 5:
            realizarVenta(cds, numCDs);
            break;
        case 6:
            cout << "\n Saliendo del programa." << endl;
            return 0;
        default:
            cout<<"\n Opcion no valida. Por favor seleccione una opcion valida." << endl;
            cout<<""<<endl;
            break;
        }
    }

    return 0;
}

void agregarCD(CD cds[], int& numCDs)
{
    if(numCDs<50)
    {
        cout<<"\n Ingrese el codigo del CD: ";
        cin>>cds[numCDs].codigo;

        cout<<"\n Ingrese el nombre del artista: ";
        cin.ignore();
        getline(cin, cds[numCDs].artista);

        cout<<"\n Ingrese el nombre del album: ";
        getline(cin, cds[numCDs].album);

        cout<<"\n Ingrese el numero de canciones: ";
        cin>>cds[numCDs].num_canciones;

        cout<<"\n Ingrese el precio: ";
        cin>>cds[numCDs].precio;

        cout<<"\n Ingrese la cantidad de existencias: ";
        cin>>cds[numCDs].existencias;

        numCDs++;
        cout<<"\n CD agregado con exito."<<endl;
        cout<<"";
    }
    else
    {
        cout<<"\n El limite de CDs ha sido alcanzado. No se pueden agregar mas."<<endl;
    }
    cout<<"";
    system("pause");
    system("cls");
}

void mostrarCDs(CD cds[], int numCDs)
{
    if (numCDs == 0)
    {
        cout<<"\n No hay CDs para mostrar."<<endl;
        return;
    }

    cout<<" \t ------[Lista de CDs]-------"<<endl;
    cout<<"";

    for (int i = 0; i < numCDs; i++)
    {
        cout<<"Codigo: " << cds[i].codigo<<endl;
        cout<<"Artista: " << cds[i].artista<<endl;
        cout<<"Album: " << cds[i].album<<endl;
        cout<<"Numero de canciones: "<< cds[i].num_canciones <<endl;
        cout<<"Precio: "<< cds[i].precio <<endl;
        cout<<"Existencias: "<< cds[i].existencias <<endl;
        cout<<"---------------------------"<<endl;
    }

    system("pause");
    system("cls");
}

void buscarPorCodigo(CD cds[], int numCDs)
{
    int codigo;
    cout<<"\n Ingrese el codigo a buscar: ";cin>>codigo;
    cout<<"";
    system("cls");

    for(int i = 0; i < numCDs; i++)
    {
        if(cds[i].codigo == codigo)
        {
            cout<<" *** CD encontrado: "<<endl;
            cout<<"";
            cout<<"Codigo: "<< cds[i].codigo <<endl;
            cout<<"Artista: "<< cds[i].artista <<endl;
            cout<<"Album: "<< cds[i].album << endl;
            cout<<"Numero de canciones: " << cds[i].num_canciones <<endl;
            cout<<"Precio: "<< cds[i].precio <<endl;
            cout<<"Existencias: "<< cds[i].existencias <<endl;
            system("pause");
            system("cls");
            return;

        }

    }
    cout<<"\n CD no encontrado."<< endl;

    cout<<"";
    system("pause");
    system("cls");
}

void modificarCD(CD cds[], int numCDs)
{
    int codigo;
    cout<<" Ingrese el codigo del CD a modificar: "; cin>>codigo;
    cout<<"";
    system("cls");

    for(int i = 0; i < numCDs; i++)
    {
        if(cds[i].codigo == codigo)
        {
            cout<<"Ingrese el nuevo precio: ";
            cin>>cds[i].precio;

            cout<<"Ingrese la nueva cantidad de existencias: ";
            cin>>cds[i].existencias;

            cout<<"CD modificado con exito."<<endl;

            system("pause");
            system("cls");
            return;
        }
    }
    cout<<" CD no encontrado."<<endl;
    cout<<"\n";
    system("pause");
    system("cls");
}

void realizarVenta(CD cds[], int numCDs)
{
    int codigo, cantidad;
    cout<<"\n Ingrese el codigo del CD a vender: ";cin>>codigo;

    for(int i = 0; i < numCDs; i++)
    {
        if(cds[i].codigo == codigo)
        {
            cout<<"\n Ingrese la cantidad a vender: ";cin>>cantidad;

            if (cantidad <= cds[i].existencias)
            {
                cds[i].existencias -= cantidad;
                cout<<" Venta realizada con exito."<<endl;
                cout<<"";
                system("pause");
                system("cls");
                return;
            }
            else
            {
                cout<<" No hay suficientes existencias para realizar la venta."<<endl;
                cout<<"";
                system("pause");
                system("cls");
                return;
            }
        }
    }
    cout<<" CD no encontrado."<<endl;
    cout<<"";
    system("pause");
    system("cls");
}




