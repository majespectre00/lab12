#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double X[], int arrsize, double Y[]){
    double sum = 0;
    for(int i = 0;i<arrsize;i++){
        sum += X[i];
    }
    Y[0] = sum/arrsize;
    double sum2 = 0;
    for(int i = 0;i<arrsize;i++){
        sum2 += pow((X[i]-Y[0]),2);
    }
    Y[1] = sqrt(sum2/arrsize);
    double ggez = 1;
    for(int i = 0;i<arrsize;i++){
        ggez*=X[i];
    }
    Y[2] = pow(ggez,1.0/arrsize);
    double harm = 0;
    for(int i = 0;i<arrsize;i++){
        harm += 1.0/X[i];
    }
    Y[3] = arrsize/harm;
    double min = X[0], max = X[0];
     for(int i = 0;i<arrsize;i++){
         if(X[i]>max) max = X[i];
         if(X[i]<min) min = X[i];
     }
     Y[4] = max;
     Y[5] = min;
}