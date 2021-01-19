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


void stat(const double data[], int n, double res[]){
    double sum = 0;
    double geom = 1;
    double harmonicSum = 0;
    double sdSum = 0;
    double max;
    double min;

    for(int i = 0; i < n; ++i){
        sum += data[i];
        
        if (i == 0){
            max = data[i];
            min = data[i];
        }

        if (data[i] < min) min = data[i];
        if (data[i] > max) max = data[i];

        harmonicSum += (1.0/data[i]);
        geom *= data[i];
    }

    res[0] = sum / n;
    for (int j = 0; j < n; ++j){
        sdSum += pow(data[j] - res[0], 2);
    }

    res[1] = sqrt(sdSum / (n));
    res[2] = pow(geom, (1.0/n));
    res[3] = n / harmonicSum;
    res[4] = max;
    res[5] = min;
}