#include <iostream>
#include <cmath>
using namespace std;



//                          FIRST QUESTION  
// Now write the function with the prototype bool isPrime(int n); to check if the input n is prime.
// firstly, I made it suitable for given input in terminal
/*
Consider the following approach to check if a number is prime:
• A prime number has no divisors except 1 and itself.
• It is enough to check divisors only up to √n.
• Use the cmath library and the sqrt() function.
*/

int is_prime(){
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





//              SECOND QUESTION

/*
Write a function with the prototype bool isSquare(int n); to check if an integer is a perfectsquare.
• Use sqrt() from cmath.
• Return true if the number is a square, otherwise false.
*/


bool isSquare(int n){

    int int_sqrt;
    int_sqrt = sqrt(n);

    // We used that print methods to check the output.
    //cout << sqrt(n) << endl;
    //cout << int_sqrt << endl;
    if (n < 0) return false;
    return (sqrt(n) == int_sqrt);

}

// Or you can directly check their multiplication is equal to the integer n or not.

bool isSquare2(int n){
    int sqrt_n = sqrt(n);
    if (n < 0) return false;
    return (sqrt_n * sqrt(n) == n);
}







//              THIRD QUESTION

/*
Write a function
    void checkWithFunction(int n, bool (*func)(int))that:

    • Receives an integer and a function pointer to a function of type bool(int).

    • Calls the function on the integer and writes
        o "The result is true" if the function returns true.
        o "The result is false" otherwise.

*/


void checkWithFunction(int n, bool (*func) (int)){

    std::cout << func(n) << endl;

}

int main(){
    int n = -2;
    std::cout << "is number square ? " << isSquare(n) << endl;
    std::cout << "is number square ? " << isSquare2(n) << endl;

    checkWithFunction(10, &isSquare);
    
    return 0;
}

