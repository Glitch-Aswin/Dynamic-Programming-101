#include <bits/stdc++.h>

using namespace std;

vector<double> fibo(100,-1);

double fib(int n){
    if(fibo[n]>0){
        return fibo[n];
    }
    if(n<=2){
        return 1;
    }

    fibo[n]= fib(n-1)+fib(n-2);

    return fibo[n];

}

int main() {
    fibo[0]=0;
    fibo[1]=1;
    fibo[2]=1;
    cout<<fib(9)<<endl;
    cout<<fib(30);
}