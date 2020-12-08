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
#include "dtcontroller.h"

extern dataset maindata[_ROW_LEN];
extern volatile int mainindex;

void createDummy();

int main(){
    init();
    mainindex = 0;
    
    printf("===== Die Musikbibliothek =====\n");
    printf("The music library, with command line\n");
    
    //sopravviveranno!!
    char query[64];
    char query_cmd[10];
    char query_op[10];
    //char *query_argv = (char*)malloc(_STR_LEN);
    char query_argv[_STR_LEN*3];
    
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
            _result = insert(query_argv);
        else if(!strcmp("ls", query_cmd)) 
            _result = ls(query_op, query_argv);
        else if(!strcmp("rm", query_cmd)) 
            _result = rm(query_op, query_argv);
        else if(!strcmp("update", query_cmd)) 
            _result = update(query_op, query_argv);
        else if(!strcmp("save", query_cmd)) 
            _result = save(maindata, mainindex);
        else if(!strcmp("exit", query_cmd)) 
            break;
        else if (!strcmp("dummy", query_cmd)){
            createDummy();
            _result = 0;
        }
        
        if(_result == 0) { //vo de Rüf
            printf("(%s) completed.\n", query_cmd);
            _result = -1;
        }else if(_result == 1) printf("Error!\n");
        else printf("Wrong command\n");
    }
    
    
    return 0;
}

void createDummy() {
    //============ DUMMY DATA ============
    dataset tmp;
    
    strcpy(tmp.name, "Vogguvisur Yggdrasils");
    strcpy(tmp.artist, "Skalmold");
    strcpy(tmp.genre, "Viking Metal");
    tmp.albumtyp = 1;
    tmp.year = 2018;
    insertdata(tmp);
    
    strcpy(tmp.name, "In the Minds of Evil");
    strcpy(tmp.artist, "Deicide");
    strcpy(tmp.genre, "Death Metal");
    tmp.albumtyp = 1;
    tmp.year = 2013;
    insertdata(tmp);
    
    strcpy(tmp.name, "Power Plant");
    strcpy(tmp.artist, "Gamma Ray");
    strcpy(tmp.genre, "Heavy Metal");
    tmp.albumtyp = 1;
    tmp.year = 1999;
    insertdata(tmp);
    
    strcpy(tmp.name, "Mooncult");
    strcpy(tmp.artist, "Silver Bullet");
    strcpy(tmp.genre, "Power Metal");
    tmp.albumtyp = 2;
    tmp.year = 2019;
    insertdata(tmp);
    
    strcpy(tmp.name, "Death to Jesus");
    strcpy(tmp.artist, "Deicide");
    strcpy(tmp.genre, "Death Metal");
    tmp.albumtyp = 3;
    tmp.year = 2006;
    insertdata(tmp);
    
    strcpy(tmp.name, "The Stench of Redemption");
    strcpy(tmp.artist, "Deicide");
    strcpy(tmp.genre, "Death Metal");
    tmp.albumtyp = 1;
    tmp.year = 2006;
    insertdata(tmp);
    
    strcpy(tmp.name, "Twilight of the Thunder God");
    strcpy(tmp.artist, "Amon Amarth");
    strcpy(tmp.genre, "Melodic Death Metal");
    tmp.albumtyp = 1;
    tmp.year = 2008;
    insertdata(tmp);
    //=====================================
}
