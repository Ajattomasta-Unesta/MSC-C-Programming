/*
    Uxellos tou arduenna et bivos to brixtos
    Togosse can'iegis sitone uxamos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> //C99 CSP

#include "dataset.h"

dataset maindata[_ROW_LEN];
volatile int mainindex;

bool ls_op(char op[], char targ) { //cheking the options
    for(int i = 0; op[i] != NULL; i++) {
        if(op[i] == targ) return true;
    }
    return false;
}

bool ls_search(int index, char *argv) {
    
    if (argv == NULL) return true;

    char *tmp = malloc((1+4)+(_STR_LEN*3));
    sprintf(tmp, "%s %s %s %d", 
            maindata[index].name, 
            maindata[index].artist, 
            maindata[index].genre, 
            maindata[index].year);//Overall indexing

    if(strstr(tmp, argv) != NULL) return true; 
    else return false;
    
    return true;
}

int ls(char op[], char *argv) {
    int *order = (int*)malloc(sizeof(int)); //die tgum drukkende Ordernummer
    int size = 0;
    
    for(int i = 0; i < mainindex; i++) {
        if(ls_search(i, argv)) {
            order[size] = i;
            size++;
            order = (int*)realloc(order, sizeof(int)*size); //re-allocation to expend the array
        }
    }
    
    if (size == 0) {
        printf("No results");
        return false;
    } // if there's no argument -> COF

    if(ls_op(op, 'o')) { //Die „Alphabetische Sortierung“
        int temp;
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size-1; j++){
                if(strcmp(maindata[order[j]].name, maindata[order[j+1]].name) > 0){
                    temp = order[j];
                    order[j] = order[j + 1];
                    order[j + 1] = temp;
                }
            }
        }
    }
    
    //od ömkehren!!
    if(ls_op(op, 'r')) {
        int temp;
        for(int i = 0; i < size / 2; ++i) {
            temp = order[i];
            order[i] = order[size - 1 - i];
            order[size - 1 - i] = temp;
        }
    }
    
    for(int i = 0; i < size; i++) {
        int j = order[i];
        printf("%-5d", maindata[j].seq);
        printf("%-30s", maindata[j].name);
        
        if(ls_op(op, 'l')){ //allé!! od denn überspringen Sie de Anderen
            printf("%-30s", maindata[j].artist);
            printf("%-30s", maindata[j].genre);
            printf("%-5d", maindata[j].year);
            printf("%-2d", maindata[j].albumtyp);
            goto shAlp;
        }
        
        if(ls_op(op, 'a')) {
            printf("%-30s", maindata[j].artist);
        }
        
        if(ls_op(op, 'g')) {
            printf("%-30s", maindata[j].genre);
        }
        
        if(ls_op(op, 'y')) {
            printf("%-5d", maindata[j].year);
        }
        
        shAlp : //goto point
        
        printf("\n");
    }
    
    free(order);
    
    return 0;
}

int rm(char *argv) {
    int index = atoi(argv);
    memmove(maindata + index, maindata + index+1, mainindex+1 - index);
    return 0;
}

bool insertdata(dataset t) {
    t.seq = mainindex + 1;
    maindata[mainindex] = t;
    
    mainindex++;
    
    return true;
}

int insert() {
    dataset v;
    char tg[_STR_LEN] = {0,};
    
    printf("insert album name : ");
    scanf("%[^\n]", tg);
    getchar();
    strcpy(v.name, tg);
    memset(tg, 0x00, sizeof(tg));

    printf("insert artist name : ");
    scanf("%[^\n]", tg);
    getchar();
    strcpy(v.artist, tg);
    memset(tg, 0x00, sizeof(tg));
    
    printf("insert genre : ");
    scanf("%[^\n]", tg);
    getchar();
    strcpy(v.genre, tg);
    memset(tg, 0x00, sizeof(tg));
    
    printf("insert released year : ");
    scanf("%d", &v.year);
    getchar();
    
    printf("insert album type(1,2,3): ");
    scanf("%d", &v.albumtyp);
    getchar();
    
    return insertdata(v);
}
