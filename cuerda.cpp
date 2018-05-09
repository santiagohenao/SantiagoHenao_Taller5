#include <SFML/Graphics.hpp>
#include <SFML/Keyboard.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <math.h>

using namespace std;

double T=40.;
double rho=10.;
double L=100.;
double tf=200.;

double dt=0.1; // Elección arbitraria

int main()
{
    double c = sqrt(T/rho); // velocidad de fase
    int n=1; // partición inicial
    while(L/n>c*dt){n++;}  // Si la partición es aún mayor que el límite inferior de dx, aumentar la partición

    double dx = L/(n-1); // Compensar el efecto de pasada del while restando uno

    double alpha = pow(c*dt/dx,2);

    double u[n]; // espacio
    double up[n]; // espacio de t-dt

    // Generación de condiciones iniciales
    for(int i=0;i<n;i++)
    {
        if(i*dx<=0.8*L)
        {
            u[i]=1.25*i*dx/L;
        }
        else
        {
            u[i]=5-5*i*dx/L;
        }
    }



    for(int i=0;i<n;i++)
    {
        up[i]=u[i];
    }

    // Primer paso según la condición de velocidad nula en el tiempo cero para todo x
    for(int i=1;i<n-1;i++)
    {
        u[i]+=alpha/2*(u[i+1]-2*u[i]+u[i-1]);
    }




    #include "window.hpp"

}
