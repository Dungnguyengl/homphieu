//funciton.h

#ifndef _FUNCTION_
#define _FUNCTION_

#include "struct.h"

int getSingleIndex(const int &row, const int &col, const int &ColOfArray); //get address of array two-way;
int *in(int &n, int &k);                                                   //function to get value;
void floyd_warshall(const int &n, int *arr);                               //algorithm floyd warshall;
void getminleng(const int *arr, const int &k, const int &n, City *city);   //get value for city;
void out(const int &n, const int &k, const City *city);                    //export result;

#endif //_FUNCTION_