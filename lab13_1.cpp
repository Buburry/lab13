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

void stat(const double A[],int N,double B[6]){

    double sum,SD = 0.0,mean;
    for(int i=0; i<N; i++) sum =sum+ A[i];
    B[0] = sum/N;


    mean = sum/N;
    for (int i = 0; i < N; i++) {
        SD += pow(A[i] - mean, 2);
    }
    SD /= (N); 
    B[1] = sqrt(SD);    


    double geo=1.0;
    for (int i = 0; i < N; i++) {
        geo = geo*A[i];
    }
    B[2] = pow(geo,1.0/N);


    double sumInverse = 0.0;
    for (int i = 0; i < N; ++i) {
        sumInverse += 1.0 / A[i];
    }
    B[3] = N / sumInverse;

    double maxVal = A[0];
    for (int i = 1; i < N; ++i) {
        if (A[i] > maxVal) {
            maxVal = A[i]; 
        }
    }
    B[4] =  maxVal;


    double minVal = A[0];
       for (int i = 1; i < N; ++i) {
        if (A[i] < minVal) {
            minVal = A[i];
        }
    }

    B[5] =  minVal;
}

