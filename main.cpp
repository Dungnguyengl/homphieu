#include <iostream>
#include <fstream>

#include "function.h"
#include "const.h"
#include "struct.h"

using namespace std;

int main()
{
    int *arr = new int;
    int n, k;
    arr = nullptr;
    arr = in(n, k);
    floyd_warshall(n, arr);
    City city[n];
    getminleng(arr, k, n, city);
    out(n, k, city);
    return 0;
}