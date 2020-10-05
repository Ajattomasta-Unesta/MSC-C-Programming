
#include <stdio.h>
#include <string.h>

char pw[20] = {0,};
bool ath();

int main() {
    int menu;
    volatile int mymoney = 1000000;
    int money_q;
    
    
    printf("==== Tschüß. ====\n1º 입금, 2º 출금, 3º 조회, 4º 비밀번호 설정, 5 종료\n");

gp1:
    printf("메뉴 입력 : ");
    scanf("%d", &menu);
    
    switch (menu) {
        case 1:
            printf("입금 메뉴입니다. \n 금액 입력 : ");
            scanf("%d", &money_q);
            mymoney += money_q;
            printf("잔액은 %d 원 입니다.", mymoney);
            break;
        
        case 2:
gp2: //======= start goto point =======
            printf("출금 메뉴입니다. \n ");
            ath();
            printf("출금 금액 입력 : ");
            scanf("%d", &money_q);
            
            if (money_q > mymoney) {
                printf("잔액 부족. 다시 출금하시겠습니까?(y/n) : ");
                getchar(); //removal
                char tmp = getchar();
                if ((tmp == 'y') || (tmp == 'Y')) goto gp2; //=== rollback to GP2 ===
                else break;
            }else mymoney -= money_q;
            printf("잔액은 %d 원 입니다. \n", mymoney);
            break;
            
        case 3:
            printf("조회 메뉴입니다. \n");
            ath();
            printf("잔액은 %d 원 입니다.", mymoney);
            break;
        
        case 4: 
            printf("Password 설정 메뉴입니다. \n Password 입력 : ");
            scanf("%s", pw);
            printf("설정 완료, ");
            break;
        
        case 5:
            printf("종료 화면입니다. \n");
            break;
            
        default:
            printf("잘못 입력하셨습니다. \n");
            goto gp1;
            break;
    }
    
    printf("거래를 계속하시겠습니까? (y/n) : ");
    getchar(); //removal
    char tmp = getchar();
    if ((tmp == 'y') || (tmp == 'Y')) goto gp1;
    else printf("===== Tschüß. =====\n");
    
    return 0;
}

bool ath() {
    if((char)pw[0] != NULL) {
        char tmp[20];
        while (1) {
            printf("input password : ");
            scanf("%s", tmp);
            if (strcmp(pw, tmp)) printf("잘못 입력 \n");
            else {
                printf("Authorized. \n");
                return true;
            }
        }
    }else return true;
    return false;
}
