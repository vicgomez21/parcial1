#include <stdio.h>      // Librería estándar de entrada y salida en C
#include <stdlib.h>     // Librería estándar de funciones de utilidad en C
#include <unistd.h>     // Librería estándar de funciones de sistema en POSIX (en este caso, getpid())
#include <string.h>     // Librería estándar de manipulación de cadenas en C
#include <iostream>     // Librería estándar de entrada y salida en C++
#include <iomanip>

 #include <iomanip> //sirve para formatos de salida

 using namespace std;
#define MAX_EMPLEADOS 50
#define NUM_COLUMNAS 5
#define CADENA_TEXTO 100
#define MIN_SUELDO 3000
#define MIN_COMISIONES 500
#define MIN_INGRESO_EXTRA 500
//declaramos una funcion llamada imprimir matriz que tenga la matriz con las filas de MAXEMPLEADo
//y columnas de NUM COLUMNAS
void imprimirMatriz(float matriz[MAX_EMPLEADOS][NUM_COLUMNAS+1]);
int busquedaAleatorios(int minimo, int maximo);
//los registros
struct Empleado{
string nombre;
float sueldo;
float bonificaciones=250;
float comisiones;
float ingrsos_extra;
float horas_extra;
float total_ingresos ;
};

int main()
{
 float matriz[MAX_EMPLEADOS][NUM_COLUMNAS+1];
 imprimirMatriz(matriz);
    return 0;
}
int busquedaAleatorios(int minimo, int maximo) {
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void imprimirMatriz(float matriz[MAX_EMPLEADOS][NUM_COLUMNAS+1] ){
int N_empleados;
float HoraOrdinaria,Horaextra;
bool repetir=true;
char opcion;
//parte
//struc
Empleado empleados[MAX_EMPLEADOS];
do{

cout<<"ingrese la cantidad de empleados"<<endl;
cin>>N_empleados;


//for para preguntar todos los datos
for(int i=0;i< N_empleados;i++){
   //borrar pantalla "se ve mejor"

   //mostrar en pantalla empleado No 1 ,2,3 etc
   cout<<"Empleado No."<<i+1<<":"<<endl;
  //----------------------------------------------------------------------------
   //pregunta nombre de cada empleado
   cout<<"Nombre: ";
   //guarda nombre en la matriz empeados fila i,columna.nombre
   cin>> empleados[i].nombre;
 //----------------------------------------------------------------------------
   //llenamos sueldos con numeros ramdom
 empleados[i].sueldo = busquedaAleatorios(MIN_SUELDO, 5000);
//----------------------------------------------------------------------------
   // imprimira bonificaciones , no se agrega CIN por que bonificaciones no lo agrega el usuario
    cout<<"Bonificacion "<<empleados[i].bonificaciones<<endl;
//----------------------------------------------------------------------------

    //llenamos ingresos extra con numero aleatoriso
    empleados[i].ingrsos_extra=busquedaAleatorios(MIN_INGRESO_EXTRA,1000);
//----------------------------------------------------------------------------

   //llenamos comisiones con numero aleatoriso
    empleados[i].comisiones=busquedaAleatorios(MIN_COMISIONES,1000);
//----------------------------------------------------------------------------

    cout<<"ingrese la cantidad de horas extra: ";
   //lo guarda en la variable hora extra
    cin>>Horaextra;
    //sacamos el valor de Hordinaria
    HoraOrdinaria = (((empleados[i].sueldo/30)/8)*1.5);
    //vamos a guardar en fila i columna .horaextra la Hordinaria *horaextra
    empleados[i].horas_extra=HoraOrdinaria*Horaextra;
//----------------------------------------------------------------------------

    cout<<"el total de horas extra es igual a "  <<empleados[i].horas_extra<<endl<<endl;

    //calculo del total
    empleados[i].total_ingresos=empleados[i].sueldo+empleados[i].bonificaciones+empleados[i].ingrsos_extra+empleados[i].horas_extra;
}
system("cls");
//----------------------------------------------------------------------------
//for para ver cual es la persona con mayor sueldo

float sueldo=0;
string empleado_Mayor;



for(int i=0;i< N_empleados;i++){

if(empleados[i].total_ingresos>sueldo)
sueldo=empleados[i].total_ingresos;
empleado_Mayor=empleados[i].nombre;


}

//cerramos for y empezamos a imprimir la matriz
cout<<setw(9)<<"Nombre "<<setw(9)<<"sueldo "<<setw(15)<<"Bonificaciones "<< setw(9) << "Comisiones " << setw(15) << "ingresos Extra " << setw(15) << "Horas Extra" << setw(15) << " Total " << endl;
for(int i=0;i<N_empleados;i++){
    cout<<setw(9)<<empleados[i].nombre<<setw(9)<<empleados[i].sueldo<<setw(9)<<empleados[i].bonificaciones<<setw(15)<<empleados[i].comisiones<<setw(15)<<empleados[i].ingrsos_extra<<setw(15)<<empleados[i].horas_extra<<setw(15)<<empleados[i].total_ingresos<<endl<<endl;
}
cout<<"el empleado con mayor sueldo es "<<empleado_Mayor <<" con "<<sueldo<<endl<<endl;
cout << "Desea otro calculo (s/n)? ";
cin >> opcion;
system("cls");
        if (opcion == 'n') {
            repetir = false;    // Si la opción es 'n', se termina el bucle
        }
    } while (repetir);
      // El bucle se repite mientras repetir sea true
}
