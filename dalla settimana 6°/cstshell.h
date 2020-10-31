#ifndef cstshell_h
#define cstshell_h

#include "dataset.h"

int insert(void);
bool insertdata(dataset t);
int ls(char op[], char *argv);
int rm(char *argv);

#endif
