//#include <stdio.h>
//
//int main() {
//    char sNation[] = "NORTH KOREA";
//    const char* strNation = "NORTH KOREA";
//    
//    printf("sNation : %s \n", sNation);
//    printf("strNation : %s \n", strNation);
//    printf("sNation : %p \n", sNation);
//    printf("strNation : %p \n", strNation);
//    
//    sNation[1] = 'A';
//    printf("sNation : %s \n", sNation);
//    
//    strNation = "Pyeongyang";
//    printf("strNation : %s \n", strNation);
//    
//    printf("sNation : %p \n", sNation);
//    printf("strNation : %p \n", strNation);
//    
//    printf("*(strNation+1) : %c \n", *(strNation+1));
//    printf("(strNation+1) : %p \n", (strNation+1));
//    
//    /***/
//    char* const str = "Kim Il-Sung";
//    //str = "Kim Jung-Un"; -> è impossibile
//    
//    const char* strNation1 = "NORTH KOREA";
//    printf("strNation : %s \n", strNation1);
//    
//    for (int i = 0;; i++) {
//        if(strNation1[i] == '\0') break;
//        printf("strNation[%d] = %c\n", i, strNation1[i]);
//    }
//    
//    strNation1 = "APPLE";
//    printf("strNation : %s \n", strNation1);
//    
//    for (int i = 0;; i++) {
//        if(strNation1[i] == '\0') break;
//        printf("strNation[%d] = %c\n", i, strNation1[i]);
//    }
//    
//    return 0;
//}

//#include <stdio.h>
//
//int main() {
//    const char* strNation[] = {"GERMANIA", "ITALIA", "FRANCIA"};
//    for (int i = 0; i < 3; i++) {
//        printf("strNation[%d] = %s\n", i, strNation[i]);
//        printf("strNation[%d] = %p\n", i, strNation[i]);
//    }
//    
//    char sNation[][10] = {"GERMANIA", "ITALIA", "FRANCIA"};
//    for (int i = 0; i < 3; i++) {
//        printf("sNation[%d] = %s\n", i, sNation[i]);
//    }
//}

//#include <stdio.h>
//
//void swap(int, int);
//
//int main() {
//    int iv1 = 10, iv2 = 20;
//    printf("@ main - iv1 : %d, iv2 : %d \n", iv1, iv2);
//    swap(iv1, iv2); //call by value, non f-tto
//    printf("@ main after swap - iv1 : %d, iv2 : %d \n", iv1, iv2);
//    return 0;
//}
//
//void swap(int v1, int v2) {
//    printf("# before swap - iv1 : %d, iv2 : %d \n", v1, v2);
//    int tmp = v1;
//    v1 = v2;
//    v2 = tmp;
//    printf("# after swap - iv1 : %d, iv2 : %d \n", v1, v2);
//}

//#include <stdio.h>
//
//int swap(int, int);
//
//int main() {
//    int iv1 = 10, iv2 = 20, a;
//    printf("@ main - iv1 : %d, iv2 : %d \n", iv1, iv2);
//    printf("addr @ main - iv1 : %p, iv2 : %p \n", &iv1, &iv2);
//    
//    a = swap(iv1, iv2); //
//    
//    printf("@ main after swap - iv1 : %d, iv2 : %d \n", iv1, iv2);
//    printf("addr @ main after swap - iv1 : %p, iv2 : %p \n", &iv1, &iv2);
//    printf("a : %d\n", a);
//    
//    return 0;
//}
//
//int swap(int v1, int v2) {
//    printf("# before swap - iv1 : %d, iv2 : %d \n", v1, v2);
//    printf("# addr before swap - iv1 : %p, iv2 : %p \n", &v1, &v2);
//    
//    int tmp = v1;
//    v1 = v2;
//    v2 = tmp;
//    
//    printf("# after swap - iv1 : %d, iv2 : %d \n", v1, v2);
//    
//    return v1;
//}

//#include <stdio.h>
//
//void swap(int*, int*);
//
//int main() {
//    int iv1 = 10, iv2 = 20, a;
//    printf("@ main - iv1 : %d, iv2 : %d \n", iv1, iv2);
//    printf("addr @ main - iv1 : %p, iv2 : %p \n", &iv1, &iv2);
//    
//    swap(&iv1, &iv2);
//    
//    printf("@ main after swap - iv1 : %d, iv2 : %d \n", iv1, iv2);
//    printf("addr @ main after swap - iv1 : %p, iv2 : %p \n", &iv1, &iv2);
//    
//    return 0;
//}
//
//void swap(int *v1, int *v2) {
//    printf("# before swap - v1 : %d, v2 : %d \n", *v1, *v2);
//    printf("# addr before swap - v1 : %p, v2 : %p \n", v1, v2);
//    
//    //keeping reference
//    int tmp = *v1; //value
//    *v1 = *v2; //value - value
//    *v2 = tmp; //value - value
//    
//    printf("# after swap - v1 : %d, v2 : %d \n", *v1, *v2);
//}

//#include <stdio.h>
//void changeArray(int score[], int num);
//
//int main() {
//    int arr[5] = {90, 95, 80, 75, 70};
//    
//    for (int i = 0; i < 5; i++)
//        printf("arr[%d] = %d \n", i, arr[i]);
//    printf("l'indirizzo di arr = %p \n", arr);
//    
//    changeArray(arr, 5);
//    
//    for (int i = 0; i < 5; i++)
//        printf("arr[%d] = %d \n", i, arr[i]);
//    printf("l'indirizzo di arr = %p \n", arr);
//    
//    return 0;
//}
//
//void changeArray(int score[], int num) {
//    for (int i = 0; i < num; i++)
//        printf("score[%d] = %d \n", i, score[i]);
//    printf("l'indirizzo di score = %p \n", score);
//    
//    score[0] = 100;
//    score[1] = 200;
//    score[2] = 300;
//    score[3] = 400;
//    score[4] = 500;
//}

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//char* getName(void);
//
//int main() {
//    char name[10] = "Wurz";
//    strcpy(name, "Das");
//    printf("1 name : %s \n", name);
//    
//    const char* pname = "Wolff";
//    printf("2 pname : %s \n", pname);
//    pname = "Toto";
//    printf("3 pname : %s \n", pname);
//    
//    char name2[10];
//    strcpy(name2, getName());
//    printf("4 name2 : %s \n", name2);
//    
//    return 0;
//}
//
//char* getName() {
//    char* name1 = (char*)malloc(10);
//    //CHE CAZZO QUANTO STRONZA CHE BASTARDO NON FARE QUALCOSA
//    //QUESTO FOTTUTO FUNZIONA SOLO COME FOTTUTO "STACK" SU ALMENO QUESTO FOTTUTO SISTEMA GCC
//    printf("input : ");
//    scanf("%s", name1);
//    printf("name : %s\n", name1);
//    
//    return name1; 
//}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* addString(char* a, char* b);

int main() {

    char *strInput = (char*)malloc(10);
    char add[50];

    strcpy(strInput, "hello"); 
    printf("시작 문자열은 %s 입니다 \n", strInput);
    
    while (1) {
        printf("추가할 문자열을 입력하세요 : ");
        scanf("%s", add);
        
        if(!strcmp(add, "exit")) break;
        
        strcpy(strInput, addString(strInput, add)); 
        printf("연결 후 문자열은 %s 입니다 \n", strInput);
    }
}

char* addString(char* a, char *b) {
    a = (char*)realloc(a, sizeof(a)+1);
    strcat(a, b);   //문자열 a와 문자열 b를 연결한다. 
    return a;
}
