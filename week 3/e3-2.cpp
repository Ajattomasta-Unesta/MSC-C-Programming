//n2
#include <stdio.h>

double weight_cv(double num, double weight);

int main() {
    int arr[][2] = {
        {30, 0}, {30, 0}, {10, 0}, {30, 0}
    };
    
    char *names[] = {"중간고사", "기말고사", "과제", "출석"}; //non adatto per ISO C++11
    
    double totale = 0.0;
    int i;
    
    for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        printf("%s 점수 입력 (100점 만점; %d%%) : ", names[i], arr[i][0]);
        scanf("%d", &arr[i][1]);
        totale += weight_cv(arr[i][1], arr[i][0]);
    }
    
    for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        printf("%s 점수 : %.2f\n", names[i], (float)arr[i][1]);
    }
    
    printf("최종 점수 : %.2lf\n", totale);
    
    return 0;
}

double weight_cv(double num, double weight) {
    num /= 100.0;
    return num * weight;
}
