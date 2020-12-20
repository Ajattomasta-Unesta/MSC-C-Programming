/*Il nostro cammino è appena iniziato
Ed ora il gruppo è stato formato
E suoneranno trombe - acclameranno il tuo nome
Il nome che non conoscerà mai il dolore!*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "dataset.h"

#define FILENAME "maindata.bin"

void getbinarray(void);

extern dataset maindata[_ROW_LEN];
extern volatile int mainindex;
bool filestatus = 0;

FILE *f;
int f_arrindex;

void getCurrentFilePref() {
    printf("_r : %d\n_w : %d\n_p : %d\n", f->_r, f->_w, f->_p);
    printf("flag : %d\nfile : %d\n", f->_flags, f->_file);
}

int init(void) {
    f = fopen(FILENAME, "a+");
    //printf("%d", f->_ur);
    
    if(f == NULL) return 1;
    else printf("\n");
    
    //getCurrentFilePref();
    fseek(f, 0, SEEK_SET);
        
    fread(&f_arrindex, sizeof(int), 1, f);
    mainindex = f_arrindex;
    getbinarray();
    
    fclose(f);
    return 0;
}

void getbinarray() {
    for (int i = 0; i < mainindex; i++)
        fread(&maindata[i], sizeof(dataset), 1, f);
}

int putbinarray(dataset *tg, int arrindex) {
    f = fopen(FILENAME, "r+");

    if(f == NULL) return 1;
    
    printf("%d", arrindex);
    
    fseek(f, 0, SEEK_SET);
    fwrite(&mainindex, sizeof(int), 1, f); 
    fwrite(maindata, sizeof(dataset), mainindex, f); 
    
    fclose(f);
    
    filestatus = 0;
    
    return 0;
}

int exportcsv(char* name) {
#pragma omp parallel
{
    f = fopen(strcat(name, ".csv"), "w");
    for (int i = 0; i < mainindex; i++) {
        fprintf(f, "%d,%s,%s,%s,%d,%d\n", maindata[i].seq, maindata[i].name, maindata[i].artist, maindata[i].genre, maindata[i].year, maindata[i].albumtyp);
    }
}    
    fclose(f);
    return 0;
}
