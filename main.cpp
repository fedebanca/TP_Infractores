#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define VACIO 0
#define TAM 1000
// Macro para detectar el sistema operativo ejecutando el programa
#ifdef __linux__
#define OS "linux"
#else
#define OS "noLinux"
#endif
/////////////////////
using namespace std;

struct Conductor
{
 int ConductorID;
 int Fechavencimiento;
 bool Activo;
 int Totalinfracciones;
 char email[50];
};

struct Infraccion{
    int infraccionID;
    char fechahora[14];
    float monto;
    int conductorID;
    int codProvicia;
};

void inicializar(Conductor cond1[]);
unsigned int tamVector(Conductor cond1[]);
void guardarConductor(Conductor cond1[]);
void cargarConductor(Conductor cond1[]);
void cargarArchivo(Conductor x[]);

int main(void){
    Conductor cond1[TAM];
    inicializar(cond1);
    unsigned int opcion = 0;
    char provincia[20];
    while(true){
        switch(opcion){
            case 0:
                if(OS == "linux"){
                    system("clear");    //Limpia la consola si el SO es GNU/Linux
                } else {
                    system("cls");      //Limpia la consola si el SO es Windows
                }
                cout << "[1] Comenzar jornada" << endl;
                cout << "[2] Ver infractores " << endl;
                cout << "[3] Cargar conductor" << endl;
                cout << "[4] Desactivar conductor" << endl;
                cout << "[5] Buscar conductor" << endl;
                cout << "[6] Procesar Lote de infractores" << endl;
                cout << "[7] Listar infracciones" << endl;
                cout << "[8] Listar conductores con infracciones por provicia" << endl;
                cout << "[9] Finalizar jornada" << endl;
                cout << "[10] Salir del programa" << endl;
                cout << endl << "SELECCIONE UNA DE LAS OPCIONES:    ";
                cin >> opcion;
                if(OS == "linux"){
                    system("clear");    //Limpia la consola si el SO es GNU/Linux
                } else {
                    system("cls");      //Limpia la consola si el SO es Windows
                }
                break;
            case 1:
                //comenzarJornada()
                opcion=0;
                break;
            case 2:
                //verInfractores()
                opcion=0;
                break;
            case 3:
                cargarConductor(cond1);
                opcion=0;
                break;
            case 4:
                //desactivarConductor()
                opcion=0;
                break;
            case 5:
                cout << "" << endl;
                cout << "" << endl;
                opcion=0;
                break;
            case 6:
                //procesarLote()
                opcion=0;
                break;
            case 7:
                //listarInfracciones()
                opcion=0;
                break;
            case 8:
                cout << "Provincia que desea ver:" << endl;
                cin.ignore();
                cin.getline(provincia, 20);
                //infraccionesXprovicia(provincia)
                opcion=0;
                break;
            case 9:
                //finalizarJornada()
                break;
            case 10:
                return 0;
                break;
            default:
                opcion = 0;
                break;
        }
    }
}

void inicializar(Conductor cond1[]){
    for(unsigned int i=0; i<TAM ; i++){
            cond1[i].ConductorID=VACIO;
        }
}
unsigned int tamVector(Conductor cond1[]){
    unsigned int i;
    for( i ; cond1[i].ConductorID!=VACIO ; i++ );
    return (i+1);
}

void guardarConductor(Conductor cond1[]){
    FILE*f;
    f=fopen("conductores.bin","wb");
    fwrite(cond1,sizeof(Conductor),1,f);
    fclose(f);
}

void cargarConductor(Conductor cond1[]){
    int i=tamVector(cond1);
    cout << "Ingrese el ID del conductor"<<endl;
    cin >> cond1[i].ConductorID;
    cout << "Ingrese la fecha de vencimiento de la licencia del conductor en formato AAAAMMDD"<<endl;
    cin >> cond1[i].Fechavencimiento;
    cout << "Ingrese 1 si el estado de el conductor es activo, de lo contrario ingrese 0"<<endl;
    cin >> cond1[i].Activo;
    cout << "Ingrese el Total de infracciones del conductor"<<endl;
    cin >> cond1[i].Totalinfracciones;
    cout << "Ingrese el mail del conductor"<<endl;
    cin >> cond1[i].email;
    guardarConductor(cond1);
}

void cargarArchivo(Conductor x[]){
    FILE*f;
    f=fopen("conductores.bin", "rb");
    fseek(f,0,SEEK_END);
    int tam=ftell(f)/sizeof(Conductor);
    fseek(f,0,SEEK_SET);
    fread(x,sizeof(Conductor),tam,f);
    fclose(f);
    cout << "El archivo ha sido cargado exitosamente" <<endl;
}

int InfraccionesXProvincia (select){
    FILE *f;
    int encontrados =0;
    bool IndiceConductores[TAM];
    int ind
    long int ic
    struct Infraccion in;
    if (f=fopen("procesados.bin" , "rb") == null)
        cout << "error al abrir el archivo de procesados" << endl;
    else
    {
        while (!feof(f))
        {
            fread(&in,sizeof(struct Infraccion),1,f);
         if (strcmp(select,in.codProvincia) == 0)
         {
             ind = ftell(procesados) / sizeof(struct Infraccion)
             encontrado = 1;
             IndiceConductores[ind] = true;
         }
         fclose(f)
   /*      if (f = fopen("Conductores.bin" , "rb") == null))
              cout << "error al abrir el archivo de conductores" << endl;
         else
         {
          for (ind = 0, i<TAM, ind++)
             if (IndiceConductores[ind] == true)
             {
                 ic = int * sizeof(struct conductor)
                 fseek(&in,ic,seek_set)
                 if (fread(&conductor,sizeof(conductor),1,f))
                     cout << "conductor:" f.ConductorID << endl;
        }   */
        if (!encontrados)
            cout << "No hay registros de infracciones en esta provincia";
         else 
         {
          if (f = fopen("Conductores.bin" , "rb") == null))
              cout << "error al abrir el archivo de conductores" << endl;
         else
         {
          for (ind = 0, i<TAM, ind++)
             if (IndiceConductores[ind] == true)
             {
                 ic = int * sizeof(struct conductor)
                 fseek(&in,ic,seek_set)
                 if (fread(&conductor,sizeof(conductor),1,f))
                     cout << "conductor:" f.ConductorID << endl;
        } 
         }
        fclose(f)
         return 1;
    }
    return 0;
}

int CrearLote()
{
    char num[2];
    char resp[1];
    cout << "ingrese el numero del lote que quiere crear" << endl;
    cin >> num;
    FILE *f;
    struct Infraccion in;
    f = fopen("lote.bin","wb");
    if (!f)
        cout << "error al crear el lote." << endl;
    else
    {
        do
        {
        cout << "desea ingresar una infraccion? S/N"<< endl;
        cin >> resp;
        if (resp == "s" || resp == "S")
        {
            cout<<"ingrese la id de la infracción"<< endl;
            cin >> in.infraccionID;
            cout<<"ingrese la fecha y hora de la infracción (use el formato AAAAMMDDHH:MM)"<<endl;
            cin >> in.fechahora;
            cout << "ingrese el monto de la infracción"<<endl;
            cin >> in.monto;
            cout << "ingrese el id del conductor"<< endl;
            cin >> in.conductorID;
            cout << "ingrese el codigo de la provincia" << endl;
            cin >> in.codProvicia;
            fwrite(&in , sizeof(in) ,1 , f);
            limpiar();
        }
        }
        while (resp != "n" || resp != "N");
        fclose(f);
    }


    return 0;
}

int ProcesarLote()
{ 
    /*Puse muchos comentarios porque no se como vas a llamar definitivamente al vector de conductores*/
    int i = 0;
    FILE *L;
    /*numero de lote (NL)*/
    char NL[20];
    cout << "Ingrese el nombre del lote que quiere procesar"<< endl;
    cin >> NL;
    L = fopen(NL,"rb");
    struct Infraccion in;
    if(!L)
        cout <<"error al abrir el lote" << endl;
    else{
        while(!feof(L))
        {
            fread(&in,sizeof(struct Infraccion),1,L);
            /* usar el subprograma de fecha valida para validar la fecha de la instruccion*/
            while(strcmp(in.conductorID,/*campo de conductor en el vector de conductores*/) != 0 || i < TAM) /*o seroa el puntero para ubicarse en el vector de conductores*/
                i ++;
            if (i > TAM)
                    cout << "El conductor " << in.conductorID << "no esta registrado"  << endl;
            else
            {
                /*aumentar en uno el numero de infracciones del conductor*/
                fseek(/*archivo de procesados.bin*/, 0, SEEK_END) /*lo puse por si es necesario, si no hace falta borralo*/
                fwrite(&in, sizeof(struct Infraccion), 1, /*archivo de procesados.bin*/)
                cout << "la infraccion " << in.infraccionID << "se ha cargado correctamente" << endl;
            }
        }
    }
    /* aca abria que cerrar y/o eliminar el archivo del lote */

    return 0;
}
