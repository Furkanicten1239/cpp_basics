
#define BLOCK 8

#if BLOCK == 1
#include <iostream>

using namespace std;
void swap(int a, int b){ // a ve b, i ve j'nin kopyalarıdır. Yani fonksiyon içinde yapılan değişiklikler orijinal i ve j'yi etkilemez.
    int temp;
    temp = a;
    cout << "temp: " << temp << endl;
    a = b;
    cout << "temp: " << temp << endl;
    b = temp;
    cout << "b inside of swap: " << b << endl;
    cout << "a inside of swap: " << a << endl;
}

int main(){
  int i = 10;
  int j = 20;
  cout << "Before swap(): i: "<<i<<" j: "<<j<<endl;
  swap(i,j);
  cout << "After swap(): i: "<<i<<" j: "<<j<<endl;
}
// Only local copies of i and j are swapped, original values remain unchanged. Thus, we need to use pointers or references to modify the original variables.
// This code demonstrates that the swap function does not affect the original variables i and j.
// Output:
// Before swap(): i: 10 j: 20
// After swap(): i: 10 j: 20



#elif BLOCK == 2

#include <iostream>

using namespace std;
void swap(int *a, int *b){
    int temp = *a; // Önce bu satır okundu için *a'nın değeri temp'e atanır. *a sonra değişse de temp etkilenmez.
    *a = *b;
    *b = temp;
}

int main(){
  int i = 10;
  int j = 20;
  cout << "Before swap(): i: "<<i<<" j: "<<j<<endl;
  swap(&i,&j);
  cout << "After swap(): i:  "<<i<<" j: "<<j<<endl;

  // Variable's value copy example
  int a= 8;
  int b= 15;
  int deneme;

  deneme = a;
  cout << "deneme: " << deneme << endl;
  a = b;
  cout << "deneme: " << deneme << endl;
  
}


#elif BLOCK == 3

#include <iostream>
using namespace std; // Bu kodda & işareti referans (takma ad) oluşturmak için kullanılır. Adres operatörü değildir!!!!
void swap(int &a, int &b){ // a = i'nin takma adı, b = j'nin takma adı
    int temp;
    temp = a; // temp = 10 (örneğin 0x100 adresindeki değer)
    a = b;  // 0x100 adresine 20 yaz → i = 20 oldu!
    b = temp;  // 0x104 adresine 10 yaz → j = 10 oldu!
}

int main(){
  int i = 10;
  int j = 20;
  cout << "Before swap(): i: "<<i<<" j: "<<j<<endl;
  swap(i,j);
  cout << "After swap(): i: "<<i<<" j: "<<j<<endl;

  // variable's reference example
  int a= 8;
  int &ref = a; // ref, a'nın takma adıdır. ref üzerinden a'ya erişilebilir ve değiştirilebilir.
  cout << "a: " << a << endl; // 8
  cout << "ref: " << ref << endl; // 8
  a = 15; // ref üzerinden a'nın değeri değiştirilir.
  cout << "a: " << a << endl; // 15
  cout << "ref: " << ref << endl; // 15
}


#elif BLOCK == 4

#include <iostream>

using namespace std;

// Helper function 
void printArray(int* start, unsigned int size){
 for(unsigned int i = 0; i < size; i++)
    cout << *(start+i) << " ";
 cout << endl << endl;
}

int main (){
    int i, *p;
    int numbers[6];
    p = numbers;
    for (i = 0; i < 6; i++)
        *(p+i)=i;
    
    printArray(numbers,6);
    p = &numbers[2];  *p = 29;
    printArray(numbers,6);
    p = numbers + 3;  *p = 17;
    printArray(numbers,6);
    p = numbers; *p = 21;
    printArray(numbers,6);
    p++;  *p = 32;
    printArray(numbers,6);
    p = numbers;  *(p+4) = 16;
    printArray(numbers,6);
}


#elif BLOCK == 5

#include <iostream>

using namespace std;

// Helper function to print values
void printValues(int *a, int *b, int c, int d){
  cout << "*a: " << *a << " *b: " << *b  << " c: " << c << " d: " << d << endl;
  cout << "a: " << a << " b: " << b << endl << endl;
}


int main(){
    int *a, c, d = 5;
    int *b = &d; //b pointerı d'nin adresini tutuyor
    c=2;
    a = &c; //a pointerı c'nin adresini tutuyor
    *a = d + 12; //a'nın adresindeki değeri d+12 yap (yani c=17 olur)
    printValues(a,b,c,d);
    a = b; //a pointerı artık b'nin tuttuğu adresi tutuyor (yani d'nin adresini)
    *b = *a + 5; //b'nin adresindeki değeri a'nın adresindeki değere 5 ekle (yani d=10 olur)
    printValues(a,b,c,d);
}

#elif BLOCK == 6

#include <iostream>

using namespace std;

void triple(double &num){
	num = 3*num;
}

int main(){
   double d = 10.0;
   triple(d);
   cout << "d: " << d << endl;
   return 0;
}


#elif BLOCK == 7

#include <iostream>

using namespace std;

void triple(double &num){
	num = 3*num;
}

int main(){
	double d = 10.0;
	triple(&d);
	cout << "d: " << d << endl;
	return 0;
}


#elif BLOCK == 8

#include <iostream>

using namespace std;

void triple(double *num){
	*num = 3**num; // num pointerının işaret ettiği adresin değerini 3 ile çarp
}

int main(){
	double d = 10.0;
	triple(&d); // d'nin adresi fonksiyona gönderilir
	cout << "d: " << d << endl;
	return 0;
}


#elif BLOCK == 9

#include <iostream>

using namespace std;

void triple(double num){
	num = 3*num;
}

int main(){
	double d = 10.0;
	triple(d);
	cout << "d: " << d << endl;
	return 0;
}

#endif