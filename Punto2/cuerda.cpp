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

double dt=0.02; // Elección arbitraria

int main()
{
    double c = sqrt(T/rho); // velocidad de fase
    int n=1; // partición inicial
    while(L/n>c*dt){n++;}  // Si la partición es aún mayor que el límite inferior de dx, aumentar la partición

    //n=500;

    n=n/3;

    double dx = L/(n); // Compensar el efecto de pasada del while restando uno

    double alpha = pow(c*dt/dx,2);

    double u[n]; // espacio presente
    double up[n]; // espacio de t-dt
    double uf[n]; // espacio futuro

    // Generación de condiciones iniciales
    for(int i=0;i<n;i++)
    {
        if(i*dx<=0.8*L)
        {
            up[i]=1.25*i*dx/L;
        }
        else
        {
            up[i]=5-5*i*dx/L;
        }
    }


    // Primer paso según la condición de velocidad nula en el tiempo cero para todo x
    for(int i=1;i<n-1;i++)
    {
        u[i]=up[i]+alpha/2*(up[i+1]-2*up[i]+up[i-1]);
    }

    // Primer cálculo del futuro
    for(int i=1;i<n-1;i++)
    {
        uf[i]=-up[i]+2*(1-alpha)*u[i]+alpha*(u[i+1]+u[i-1]);
    }


    for(int i=0;i<n;i++)
    {
        up[i]=u[i];
    }
    for(int i=0;i<n;i++)
    {
        u[i]=uf[i];
    }

    #include "window.hpp"

}
