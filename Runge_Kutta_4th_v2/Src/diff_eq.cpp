#include "diff_eq_v2.h"
#include <math.h>
//dx/dt = y
//dy/dt = u*(1-x^2)*y-x^2





int main(){
    const int n = 4;
    const double A [4][4] = {{0, 0, 0, 0},{1, 0, 0, 0},{0, 1, 0, 0},{0, 0, 1, 0}};
    const double c [4] = {0, 1/2, 1/2, 1};
    const double b [4] = {1/6, 1/3, 1/3, 1/6};  

    double t;
    double dt;
    double TF;
    double error;
    const int N = 2;
    const int M = 1;
    double X[N+1]; //state vector (index starts from 1)
    double U[N+1]; //input vector (index starts from 1)
  
    //function approximators
    double K [4];
    double L [4];

    double s;

    //initials conditions
    t = 0.0;
    dt = 0.01;
    TF = 20;
    error = 10e-3;
    X[1] = 0;
    X[2] = 2;
    U[1] = 1;
/*  X[1] = 0;
    X[2] = 1; */
    ofstream fout ("sim.csv");
    if(!fout){
        cout << "\n error" << endl;
    }
    fout << scientific;
    fout.precision (8);

    fout << "Time(s)" << "," << "X-Position (X[2])" << "," << "Y-Position (X[1])" << "," << "Input U" << "\n";

    while (t<TF){
        //input
        //U[1] = sin(pow(t,0.2));
        //placeholders
        double t_2 = t+0.5*dt;
        double t_3 = t*dt;

        double s;
        


        //at each time step, forward iterations
        int i = 1;
        K[0] = dt*func1(t,X[1],X[2],U[1]);
        L[0] = dt*func2(t,X[1],X[2],U[1]);
        for (i;i<n;i++){
            K[i] = dt*func1(t+dt*c[i],X[1]+L[i-1],X[2]+K[i-1],U[1]);
        }

        //update X-Position
        X[2] = X[2]+b[0]*(K[0]+K[3])+b[1]*(K[1]+K[2]);
        //update y-Position
        X[1] = X[1]+b[0]*(L[0]+L[3])+b[1]*(L[1]+L[2]);

        //Output
        fout << t << "," << X[2] << "," << X[1] << "," << U[1] << "\n";
        t+=dt;


    }
        cout << "X[111] = " << X[1] << endl;
        cout << "X[2] = " << X[2] << endl;
        cout << "t = " << t << endl;


}