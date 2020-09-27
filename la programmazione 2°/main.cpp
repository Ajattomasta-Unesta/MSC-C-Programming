
#include <stdio.h>
#define AND(A, B) A&&B
#define OR(A, B) A||B

void toBinary(int n); //per vedere le cifre in binario

int main() {
    int iV = 15, iR;
    
    iR = (0 <= iV <= 15); //not working as we could think - always true
    printf("iResult : %d\n", iR);
    
    iR = AND((iV >= 0), (iV <= 10));
    printf("iRes ult : %d\n", iR);

    iR = OR((iV >= 0), (iV <= 10));
    printf("iResult : %d\n", iR);
    
    iR = !iV;
    printf("iResult : %d\n", iR);
    
    int iV1 = 99;
    printf("%d\n", iV1);
    printf("%d\n", !iV1); //the opposite of value that except 0 is 0
    
    iV1 = !iV1;
    printf("%d\n", !iV1); //essere uno, la prima cosa di NOT
    
    iV = 0;
    iR = (iV > 0) && ++iV;
    printf("iValue = %d, iResult = %d\n", iV, iR);
    
    iR = (iV == 0) && ++iV; // <iV == 0> is true, ++iV is 1 = true(1)
    printf("iValue = %d, iResult = %d\n", iV, iR);
    
    iR = (iV > 0) || ++iV; //the operator won't continue to calculate the latter
    printf("iValue = %d, iResult = %d\n", iV, iR);
    
    iR = (iV == 0) || ++iV;
    printf("iValue = %d, iResult = %d\n", iV, iR);
    
    //Bitweiser operator
    toBinary(10);

    toBinary(3);
  
    toBinary(10 & 3); //UND

    toBinary(10 | 3); //ODER

    toBinary(10 ^ 3); //XOR
    
    toBinary(~10); //NICHT (Bitweise)
    toBinary(!10); //NICHT (Logisch) - es gibt einen großen Unterschied
    
    toBinary(10 >> 2);
    toBinary(10 << 3);
    
    //sizeof
    printf("sizeof(short) : %d\n", sizeof(short));
    printf("sizeof(int) : %d\n", sizeof(int));
    printf("sizeof(long long) : %d\n", sizeof(long long));
    printf("sizeof(doppel) : %d\n", sizeof(double));
    
    //ternary conditional operator
    printf("%d\n", (10 > 0) ? 1 : 2);
    
    int a, b, c;
    printf("두 수를 입력하세요 : ");
    scanf("%d%d", &a, &b);
    
    c = (a > b) ? a : b;
    printf("%d와 %d중 %d가 크다.\n", a, b, c);
    
    int mypass = 25;
    int def = 10;
    int result;
    
    printf("door has been closed\n");
    result = mypass ^ def;
    printf("current state is = %d\n", result);
    printf("arrived at home\n");
    
home :
    printf("input password : ");
    scanf("%d", &mypass);
    if(mypass == 25) result = result ^ mypass;
    else {
        printf("wrong password");
        goto home;
    }
    printf("current state is = %d\n", result);
    printf("door has been opened\n ");
    
    result = result ^ mypass;
    printf("current state is = %d\n", result);
    
    int value;
    printf("정수 입력 : ");
    scanf("%d", &value);
    
    if(value > 0) printf("0보다 큰 양수입니다\n");
    else if(value == 0) printf("0입니다\n");
    else printf("0보다 작은 음수입니다\n");
    
    int t = 1;
    printf("정수 입력 : ");
    scanf("%d", &value);
    for(int x = value; x >= 0; x--) t = t^1;
    printf("%s", (t == 1) ? "odd" : "even" );
    
    return 0;
}

void toBinary(int n) {
    for (int i = 7; i >= 0; --i) printf("%d", (n >> i) & 1);
    printf("\n");
}
