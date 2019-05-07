#include <string.h> 
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) 
{ 
    char    abc[27]; 
    char    *ptr = abc; 
    strcpy(abc, "abcdefgxyz"); 
     /* 
     * What are the types and values of expressions: 
     * 
   
     * 1. abc 
     * 2. *abc 
     * 3. abc[2] 
     * 4. &abc[3] //&abc[3] = abc + 3*sizeof(char) 
     * 5. abc+4 
     * 6. *(abc+5) + 20000  //h  long long x = int * 1LL * int 
     * 7. abc[10] //'\0' 
     * 8. abc[12] //memset () 
     * 9. &ptr //char** 
     */ 
        cout << abc << endl; // abcdefgxyz
    cout << *abc << endl;//a
    cout << abc[2] << endl; // c
    cout << &abc[3] << endl; // defgxyz
    cout << abc + 1 << endl;//bcdefgxyz
    cout << *(abc+5) + 2000 << endl; // 
    cout << abc[10] << endl;
    
    cout << abc[12] << endl;
    cout << &ptr ;

     return 0; 
}