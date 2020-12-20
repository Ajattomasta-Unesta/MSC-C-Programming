
#ifndef dtcontroller_h
#define dtcontroller_h

#include "dataset.h"
int init(void);
int putbinarray(dataset *tg, int arrindex);
int exportcsv(char* name);

#endif /* dtcontroller_h */
