#ifndef cstshell_h
#define cstshell_h

#include "dataset.h"

int insert(char *argv);
int ls(char op[], char *argv);
int rm(char op[], char *argv);
int update(char op[], char *argv);

int insertdata(dataset t);

int save(dataset *tg, int arrindex);
#endif
