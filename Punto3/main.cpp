#include <SFML/Graphics.hpp>
#include <SFML/Keyboard.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <math.h>

using namespace std;

// constante de las ecuaciones y constante de paso
#define epsilon 10e-03
#define step 10e-4

// condiciones iniciales
double q1=sqrt(2.)/4.;
double q2=sqrt(2.)/4.;

double p1=0;
double p2=0;

double p1_dot=-1.9999;
double p2_dot= 1.9999;


// Método de Runge-Kutta de cuarto orden para una función general

double k1(double (*f)(double,double), double h, double tn, double yn)
{
    return h*f(tn,yn);
}

double k2(double (*f)(double,double), double h, double tn, double yn)
{
    return h*f(tn+h/2,yn+k1(f,h,tn,yn)/2);
}

double k3(double (*f)(double,double), double h, double tn, double yn)
{
    return h*f(tn+h/2,yn+k2(f,h,tn,yn)/2);
}

double k4(double (*f)(double,double), double h, double tn, double yn)
{
    return h*f(tn+h,yn+k3(f,h,tn,yn));
}

// Definición de las ecuaciones físicas del sistema

double p_dot(t_arg,y_arg)
{
    //
}



int main()
{
    return 0;
}
