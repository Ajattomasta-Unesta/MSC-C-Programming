/*
    Höldum nú á feigðarinnar fund,
    þetta ferðalag er köllun vor og saga
    Vaskir menn á vígamóðri stund
    og Valhöll bíður okkar allra þá
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> //C99 CSP

#include "cstshell.h"
#include "dataset.h"

extern dataset maindata[];
extern volatile int mainindex;

void createDummy() {
    //============ DUMMY DATA ============
    dataset tmp;
    tmp.seq = 1;
    strcpy(tmp.name, "Vogguvisur Yggdrasils");
    strcpy(tmp.artist, "Skalmold");
    strcpy(tmp.genre, "Viking Metal");
    tmp.albumtyp = 1;
    tmp.year = 2018;
    maindata[0] = tmp;
    
    tmp.seq = 2;
    strcpy(tmp.name, "Power Plant");
    strcpy(tmp.artist, "Gamma Ray");
    strcpy(tmp.genre, "Heavy Metal");
    tmp.albumtyp = 1;
    tmp.year = 1999;
    maindata[1] = tmp;
    
    tmp.seq = 3;
    strcpy(tmp.name, "The Eighth Mountain");
    strcpy(tmp.artist, "Rhapsody of Fire");
    strcpy(tmp.genre, "Neoclassical Metal");
    tmp.albumtyp = 1;
    tmp.year = 2019;
    maindata[2] = tmp;
    
    tmp.seq = 4;
    strcpy(tmp.name, "Twilight of the Thunder God");
    strcpy(tmp.artist, "Amon Amarth");
    strcpy(tmp.genre, "Melodic Death Metal");
    tmp.albumtyp = 1;
    tmp.year = 2008;
    maindata[3] = tmp;

    mainindex = 4;
    //=====================================
}

int main(){
    mainindex = 0;
    
    createDummy();
    
    printf("===== Die Musikbibliothek =====\n");
    printf("The music library, with command line\n");
    
    //sopravviveranno!!
    char query[64];
    char query_cmd[10];
    char query_op[10];
    //char *query_argv = (char*)malloc(_STR_LEN);
    char query_argv[_STR_LEN];
    
    while (1) {
        query[0] = '\0'; //init
        memset(query_cmd, 0x00, sizeof(query_cmd));
        memset(query_op, 0x00, sizeof(query_op));
        memset(query_argv, 0x00, sizeof(query_argv));
        
        //command line startingpoint
        printf("> ");
        scanf("%[^\n]", query);
        getchar(); //removing buf
        
        //command tokenize
        char *div = strtok(query, " ");
        if(div != NULL){
            strcpy(query_cmd, div);
        
            //aft cmd
            div = strtok(NULL, " ");
        }
        
        //bool argvIndex = 0;
        
        while (div != NULL) {
            if (div[0] == '-') { //separazione opzione(i)
                for (int i = 1; !(div[i] == NULL); i++) 
                    query_op[i-1] = div[i];
                div = strtok(NULL, " ");
            }else{//separazione argomento(i)
                strcat(query_argv, div);
                div = strtok(NULL, " ");
                if(div != NULL) strcat(query_argv, " ");
            }
        }
        
        int _result = -1; //to check the state
        if(!strcmp("insert", query_cmd)) 
            _result = insert();
        else if(!strcmp("ls", query_cmd)) 
            _result = ls(query_op, query_argv);
        else if(!strcmp("rm", query_cmd)) 
            _result = rm(query_argv);
        else if(!strcmp("exit", query_cmd)) 
            break;
        
        if(_result == 0) { //vo de Rüf
            printf("(%s) completed.\n", query_cmd);
            _result = -1;
        }else printf("Wrong command\n");
    }
    
    
    return 0;
}

/*
int insert() {
    struct dataset v;
    char tg[_STR_LEN] = {0,};
    
    printf("insert album name : ");
    scanf("%[^\n]", tg);
    getchar();
    strcpy(v.name, tg);
    memset(tg, NULL, sizeof(tg));

    printf("insert artist name : ");
    scanf("%[^\n]", tg);
    getchar();
    strcpy(v.artist, tg);
    memset(tg, NULL, sizeof(tg));
    
    printf("insert genre : ");
    scanf("%[^\n]", tg);
    getchar();
    strcpy(v.genre, tg);
    memset(tg, NULL, sizeof(tg));
    
    printf("insert released year : ");
    scanf("%d", &v.year);
    getchar();
    
    printf("insert album type(1,2,3): ");
    scanf("%d", &v.albumtyp);
    getchar();
    
    v.seq = mainindex + 1;
    maindata[mainindex] = v;
    
    mainindex++;
    
    return 0;
}

int ls(char op[], char **argv) {
    int order[mainindex+1]; //die tgum drukkende Ordernummer
    for(int i = 0; i < mainindex; i++) order[i] = i;
    
    if(ls_op(op, 'o')) { //Die „Alphabetische Sortierung“
        int temp;
        for(int i = 0; i < mainindex; i++) {
            for(int j = 0; j < mainindex-1; j++){
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
        for(int i = 0; i < mainindex / 2; ++i) {
            temp = order[i];
            order[i] = order[mainindex - 1 - i];
            order[mainindex - 1 - i] = temp;
        }
    }
    
    for(int i = 0; i < mainindex; i++) {
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
    
    return 0;
}

bool ls_op(char op[], char targ) { //cheking the options
    for(int i = 0; !(op[i] == NULL); i++) {
        if(op[i] == targ) return true;
    }
    return false;
}*/
