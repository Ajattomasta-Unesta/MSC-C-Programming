//n3
#include <stdio.h>
#include <stdlib.h>

double weight_cv(double num, double weight);
const int _SOC_LIMIT = 20; // [State of Charge]h/w limit of the 2d array

int main() {
    int arr[] = {30, 30, 10, 30};
    const int _CTX_ARR_LEN = sizeof(arr)/sizeof(int);
    char *names[] = {"중간고사", "기말고사", "과제", "출석"}; 
    
    int glist[20][(sizeof(arr)/sizeof(int))+2] = {0,};
    char **gnames = (char**)malloc(sizeof(char*)*_SOC_LIMIT); //inputable string-array with malloc - serc.1
    
    int i, n = 0;
    for (;;n++) {
        double totale = 0.0;
        glist[n][0] = n+1;
        
        printf("이름 입력 : ");
        gnames[n] = (char*)malloc(_SOC_LIMIT);//inputable string-array with malloc - serc.2 per ogni fila
        scanf("%s", gnames[n]);
        
        for(i = 0; i < _CTX_ARR_LEN; i++) {
            printf("%s 점수 입력 (100점 만점; %d%%) : ", names[i], arr[i]);
            scanf("%d", &glist[n][i+1]);
            totale += weight_cv(glist[n][i+1], arr[i]);
        }
        
        glist[n][i+1] = (int)(totale*100);
        printf("최종 점수 : %.2lf\n", totale);
        
        printf("-------------------------------------\n");
        printf("성적 : \n %-20s %-5s ", "Name", "Seq.");
        for (int x = 0; x < sizeof(names)/8; x++) printf("%-5s ", names[x]);
        printf("%-5s \n", "총점");
        
        int j, k;
        for (j = 0; j < n+1; j++) {
            printf("%-20s ", gnames[j]);
            for (k = 0; k < (sizeof(glist[0])/sizeof(int))-1; k++) printf("%-5d ", glist[j][k]);
            printf("%-4.1f\n", (double)glist[j][k]/100);
        }getchar(); //removeing remain-string
        
        printf("계속하시겠습니까?(y/n) : ");
        char cont = getchar();
        
        if(!(cont == 'y' || cont == 'Y')) { //logical consistency - confuso!
            for(int v = 0; v < sizeof(**gnames); v++) free(gnames[v]);
            break;
        }
    }
    return 0;
}

double weight_cv(double num, double weight) {
    num /= 100.0;
    return num * weight;
}
