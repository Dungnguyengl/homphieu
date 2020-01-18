#include <iostream>
#include <fstream>

#include "function.h"
#include "const.h"

using namespace std;

int main()
{
    int n, k;
    int *arr = new int;
    arr = in(n, k);
    int *city = new int[k];
    int *mark = new int[n];
    city = progress(arr, mark, n, k);
    floyd_warshall(n, arr);
    out(arr, mark, city, n, k);
    return 0;
}

int getSingleIndex(const int &row, const int &col, const int &ColOfArray)
{
    return (row * ColOfArray) + col;
}

int *in(int &n, int &k)
{
    ifstream infile;
    infile.open("HOMPHIEU.IN");
    infile >> n;
    infile >> k;
    int *arr = new int[n * n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            infile >> arr[getSingleIndex(i, j, n)];
        }
    }
    infile.close();
    return arr;
}

void floyd_warshall(const int &n, int *arr)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[getSingleIndex(i, j, n)] == 0)
            {
                arr[getSingleIndex(i, j, n)] = INFINITY;
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arr[getSingleIndex(i, j, n)] = min(arr[getSingleIndex(i, j, n)], (arr[getSingleIndex(i, k, n)] + arr[getSingleIndex(k, j, n)]));
            }
        }
    }
}

int *getmin(const int *arr, int *&mark, const int &n)
{
    int maxcity = 0, maxleng = INFINITY;
    int *x = new int;
    for (int i = 0; i < n; i++)
    {
        int city = 0, leng = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[getSingleIndex(i, j, n)] != 0 && mark[j] == 0)
            {
                city++;
            }
            if (arr[getSingleIndex(i, j, n) < leng] && mark[j] == 0)
            {
                leng = arr[getSingleIndex(i, j, n)];
            }
        }
        if (leng < maxleng || (leng = maxleng && city > maxcity))
        {
            maxleng = leng;
            maxcity = city;
            *x = i;
        }
    }
    return x;
}

int *progress(const int *arr, int *mark, const int &n, const int &k)
{
    int *x = new int;
    int *city = new int[k];
    mark = {0};
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            x = getmin(arr, mark, n);
            city[i] = *x;
            mark[*x] = 1;
            for (int j = 0; j < n; j++)
            {
                if (arr[getSingleIndex(i, j, n)] > 0)
                {
                    mark[j] = 2;
                }
            }
        }
    }
    delete x;
    x = nullptr;
    return city;
}

void out(const int *arr, const int *mark, const int *city, const int &n, const int &k)
{
    int leng, maxleng = 0;
    for (int i = 0; i < n; i++)
    {
        if (mark[i] != 1)
        {
            leng = INFINITY;
            for (int j = 0; j < k; j++)
            {
                if (i != city[j] && arr[getSingleIndex(i, city[j], n)] < leng)
                {
                    leng = arr[getSingleIndex(i, city[j], n)];
                }
            }
            if (maxleng < leng && leng != INFINITY)
            {
                maxleng = leng;
            }
        }
    }
    ofstream outfile;
    outfile.open("HOMPHIEU.OUT");
    outfile << maxleng << endl;
    for (int i = 0; i < k; i++)
    {
        outfile << city[i] << " ";
    }
    outfile.close();
}