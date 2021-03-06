#include <SFML/Graphics.hpp>
#include <SFML/Keyboard.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <math.h>

using namespace std;

//constante de resolución temporal
double step=6*10e-4;

// constante de las ecuaciones, tiempo máximo
#define epsilon 0.8
#define t_max 3000

// condiciones iniciales
double q1=sqrt(2.)/4.;
double q2=-sqrt(2.)/4.;


double p1=0.;
double p2=0.;

double q1f;
double q2f;

double p1f;
double p2f;


// Método de Runge-Kutta de cuarto orden para una función general f

double k1(double (*f)(double,double,double), double h, double tn, double y1, double y2)
{
    return h*f(tn,y1,y2);
}

double k2(double (*f)(double,double,double), double h, double tn, double y1, double y2)
{
    return h*f(tn+h/2,  y1+k1(f,h,tn,y1,y2)/2  ,  y2+k1(f,h,tn,y1,y2)/2);
}

double k3(double (*f)(double,double,double), double h, double tn, double y1, double y2)
{
    return h*f(tn+h/2,  y1+k2(f,h,tn,y1,y2)/2  ,  y2+k2(f,h,tn,y1,y2)/2);
}

double k4(double (*f)(double,double,double), double h, double tn, double y1, double y2)
{
    return h*f(tn+h, y1+k3(f,h,tn,y1,y2)  ,  y2+k3(f,h,tn,y1,y2) );
}




// Definición de las ecuaciones físicas del sistema

double p1_dot(double tn, double y1, double y2)
{
    return (-2*y1)/pow(pow(epsilon,2) + 4*pow(y1,2),1.5);
}
double p2_dot(double tn, double y1, double y2)
{
    return (y1 - y2)/pow(pow(epsilon,2)/4. + pow(y1 - y2,2),1.5) -  (y1 + y2)/pow(pow(epsilon,2)/4. + pow(y1 + y2,2),1.5);
}
double q1_dot(double tn, double y1, double y2)
{
    return y1;
}
double q2_dot(double tn, double y1, double y2)
{
    return y2;
}


int main()
{
    // Runge-Kutta

    ofstream result("result.dat");

    int mu=0;

    for(double t=0.;t<t_max;t+=step)
    {
        //cout << t << "\t" << p1 << endl;
        q1f=q1+(k1(q1_dot,step,t,p1,p2)+2*k2(q1_dot,step,t,p1,p2)+2*k3(q1_dot,step,t,p1,p2)+k4(q1_dot,step,t,p1,p2))/6.;
        q2f=q2+(k1(q2_dot,step,t,p1,p2)+2*k2(q2_dot,step,t,p1,p2)+2*k3(q2_dot,step,t,p1,p2)+k4(q2_dot,step,t,p1,p2))/6.;

        p1f=p1+(k1(p1_dot,step,t,q1,q2)+2*k2(p1_dot,step,t,q1,q2)+2*k3(p1_dot,step,t,q1,q2)+k4(p1_dot,step,t,q1,q2))/6.;
        p2f=p2+(k1(p2_dot,step,t,q1,q2)+2*k2(p2_dot,step,t,q1,q2)+2*k3(p2_dot,step,t,q1,q2)+k4(p2_dot,step,t,q1,q2))/6.;

        // actualizar valores
        q1=q1f;q2=q2f;p1=p1f;p2=p2f;

        if(mu==10) // Exportar uno de cada diez datos.
        {
            result << t << "\t" << q1 << "\t" << q2 << "\t" << p1 << "\t" << p2 << endl;
            mu=0;
        }
        mu++;
    }



    return 0;
}
