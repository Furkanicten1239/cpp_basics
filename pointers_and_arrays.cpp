#include <iostream>

using namespace std;

int main(){
    int arr[7];
    int i;

    cout << "printing adress of the first element: " << &arr[0] << endl;
    // Insert values in arrray
    for(i=0; i<7; i++)
        arr[i] = i;

    // Print values in array
    for(i=0; i<7; i++)
        cout << arr[i] << " ";


    cout << endl;
    // Print addresses
    for(i=0; i<7; i++)
        cout<< &arr[i] << endl;

    cout << "printing arr, the adress of the first element: " << arr << endl; // Name of array is address of first element. If we add 1 to it, it will point to the next element.
    // Access values by dereferencing
    for(i=0; i<7; i++)
        cout << *(arr+i) << " "; //getting values from their corresponding adresses. * is doing it.
    cout << endl;


    // Pointer for first array element
    int *p = arr;
    // Print values using pointer increment
    for(i=0;i<7;i++){
        cout << *p << " ";
        p++;
    }
    cout << endl << endl;


    double d;
    cout << sizeof(d) << endl;
    double *pd;
    double *q = pd+3;
    cout << pd << " " << q << endl;


    return 0;
}
