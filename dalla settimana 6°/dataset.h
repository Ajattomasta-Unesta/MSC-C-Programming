
#ifndef dataset_h
#define dataset_h

#define _STR_LEN  30 //maximum length -each column
#define _ROW_LEN  20 //maximum length -dt-record

typedef struct { //data object
    int seq;
    char name[_STR_LEN];
    char artist[_STR_LEN];
    char genre[_STR_LEN];
    int albumtyp;
    int year;
} dataset;

#endif /* dataset_h */
