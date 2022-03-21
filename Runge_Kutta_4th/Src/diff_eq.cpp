#include "diff_eq.h"
#include <math.h>
//dx/dt = y
//dy/dt = u*(1-x^2)*y-x^2





int main(){

    double t;
    double dt;
    double TF;
    const int N = 2;
    const int M = 1;
    double X[N+1]; //state vector (index starts from 1)
    double U[N+1]; //input vector (index starts from 1)

    // RK4 constants
    double a1 = 0.166;
    double a23 = 0.333;
    double a4 = 0.166;
    
    //function approximators
    double K1, K2, K3, K4;
    double L1, L2, L3, L4;

    //initials conditions
    t = 0.0;
    dt = 0.01;
    TF = 150;
    X[1] = 0.01;
    X[2] = 0;

    ofstream fout ("sim.csv");
    if(!fout){
        cout << "\n error" << endl;
    }
    fout << scientific;
    fout.precision (8);

    fout << "%Time(s)" << "," << "X-Position (X[2])" << "," << "Y-Position (X[1])" << "," << "Input U" << "\n";

    while (t<TF){
        //input
        U[1] = sin(pow(t,0.2));

        //placeholders
        double t_2 = t+0.5*dt;
        double t_3 = t*dt;

        //at each time step, forward iterations

        K1 = dt*func1(X[1]);
        L1 = dt*func2(t,X[1],X[2],U[1]);

        K2 = dt*func1(X[1]+0.5*L1);
        L2 = dt*func2(t_2,X[1]+0.5*L1,X[2]+0.5*K1,U[1]);

        K3 = dt*func1(X[1]+0.5*L2);
        L3 = dt*func2(t_2,X[1]+0.5*L2,X[2]+0.5*K2,U[1]);

        K4 = dt*func1(X[1]+L3);
        L4 = dt*func2(t_3,X[1]+L3,X[2]+K3,U[1]);

        //update X-Position
        X[2] = X[2]+a1*(K1+K4)+a23*(K2+K3);
        //update y-Position
        X[1] = X[1]+a1*(L1+L4)+a23*(L2+L3);

        //Output
        fout << t << "," << X[2] << "," << X[1] << "," << U[1] << "\n";
        t+=dt;


    }
        cout << "X[111] = " << X[1] << endl;
        cout << "X[2] = " << X[2] << endl;
        cout << "t = " << t << endl;

        system("pause");
}