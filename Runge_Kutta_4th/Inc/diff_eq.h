

#include<iostream>
#include<string>
#include<cmath>
#include<fstream>

using namespace std;
//dx/dt = y > func1
double func1(double X1);
//dy/dt = u*(1-x^2)*y-x
double func2(double &t, double X1, double X2, double U1);

double func1(double X1){
    return X1;
}

double func2(double &t, double X1, double X2, double U1){
    double F2 = U1*(1-pow(X2,2))*X1 - X2;
    return F2;
}