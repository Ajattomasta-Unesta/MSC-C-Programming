////n1
//#include <stdio.h>
//
//double weight_cv(double num, double weight);
//
//int main() {
//    int exam1, exam2, asgm, attd = 0;
//    
//    printf("중간고사 점수 입력 (100점 만점; 30%%) : ");
//    scanf("%d", &exam1);
//    
//    printf("기말고사 점수 입력 (100점 만점; 30%%) : ");
//    scanf("%d", &exam2);
//    
//    printf("과제 점수 입력 (100점 만점; 10%%) : ");
//    scanf("%d", &asgm);
//    
//    printf("출석 점수 입력 (100점 만점; 30%%) : ");
//    scanf("%d", &attd);
//    
//    double totale = weight_cv(exam1, 30) + weight_cv(exam2, 30) + weight_cv(asgm, 10) + weight_cv(attd, 30);
//    
//    
//    printf("중간고사 점수 : %.2f\n", (float)exam1); //due to the condition of the task - needs to convert its own type
//    printf("기말고사 점수 : %.2f\n", (float)exam2);
//    printf("과제 점수 : %.2f\n", (float)asgm);
//    printf("출석 점수 : %.2f\n", (float)attd);
//    printf("최종 점수 : %.2lf\n", totale);
//    
//    return 0;
//}
//
//double weight_cv(double num, double weight) {
//    num /= 100.0;
//    return num * weight;
//}
