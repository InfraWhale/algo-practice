#include<bits/stdc++.h> // Æ÷ÀÎÅÍ 
using namespace std;

int main(){
    string a = "abcda";
    string *b = &a;

//    cout << a << "\n";
//    cout << &a << "\n";
//
//    cout << b << "\n";
//    cout << *b << "\n";




    cout << "a : " << a << "\n";
    cout << "&a : "  << &a << "\n";

    cout << "b : "  << b << "\n";
    cout << "*b : "  << *b << "\n";
    return 0;
}
