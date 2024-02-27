#include <stdio.h>      // Librería estándar de entrada y salida en C
#include <stdlib.h>     // Librería estándar de funciones de utilidad en C
#include <unistd.h>     // Librería estándar de funciones de sistema en POSIX (en este caso, getpid())
#include <string.h>     // Librería estándar de manipulación de cadenas en C
#include <iostream>     // Librería estándar de entrada y salida en C++
#include <iomanip>

 #include <iomanip> //sirve para formatos de salida
using namespace std;
#define CANDIDATOS 5
#define COLUMNAS 4
#define MAX_VOTOS 10000


//definimos funcion
void imprimirMatriz(float matriz[CANDIDATOS][COLUMNAS+1]);

//registros
//nombre matriz
struct P_REP{
    //columnas de la matriz
string nombre;
int V2017;
int V2019;
int V2021;
int V2023;
int VTOTALES;
};
//----------------------------------------------------------------------------
struct P_DEMO{
string nombre;
int V2017;
int V2019;
int V2021;
int V2023;
int VTOTALES;
};
//----------------------------------------------------------------------------
struct P_INDE{
string nombre;
int V2017;
int V2019;
int V2021;
int V2023;
int VTOTALES;
};
//----------------------------------------------------------------------------
int main()
{
    float matriz[CANDIDATOS][COLUMNAS+1];
    imprimirMatriz(matriz);
    return 0;
}
int busquedaAleatorios(int minimo, int maximo) {
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}
void imprimirMatriz(float matriz[CANDIDATOS][COLUMNAS+1]){
//do while
bool repetir=true;
char opcion;
P_REP p_rep[CANDIDATOS];
P_DEMO p_demo[CANDIDATOS];
P_INDE p_inde[CANDIDATOS];
//abrimos for para preguntar nombres de candidatos
do{
for(int i=0;i<CANDIDATOS;i++){
    cout<<"candidato N0 "<< i+1<<" de el partido Independiente  "<<endl;
//----------------------------------------------------------------------------
   cout<<"Nombre: ";
    cin>>p_inde[i].nombre;
    system("cls");
//----------------------------------------------------------------------------
//llenamos votaciones 2017 con ramdoms
p_inde[i].V2017=busquedaAleatorios(1,MAX_VOTOS);
//----------------------------------------------------------------------------
//llenamos votaciones 2019 con ramdoms
  p_inde[i].V2019=busquedaAleatorios(1,MAX_VOTOS);
//----------------------------------------------------------------------------
//llenamos votaciones 2017 con ramdoms
   p_inde[i].V2021=busquedaAleatorios(1,MAX_VOTOS);
//----------------------------------------------------------------------------
//llenamos votaciones 2017 con ramdoms
    p_inde[i].V2023=busquedaAleatorios(1,MAX_VOTOS);
//voto total P_INDEPENDIENTE
p_inde[i].VTOTALES=p_inde[i].V2017+p_inde[i].V2019+p_inde[i].V2021+ p_inde[i].V2023;

}
system("cls");
for(int i=0;i<CANDIDATOS;i++){
    cout<<"candidato N0 "<< i+1<<" de el partido Democrata  "<<endl;
//----------------------------------------------------------------------------
   cout<<"Nombre: ";
    cin>>p_demo[i].nombre;
    system("cls");
//----------------------------------------------------------------------------
//llenamos votaciones 2017 con ramdoms
p_demo[i].V2017=busquedaAleatorios(1,MAX_VOTOS);
//----------------------------------------------------------------------------
//llenamos votaciones 2017 con ramdoms
p_demo[i].V2019=busquedaAleatorios(1,MAX_VOTOS);
//----------------------------------------------------------------------------
//llenamos votaciones 2017 con ramdoms
p_demo[i].V2021=busquedaAleatorios(1,MAX_VOTOS);
//----------------------------------------------------------------------------
//llenamos votaciones 2017 con ramdoms
p_demo[i].V2023=busquedaAleatorios(1,MAX_VOTOS);
//voto total P_INDEPENDIENTE
p_demo[i].VTOTALES=p_demo[i].V2017+p_demo[i].V2019+p_demo[i].V2021+ p_demo[i].V2023;

}
//----------------------------------------------------------------------------//----------------------------------------------------------------------------
system("cls");
int votoM=0;
int votoM1=0;
int votoMe=100000000;
int votoMe1=10000000;
string candidato_Menor,candidato_Menor1;
string candidato_Mayor,candidato_Mayor1;
float promedio,promedio1=0;
int suma,suma1=0;

//----------------------------------------------------------------------------//----------------------------------------------------------------------------
for(int i=0;i< CANDIDATOS;i++){
//acumulador de votos
suma=suma+p_inde[i].VTOTALES;

//mayor votos//
//----------------------------------------------------------------------------//----------------------------------------------------------------------------
if(p_inde[i].VTOTALES>votoM){
votoM=p_inde[i].VTOTALES;
candidato_Mayor=p_inde[i].nombre;
}
//menor votos
//----------------------------------------------------------------------------//----------------------------------------------------------------------------
if (p_inde[i].VTOTALES<votoMe){
    votoMe=p_inde[i].VTOTALES;
    candidato_Menor=p_inde[i].nombre;
}

}
//promedio de votos
promedio=suma/CANDIDATOS;
//----------------------------------------------------------------------------//----------------------------------------------------------------------------
for (int i=0;i<CANDIDATOS;i++){
    suma1=suma1+p_demo[i].VTOTALES;
    //mayor votos
    if(p_demo[i].VTOTALES>votoM1){
votoM1=p_demo[i].VTOTALES;
candidato_Mayor1=p_demo[i].nombre;
}

if (p_demo[i].VTOTALES<votoMe1){
    votoMe1=p_demo[i].VTOTALES;
    candidato_Menor1=p_demo[i].nombre;
}
}
promedio1=suma1/CANDIDATOS;
//----------------------------------------------------------------------------//----------------------------------------------------------------------------
cout<<setw(10)<<"------PARTIDO INDEPENDIENTE-----"<<endl<<endl;
cout<<setw(9)<<"Nombre /"<<setw(9)<<"2017 /"<<setw(15)<<"2019/ "<< setw(9) << "2021 /" << setw(15) << "2023/" << setw(15) << "Votos Totales/" <<  endl<<endl;
  cout<<"------------------------------------------------------------------------------------------"<<endl;
    //for para imprimir los datos
    for(int i=0;i<CANDIDATOS;i++){
     cout<<setw(9)<<p_inde[i].nombre<<setw(9)<<p_inde[i].V2017<<setw(15)<<p_inde[i].V2019<< setw(9) << p_inde[i].V2021 << setw(15) << p_inde[i].V2023 << setw(15) <<p_inde[i].VTOTALES <<  endl<<endl;
    }
    cout<<"el candidato con mas votos es "<<candidato_Mayor <<" con "<< votoM<<" votos"<<endl<<endl;
    cout<<"el candidato con menor votos es "<<candidato_Menor <<" con "<<votoMe<<" votos"<<endl<<endl;
    cout<<"el promedio de votos en el partido Independiente es "<<promedio<<" votos"<<endl<<endl;


//----------------------------------------------------------------------------//----------------------------------------------------------------------------

cout<<setw(10)<<"------PARTIDO DEMOCRATA-----"<<endl<<endl;
cout<<setw(9)<<"Nombre "<<setw(9)<<"2017 "<<setw(15)<<"2019 "<< setw(9) << "2021 " << setw(15) << "2023" << setw(15) << "Votos Totales" <<  endl<<endl;
      cout<<"------------------------------------------------------------------------------------------"<<endl;

    //for para imprimir los datos
    for(int i=0;i<CANDIDATOS;i++){
     cout<<setw(9)<<p_demo[i].nombre<<setw(9)<<p_demo[i].V2017<<setw(15)<<p_demo[i].V2019<< setw(9) << p_demo[i].V2021 << setw(15) << p_demo[i].V2023 << setw(15) <<p_demo[i].VTOTALES <<  endl<<endl;
    }
    cout<<"el candidato con mas votos es "<<candidato_Mayor1<<" con "<< votoM1<<" votos"<<endl<<endl;
    cout<<"el candidato con menor votos es "<<candidato_Menor1 <<" con "<< votoMe1<<" votos"<<endl<<endl;
    cout<<"el promedio de votos en el partido Democrata es "<<promedio1<<" votos"<<endl<<endl;

     cout << "Desea otro calculo (s/n)? ";
        cin >> opcion;
        system("cls");
        if (opcion == 'n') {
            repetir = false;    // Si la opción es 'n', se termina el bucle
        }
    } while (repetir);
}


