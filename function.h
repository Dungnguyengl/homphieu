//funciton.h

#ifndef _FUNCTION_
#define _FUNCTION_

int *in(int &, int &);
void floyd_warshall(const int &n, int *arr);
int *getmin(const int *arr, int *&mark, const int &n);
void out(const int *, const int *, const int *, const int &, const int &);
int getSingleIndex(const int &row, const int &col, const int &ColOfArray);
int *progress(const int *arr, int *mark, const int &n, const int &k);

#endif //_FUNCTION_