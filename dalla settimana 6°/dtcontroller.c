#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "dataset.h"

#define PRAGMA_RW 7
#define FILENAME "test.txt"

void getbinarray(void);

//dataset maindata[_ROW_LEN];
//volatile int mainindex;

FILE *f;
int f_arrindex;

void getCurrentFilePref() {
    printf("_r : %d\n_w : %d\n", f->_r, f->_w);
    printf("flag : %d\nfile : %d\n", f->_flags, f->_file);
}

int init(void) {
    
    f = fopen(FILENAME, "a+");
    //printf("%d", f->_ur);
    
    if(f == NULL) return 1;
    else printf("\n");
    
    if(f->_r != 0) {
        fread(&f_arrindex, sizeof(int), 1, f);
        getbinarray();
    }
    
    return 0;
}

int putbinarray(dataset *tg, int arrindex) {
    fwrite(&arrindex, sizeof(int), 1, f); 
    fwrite(tg, sizeof(dataset), arrindex, f); 
    return 0;
}

/*dataset getbin() {
    
}*/

void getbinarray() {
    for (int i = 0; i < f_arrindex; i++) {
        //fread(<#void *restrict __ptr#>, <#size_t __size#>, <#size_t __nitems#>, <#FILE *restrict __stream#>)
    }
}

