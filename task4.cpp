#include <bits/stdc++.h>
#include <fstream>
using namespace std;

void merge(int ax[], int lb, int mid, int ub)
{
    int i, j, k;
    i = lb;
    j = mid + 1;
    k = lb;
    int bx[10001];
    while (i <= mid && j <= ub)
    {
        if (ax[i] <= ax[j])
        {
            bx[k] = ax[i];
            i++;
        }
        else
        {
            bx[k] = ax[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        bx[k] = ax[i];
        i++;
        k++;
    }
    while (j <= ub)
    {
        bx[k] = ax[j];
        j++;
        k++;
    }
    for (int k = lb; k <= ub; k++)
    {
        ax[k] = bx[k];
    }
}

void merge_sort(int ax[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2; 
        merge_sort(ax, lb, mid);
        merge_sort(ax, mid + 1, ub);
        merge(ax, lb, mid, ub);
    }
}

int main()
{
    int n = 10000;
    int arr[n + 1];
    int rand_n;

    
    // ofstream out("task4.txt");

    // for (int i = 0; i <= n; i++)
    // {
    //     rand_n = rand() % 10000 + 1;
    //     out << rand_n << " ";
    // }

    // out.close();

    ifstream in("task4.txt");

    for (int i = 0; i <= n; i++)
    {
        in >> arr[i];
    }

    in.close();


    merge_sort(arr, 0, n);

    cout << "Array after Sorting: " << endl;

    for (int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
}
