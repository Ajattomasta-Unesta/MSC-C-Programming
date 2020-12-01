//
//
//==11-4==
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main() {
//    char str[30];
//    
//    printf("Input : ");
//    scanf("%s", str);
//    
//    for (int i = strlen(str); i >= 0; i--) printf("%c", str[i]);
//    printf("\n");
//    
//    return 0;
//}
//
//==11-5==
//#include <stdio.h>
//#include <string.h>
//
//int main() {
//    char str[30];
//    
//    printf("Input : ");
//    scanf("%s", str);
//    
//    for (int i = 0; i < strlen(str); i++) printf("%c", str[i]-32);
//    printf("\n");
//    
//    return 0;
//}
//
//==11-6==
//#include <stdio.h>
//
//int main() {
//    char str[30];
//    int cnt = 0;
//    
//    printf("Input : ");
//    scanf("%s", str);
//    
//    for (int i = 0;; i++) {
//        if (str[i] == '\0') break;
//        cnt++;
//    }
//    printf("len = %d\n", cnt);
//    
//    return 0;
//}
//
//==11-7==
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main() {
//    char str[30];
//    char tg[30];
//    int flag = 1;
//    
//    printf("Input Primo : ");
//    scanf("%[^\n]", str);
//    getchar();
//    printf("Input target : ");
//    scanf("%s", tg);
//    
//    for (int i = 0; i <= strlen(str)-strlen(tg); i++) {
//        for (int j = 0; j < strlen(tg); j++) {
//            if(tg[j] != str[j+i]) flag = 0;
//        }
//        if(flag) {
//            printf("%s는 포함되어 있음.\n", tg);
//            flag = -1;
//            break;
//        }
//        flag = 1;
//    }
//    
//    if(flag != -1) printf("%s는 포함되어 있지 아니하다.\n", tg);
//    
//    return 0;
//}
//
//==11-8==
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//int main() {
//    srand(time(NULL));
//    for (int i = 0; i < 6; i++) printf("%d\t", (rand() % 45) + 1);
//    return 0;
//}
//
//==12-7 e 12-8==
//#include <stdio.h>
//
//typedef struct _triangolo {
//    double height;
//    double base;
//} tri;
//
//int main() {
//    tri a;
//    
//    printf("높이 입력 : ");
//    scanf("%lf", &a.height);
//    
//    printf("밑변 입력 : ");
//    scanf("%lf", &a.base);
//    
//    printf("넓이 : %lf\n", (a.base * a.height)/2);
//    return 0;
//}
//
////==12-9==
//#include <stdio.h>
//
//enum color {
//    BLACK = 0,
//    WHITE,
//    BLUE
//};
//
//int main() {
//    enum color color1;
//    
//    printf("Select color [BLACK=0] [WHITE=1] [BLUE=2] : ");
//    scanf("%d", &color1);
//    switch (color1) {
//        case BLACK:
//            printf("BLACK을 선택하셨습니다. \n");
//            break;
//        
//        case WHITE:
//            printf("WHITE을 선택하셨습니다. \n");
//            break;
//            
//        case BLUE:
//            printf("BLUE을 선택하셨습니다. \n");
//            break;
//            
//        default:
//            printf("error\n");
//            break;
//    }
//    return 0;
//}
//
//
//==CCDC==

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
    char c;
    struct _node* t;
} node;

int main() {
    node* po[10];
    po[0] = malloc(sizeof(node));
    
    char *str = "xabcdefghi";
    
    for (int i = 1; i < 10; i++) {
        po[i] = malloc(sizeof(node));
        if ((i % 2) != 0) 
            po[i]->t = po[i-1];
        else
            po[i]->t = po[i-2];
        po[i]->c = str[i];
    }
    
    po[0]->t = po[1];
    
    int x;
    printf("Input X : ");
    scanf("%d", &x);
    
    node *cur = po[x]; 
    for (int i = 0; i < 10; i++) {
        printf("%c\n", cur->c);
        cur = cur->t;         
    }

    return 0;
}
