#include <iostream>
#include <cmath>
using namespace std;

// firstly, I made it suitable for given input in terminal
int main(){
    int number;
    cin >> number;
    cout << "sectigin sayi: " << number << endl;

    bool isprime = true;

    for (int i=2; i<= sqrt(number); i++){

        if (number % i == 0 ) isprime = false;
        
        if (number == 2 || number == 3) isprime = true;

    }
    if (isprime == true) cout << "prime " << endl;
    else  cout << "prime degil" << endl;
    
    return 0; // her sey yolunda, kodda bir hata yok
}



//The second method, create it as a function to use it anywhere.

bool isPrime(int n){
    bool isprime = true;
    for (int i=2; i<= sqrt(n); i++){

        if (n % i == 0 ) isprime = false;
        
        if (n == 2 || n == 3) isprime = true;

    }
    if (isprime == true) return true;
    else  return false;

}

