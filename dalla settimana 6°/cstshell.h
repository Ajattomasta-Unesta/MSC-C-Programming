#ifndef cstshell_h
#define cstshell_h

#include "dataset.h"

int insert(void);
int ls(char op[], char *argv);
int rm(char *argv);

int insertdata(dataset t);
#endif
