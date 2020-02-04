//funciton.h

#ifndef _FUNCTION_
#define _FUNCTION_

#include "struct.h"
//get address of array two-way;
int getSingleIndex(const int &row, const int &col, const int &ColOfArray) 
{
    return (row * ColOfArray) + col;
}
//function to get value;
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
//algorithm floyd warshall;
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
//get value for city;
void getminleng(const int *arr, const int &k, const int &n, City *city)   
{

    int minl;      //value min of max leng of all city;
    int maxl;      //value max leng of city i;
    int maxltemp;  //value temp of maxl;
    int temp;      //value temp of city will be picked;
    int lengc;     //value number minest leng same;
    int lengctemp; //value temp of lengc;
    for (size_t x = 0; x < k; x++)
    {
        lengc = 0;
        temp = -1;
        minl = INFINITY;
        for (size_t i = 0; i < n; i++)
        {
            maxl = INFINITY;
            lengctemp = 0;
            if (!city[i].place)
            {
                maxltemp = INFINITY;
                for (size_t j = 0; j < n; j++)
                {
                    if (i != j && !city[i].place)
                    {
                        maxltemp = arr[getSingleIndex(i, j, n)];
                        if (maxltemp == maxl)
                        {
                            ++lengctemp;
                        }
                        else
                        {
                            lengctemp = 1;
                        }

                        maxl = min(maxl, maxltemp);
                    }
                }

                if ((minl > maxl || (minl == maxl && lengc < lengctemp)))
                    if (!city[i].status || (city[i].status && maxl < city[i].leng))
                    {
                        minl = maxl;
                        temp = i;
                        lengc = lengctemp;
                    }
            }
        }

        for (size_t i = 0; i < n; i++)
        {

            if (!city[i].place)
            {
                if (temp == -1)
                {
                    temp = i;
                }
                if (arr[getSingleIndex(i, temp, n)] <= minl)
                {
                    city[i].leng = arr[getSingleIndex(i, temp, n)];
                    city[i].to = temp;
                    city[i].status = 1;
                }
                if (i == temp)
                {
                    city[i].to = temp;
                    city[i].leng = 0;
                    city[i].status = true;
                    city[i].place = true;
                }
            }
        }
    }
}
//export result;
void out(const int &n, const int &k, const City *city)                    
{
    int x = 0;
    int *cityp = new int[k];
    for (size_t i = 0; i < n; i++)
    {
        if (city[i].place == true)
        {
            cityp[x] = i;
            ++x;
        }
    }
    int maxl = 0;
    for (size_t i = 0; i < k; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (city[j].to == cityp[i])
            {
                maxl = max(maxl, city[j].leng);
            }
        }
    }

    ofstream outfile;
    outfile.open("HOMPHIEU.OUT");
    outfile << maxl << "\n";
    for (size_t i = 0; i < k; i++)
    {
        outfile << cityp[i] + 1 << " ";
    }
    outfile.close();
    delete[] cityp;
    cityp = nullptr;
}
#endif //_FUNCTION_