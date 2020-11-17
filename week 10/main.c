
//#include <stdio.h>
//
//int main() {
//    int ival[5] = {10, 20, 30, 40, 50};
//    int *pint = ival;
//    
//    printf("ival[0] : %d \n", ival[0]);
//    printf("&ival[0] : %p \n", &ival[0]); //head
//    printf("&ival[1] : %p \n", &ival[1]); //head + 4
//    printf("pint : %p \n", pint);
//    
//    pint++; //+4 perché int è 4byte
//    printf("pint : %p \n", pint);
//    
//    pint--; //-4
//    printf("pint : %p \n", pint);
//    
//    printf("ival : %p \n", ival);
//    printf("&ival : %p \n", &ival);
//    
//    pint = &ival[4];
//    int diff = pint - ival;
//    printf("diff : %d \n", diff);
//    return 0;
//}

//#include <stdio.h>
//
//int main() {
//    int a[5] = {10, 20, 30, 40, 50};
//    int *pint = a;
//    
//    printf("a[0] : %d \n", a[0]);
//    printf("&a[0] : %p \n", &a[0]); 
//    printf("pint : %p \n", pint);
//    printf("a : %p \n", a); //sono tutti uguali
//    
//    printf("&a[1] : %p \n", &a[1]); 
//    printf("pint + 1 : %p \n", pint + 1);
//    printf("a + 1 : %p \n", a + 1); //uguali
//    
//    printf("*&a[1] : %d \n", *&a[1]); 
//    printf("*(pint + 1) : %d \n", *(pint + 1));
//    printf("*(a + 1) : %d \n", *(a + 1)); //uguali
//    
//    printf("pint : %p \n", pint);
//    printf("*pint + 1 : %d \n", *pint + 1); 
//    //non è un riferimento di pointer.
//    
//    printf("++pint : %p \n", ++pint);
//    printf("*pint + 1 : %d \n", *pint + 1); 
//    printf("*(pint + 1) : %d \n", *(pint + 1)); 
//    
//    return 0;
//}

//#include <stdio.h>
//
//int main() {
//    int a[5] = {10, 20, 30, 40, 50};
//    int *pint = a;
//    
//    printf("pint address : %p \n", pint);
//    printf("*pint++ : %d \n", *pint++);
//    printf("pint address(after pint++) : %p \n", pint);
//    printf("*++pint : %d \n", *++pint);
//    printf("pint address(after ++pint) : %p \n", pint);
//    
//    return 0;
//}

//#include <stdio.h>
//
//int main() {
//    char a[6] = "hello";
//    char *pchar = a;
//    
//    printf("pchar address : %p \n", pchar);
//    printf("pchar+1 address : %p \n", pchar+1);
//    printf("a[0] : %c \n", a[0]); //string
//    printf("&a[0] : %p \n", &a[0]);
//    printf("string : %s \n", a); //by the head
//    
//    printf("string : %c \n", a[0]);
//    printf("string : %s \n", &a[0]); //address -> string
//    printf("string : %s \n", pchar); //pointer -> addr. -> string
//    printf("&a[0] : %p \n", &a[0]);
//    
//    printf("string : %s \n", pchar+1); //starts with [1]
//    printf("string : %c \n", *(pchar+1)); //char
//    
//    char name[20] = "Marc Marquez";
//    printf("%s \n", name[19]); //NULL
//    printf("%d \n", name[19]); //0
//    printf("%c \n", name[19]); //empty
//    printf("%d \n", name[4]); //32
//    printf("%d \n", name[7]);
//    printf("%c \n", name[7]);
//    printf("%d \n", name[8]);
//    
//    return 0;
//}

//#include <stdio.h>
//
//int main() {
//    int a[2][5] = {10, 20, 30, 40, 50};
//    
//    printf("&a[0][0] : %p \n", &a[0][0]);
//    printf("a[0] : %p \n", a[0]);
//    
//    printf("&a[1][0] : %p \n", &a[1][0]); //4*5
//    printf("a[1] : %p \n", a[1]); 
//    
//    return 0;
//}

#include <stdio.h>

int main() {
    int a1 = 10, a2 = 20, a3 = 30;
    int *pArr[3] = {&a1, &a2, &a3};
    
    for (int i = 0; i < 3; i++) {
        printf("pArr[%d] : %p \n", i, pArr[i]);
        printf("*pArr[%d] : %d \n", i, *pArr[i]); //doppelkonz(= *&a[n])
    }
    
    char n1[10] = "Böjrn";
    char n2[10] = "Útgaar";
    char n3[10] = "Thrrain";
    
    printf("addresso n1 : %p \n", n1);
    printf("addresso n2 : %p \n", n2);
    printf("addresso n3 : %p \n", n3);
    
    int *pArr2[3] = {n1, n2, n3};
    
    for (int i = 0; i < 3; i++) {
        printf("pArr2[%d] : %p \n", i, pArr2[i]);
        printf("pArr2[%d] : %s \n", i, pArr2[i]); //head pointer
        printf("*pArr2[%d] : %c \n", i, *pArr2[i]); //head
    }
    
    return 0;
}
