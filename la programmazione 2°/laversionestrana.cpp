/*
    Höldum nú á feigðarinnar fund,
    þetta ferðalag er köllun vor og saga
    Vaskir menn á vígamóðri stund
    og Valhöll bíður okkar allra þá
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _STR_LEN  30 //maximum length -each column
#define _ROW_LEN  20 //maximum length -dt-record

struct dataset { //data object
    int seq;
    char name[_STR_LEN];
    char artist[_STR_LEN];
    char genre[_STR_LEN];
    int albumtyp;
    int year;
};

//int insert();
//int ls(char op[], char **argv);
bool ls_op(char op[], char targ);

struct dataset maindata[_ROW_LEN];
volatile int mainindex = 0;

int main(){

    //============ DUMMY DATA ============
    struct dataset tmp;
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
    //========================
    
    printf("===== Die Musikbibliothek =====\n");
    printf("The music library, with command line\n");
    
    char query[64];
    char query_cmd[10];
    char query_op[10];
    char **query_argv;
    
    while (1) {
        query[0] = '\0'; //init
        memset(query_cmd, NULL, sizeof(query_cmd));
        memset(query_op, NULL, sizeof(query_op));
        
        //prototype -FFTA
        query_argv = (char**)malloc(sizeof(char*)*3);
        
        //command line startingpoint
        printf("> ");
        scanf("%[^\n]", query);
        getchar(); //removing buf
        
        //command tokenize
        char *div = strtok(query, " ");
        strcpy(query_cmd, div);
        
        //aft cmd
        div = strtok(NULL, " ");
        
        int argvIndex = 0;
        
        while (div != NULL) 
        {
            if (div[0] == '-') { //separazione opzione(i)
                for (int i = 1; !(div[i] == NULL); i++) 
                    query_op[i-1] = div[i];
            }else { //separazione argomento(i)
                query_argv[argvIndex] = (char*)malloc(_STR_LEN);
                strcpy(query_argv[argvIndex], div);
                argvIndex++;
            }
            div = strtok(NULL, " ");
        }
        
        int _result = -1; //to check the state
        
        if(!strcmp("insert", query_cmd)) {
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
            
            _result = 0;
        }
        
        else if(!strcmp("ls", query_cmd)) {
            int order[mainindex+1]; //die tgum drukkende Ordernummer
            for(int i = 0; i < mainindex; i++) order[i] = i;
            
            if(ls_op(query_op, 'o')) { //Die „Alphabetische Sortierung“
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
            if(ls_op(query_op, 'r')) {
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
                
                if(ls_op(query_op, 'l')){ //allé!! od denn überspringen Sie de Anderen
                    printf("%-30s", maindata[j].artist);
                    printf("%-30s", maindata[j].genre);
                    printf("%-5d", maindata[j].year);
                    printf("%-2d", maindata[j].albumtyp);
                    goto shAlp;
                }
                
                if(ls_op(query_op, 'a')) {
                    printf("%-30s", maindata[j].artist);
                }
                
                if(ls_op(query_op, 'g')) {
                    printf("%-30s", maindata[j].genre);
                }
                
                if(ls_op(query_op, 'y')) {
                    printf("%-5d", maindata[j].year);
                }
                
                shAlp : //goto point
                
                printf("\n");
            }
            _result = 0;
        }
        
        else if(!strcmp("exit", query_cmd)) 
            break;
        
        if(_result == 0) { //vo de Rüf
            printf("(%s) completed.\n", query_cmd);
            _result = -1;
        }
        
        //fight for the freedom
        free(query_argv);
    }
    
    return 0;
}

bool ls_op(char op[], char targ) { //cheking the options
    for(int i = 0; !(op[i] == NULL); i++) {
        if(op[i] == targ) return true;
    }
    return false;
}

/* int insert() {
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
} */

/*
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
 
 */


