#include <iostream>
#include <fstream>
#include <windows.h> //para usar el cls


using namespace std;



int menu(){
    int opc;
    system("cls");
		cout<<"\n\n";
		cout << "\t\t       ======  The STUDIO 54   ======";
        cout <<"\n\n               ";
        cout << "\t\t      The Night Magic  ";
        cout <<"\n\n               ";
        cout << "       ====  ""Sistema de Reservas"" ====";
        cout << "\n\n";
        cout << "\n\t\t          =============  ===    ===";
        cout << "\n\t\t          =============  ===    ===";
        cout << "\n\t\t          ======         ===    ===";
        cout << "\n\t\t          =============  ==========";
        cout << "\n\t\t          =============        ====";
        cout << "\n\t\t               ========        ====";
        cout << "\n\t\t          =============        ====";
        cout << "\n\t\t          =============        ====";
        cout <<"\n\n               ";
        cout <<"------------------------------------------- \n\n";
    cout<<" \t                     Menu Principal \n\n"<<endl;
    cout<<"\n ";
    cout<<"              1. Agregar Invitado "<<endl;
    cout<<"               2. Ver lista "<< endl;
    cout<<"               3. Buscar"<<endl;
    cout<<"               4. Editar datos personales y asistencia "<<endl;
    cout<<"               5. Borrar invitado "<<endl;
    cout<<"               6. SALIR "<<endl;
    cout<<"Opcion:";
    cin>>opc;
    return opc;

}
void agregarinvitados(ofstream &invitados)//ofstream para hacer el fichero en modo  escritura , &para indicar que recive un objeto por referencia,
                                         //invitados es el nombre del archivo dentreo de la funcion
    {
      system("cls");//limpio pantalla
      string nombre;
      string apellido;
      string edad;
      string asistencia;
      string nticket;
      cout<<"°============================================================================°\n"<<endl;
    cout<<"Registrar nuevo invitado  "<<endl;
    cout<<"----------------------------------------------------------------------------\n"<<endl;
                invitados.open("invitados.txt", ios::out | ios::app);//ios::out para para escribir en el archivo, ios::app para que se posicione en el ultimo caracter ingresado y no sobreescriba
                cout<<" Primer Nombre Invitado:  ";
                    cin>>nombre;
                cout<<" Apellido Invitado:  ";
                    cin>>apellido;
                cout<<" Edad Invitado: ";
                    cin>>edad;
                cout<<" Asistencia: ";
                    cin>>asistencia;
                cout<<" Numero Ticket: ";
                    cin>>nticket;
                    invitados<<nombre<<" "<<apellido<<" "<<edad<<" "<<asistencia<<" "<<nticket<<"\n";//guardo dentreo del archivo los datos ingresados en el mismo orden
     invitados.close();//cierro el txt para guardar los invitados cargados
}

void mostrarinvitados (ifstream &mostrar)//ifstream para fichero el archivo en modo lectura
    {
      system("cls");
      string nombre;
      string apellido;
      string edad;
      string asistencia;
      string nticket;
      cout<<"°============================================================================°\n"<<endl;
    cout<<"Datos de Invitados cargados  "<<endl;
    cout<<"----------------------------------------------------------------------------\n"<<endl;
     mostrar.open("invitados.txt", ios::in); //ios::in archivo een modo de lectura
     //poner personas registradas titulo
            if (mostrar.is_open())//si el archivo se abre con exito inicia el if
                {
                    mostrar>>nombre;//inicio la varible con un valor antes de inciar el while
                    while(!mostrar.eof()){//recorro el archivo mientras no llegue al final de este
                        mostrar>>apellido;
                        mostrar>>edad;
                        mostrar>>asistencia;
                        mostrar>>nticket;
                            cout<<"Nombre--------> "<<nombre<<endl;
                            cout<<"Apellido--------> "<<apellido<<endl;
                            cout<<"Edad--------> "<<edad<<endl;
                            cout<<"Asistencia--------> "<<asistencia<<endl;
                            cout<<"Numero ticket--------> "<<nticket<<endl;
                            cout<<"\n\n";
                        mostrar>>nombre;

         }
         mostrar.close();//cierro archivo
    }else
                            cout<<"error encontrando el archivo"<<endl;
     system("pause");

}

void buscarinvitado (ifstream &buscar)//ifstream para fichero el archivo en modo lectura
    {
        system("cls");
        buscar.open("invitados.txt", ios::in );//ios::in archivo een modo de lectura

            string nombre;
            string apellido;
            string edad;
            string asistencia;
            string nticket, nticketaux;
      cout<<"°============================================================================°\n"<<endl;
    cout<<"Buscador de invitados  "<<endl;
    cout<<"----------------------------------------------------------------------------\n"<<endl;
     bool ticketencontrado = FALSE;//si encuentro a la persona toma el valor true
     cout<<"Ingrese numero de ticket que desea buscar----> ";
     cin>>nticketaux;//ingreso numero para comparar con el guardado
     buscar>>nombre;//doy valor de inicio a la varibale
            while(!buscar.eof()&& !ticketencontrado){//recorre el archivo siempre hasta el final y que el numero que ingrese sea dif del guardado
                 buscar>>apellido;
                 buscar>>edad;
                 buscar>>asistencia;
                 buscar>>nticket;
                    if(nticket == nticketaux){
                        cout<<"Nombre--------> "<<nombre<<endl;
                        cout<<"Apellido--------> "<<apellido<<endl;
                        cout<<"Edad--------> "<<edad<<endl;
                        cout<<"Asistencia--------> "<<asistencia<<endl;
                        cout<<"Numero ticket--------> "<<nticket<<endl;
                        cout<<"\n\n";
                        ticketencontrado = true;

                 }

                    buscar>>nombre;//vuelvo a dar valor inicial

            }
         buscar.close();

         if (!ticketencontrado){
             cout<<"Ticket no encontrado "<<endl;
         }
         system("Pause");
}

void editardatos (ifstream &editar)
    {
                system("cls");
                  string nombre;
                  string apellido;
                  string edad;
                  string asistencia;
                  string nticket;
                  string nombreaux, apellidoaux,edadaux,asistaux,nticketaux;//variables aux para ingresar nuevos datos y reescribir los existentes

     editar.open("invitados.txt", ios::in);
     ofstream aux("editinvitados.txt", ios::out);//creo un txt nuevo para ingresar datos temporales y asi guardar los cambios

     if(editar.is_open()){
        cout<<"Ingrese numero de ticket que desea buscar ----> ";
        cin>>nticketaux;
        cout<<" ";
    cout<<"°============================================================================°\n"<<endl;
    cout<<" Editar Informacion de invitados  "<<endl;
    cout<<" ----------------------------------------------------------------------------\n"<<endl;
        editar>>nombre;

            while(!editar.eof()){
                    editar>>apellido;
                    editar>>edad;
                    editar>>asistencia;
                    editar>>nticket;
                       if(nticket == nticketaux){
                            cout<<"Nombre--------> "<<nombre<<endl;
                            cout<<"Apellido--------> "<<apellido<<endl;
                            cout<<"Edad--------> "<<edad<<endl;
                            cout<<"Asistencia--------> "<<asistencia<<endl;
                            cout<<"Numero ticket--------> "<<nticket<<endl;
                            cout<<"\n\n";
                            cout<<"------------------- \n\n";
                                cout<<"Reingrese nombre------> ";
                                cin>>nombreaux;
                                cout<<"Reingrese apellido------> ";
                                cin>>apellidoaux;
                                cout<<"Reingrese edad------> ";
                                cin>>edadaux;
                                cout<<"Edite asistencia ------> ";
                                cin>>asistaux;
                                    aux<<nombreaux<<" "<<apellidoaux<<" "<<edadaux<<" "<<asistaux<<" "<<nticket<<"\n";//guardo en el nuevo txt la correccion de datos

                        }
                        else{

                                    aux<<nombre<<" "<<apellido<<" "<<edad<<" "<<asistencia<<" "<<nticket<<"\n";//mantengo el el mismo txt los datos que ya existian
                        }

                    editar>>nombre;
            }
            editar.close();//cierro archivo original
            aux.close();//cierro archivo auxliar
            remove ("invitados.txt");//elimino el txt original
            rename ("editinvitados.txt","invitados.txt");//cambio el nombre del txt auxiliar  y le dejo el nombre del original
            system("pause");


     }
     else
     {

        cout<<"error"<<endl;

     }

}

void borrarinvitado(ifstream &borrar)
    {

    system("cls");
                  string nombre;
                  string apellido;
                  string edad;
                  string asistencia;
                  string nticket;
                  string nombreaux, apellidoaux,edadaux,asistaux,nticketaux;//variables aux para ingresar nuevos datos y reescribir los existentes

     borrar.open("invitados.txt", ios::in);
     ofstream aux("editinvitados.txt", ios::out);//creo un txt nuevo para ingresar datos temporales y asi guardar los cambios


     if(borrar.is_open()){
        cout<<"Ingrese numero de ticket que desea borrar ----> ";
        cin>>nticketaux;
        cout<<" ";
        cout<<"°============================================================================°\n"<<endl;
        cout<<" Informacion de invitado que esta siendo borrado  "<<endl;
        cout<<" ----------------------------------------------------------------------------\n"<<endl;
        borrar>>nombre;

            while(!borrar.eof()){
                    borrar>>apellido;
                    borrar>>edad;
                    borrar>>asistencia;
                    borrar>>nticket;
                       if(nticket == nticketaux)//si el numero que busco coinside con el guardado,  elimina toda la informacion de esa linea
                        {
                         cout<<"Nombre--------> "<<nombre<<endl;
                         cout<<"Apellido--------> "<<apellido<<endl;
                         cout<<"Edad--------> "<<edad<<endl;
                         cout<<"Asistencia--------> "<<asistencia<<endl;
                         cout<<"Numero ticket--------> "<<nticket<<endl;
                         cout<<"\n\n";
                         cout<<"------------------- \n\n";


                         cout<<"Invitado borrado..";

                        }
                        else
                        {
                        aux<<nombre<<" "<<apellido<<" "<<edad<<" "<<asistencia<<" "<<nticket<<"\n";//guardo en el nuevo txt los datos sin modificar
                        }

                    borrar>>nombre;
            }
            borrar.close();//cierro el archivo original
            aux.close();//cierro el archivo auxiliar
            remove ("invitados.txt");//elimino el archivo original
            rename ("editinvitados.txt","invitados.txt");//ronombro el archivo auxiliar con el nombre del original
            system("pause");


     }
     else
     {
     cout<<"error"<<endl;

     }

}




int main(){
//   \n
    ofstream escritura;
    ifstream mostrar,buscar,editar,borrar;
    int op;
       do{
              op= menu();
              switch(op){

                case 1:
                    agregarinvitados(escritura);
                break;

                case 2:
                    mostrarinvitados(mostrar);
                break;

                case 3:
                    buscarinvitado(buscar);
                break;


                case 4:
                    editardatos(editar);
                break;

                case 5:
                    borrarinvitado(borrar);
                break;
    }

    }while(op!= 6);

         cout<<"\n Programa finalizado ";


    return 0;
}
