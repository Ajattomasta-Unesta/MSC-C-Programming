

//
//void _func() {
//    int iAuto = 1;
//    static iStatic = 1;
//    printf("iAuto = %d / iStatic = %d\n", iAuto, iStatic);
//    iAuto++;
//    iStatic++;
//}
//
//int main() {
//    int iCount;
//    for (iCount = 1; iCount <= 10; iCount++) {
//        _func();
//    }
//    
//    return 0;
//}

//int main() {
//    int a[5] = {10, 20, 30, 40, 50};
//    int sum = 0;
//    int max = 0;
//    int min = 99;
//    
//    for (int i = 0; i < 5; i++) {
//        sum += a[i];
//        if (a[i] > max) max = a[i];
//        if (a[i] < min) min = a[i];
//    }
//    
//    printf("합계 : %d\n큰 값 : %d\n작은 값 : %d\n", sum, max, min);
//    
//    int b[2][5] = {{10, 20, 30, 40, 50}, {1, 2, 3, 4, 5}};
//    sum = 0;
//    max = 0;
//    min = 99;
//    
//    for (int i = 0; i < 2; i++) {
//        for (int j = 0; j < 5; j++) {
//            sum += b[i][j];
//            if (b[i][j] > max) max = b[i][j];
//            if (b[i][j] < min) min = b[i][j];
//        }
//    }
//    
//    printf("합계 : %d\n큰 값 : %d\n작은 값 : %d\n", sum, max, min);
//    
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>

int main() {
    int score[3] = {100, 70, 50};
    char name[20] = "Markus Winkelhock";
    char *name_ = (char*)malloc(sizeof(char*)*20);
    
    printf("name[0] = %c / name[10] = %c\n", name[0], name[10]);
    printf("name = %s\nSpacebar = %d\nNull = %d\n", name, ' ', NULL);
    
    scanf("%s", name);
    printf("name = %s\n", name);
    
    scanf("%s", name_);
    printf("name__ = %s\n", name_);
    
    free(name_);
    return 0;
}
