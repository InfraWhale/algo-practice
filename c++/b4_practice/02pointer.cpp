#include<bits/stdc++.h>
using namespace std;
double a = 4.4;
int c = 10;
int main(){
    double *b = &a;
    int *d = &c;
    cout << b << '\n';
    cout << d << '\n';
    cout << sizeof(b) << '\n';
    cout << sizeof(d) << '\n';
}