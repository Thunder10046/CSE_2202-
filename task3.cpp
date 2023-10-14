#include<bits/stdc++.h>
#include<fstream>
#include<chrono>
using namespace std; 

int max_min_normal(int arr[],int size)
{
    int max, min;
    max = min = arr[0];
    int comp = 0;

    for (int i = 1; i <size ; i++)
    {
        if (arr[i]>max)
        {
            max =arr[i];
            comp++;  
        }
        else if (arr[i]<min)
        {
            min = arr[i];
            comp++;
        }
        
    }
    return comp;
    
}

int MaxMin(int i, int j, int arr[], int &max, int &min)
{
    int comp = 0;
    if (i == j)
    {
        max = min = arr[i];
        comp++;
    }
    else if (i == j - 1)
    {
        if (arr[i] < arr[j])
        {
            max = arr[j];
            min = arr[i];
            comp++;
        }
        else
        {
            max = arr[i];
            min = arr[j];
            comp++;
        }
    }
    else
    {
        int mid = (i + j) / 2;
        int max1, min1;
        int comp1 = MaxMin(i, mid, arr, max, min);
        int comp2 = MaxMin(mid + 1, j, arr, max1, min1);

        comp += (comp1 + comp2);

        if (max1 > max)
        {
            max = max1;
            comp++;
        }
        if (min1 < min)
        {
            min = min1;
            comp++;
        }
    }
    return comp;
}

int main()
{
    int n = 10000;
    int arr[n+1]; 
    int rand_n; 
    // ofstream out("task3.txt");
    
    // for (int i = 0; i < n; i++)
    // {
    //     rand_n = rand()%10000 + 1;      
    //     out<<rand_n<<" ";        
    // }

    // out.close(); 

    ifstream in ("task3.txt");  

    

    for (int i = 0; i < n; i++)
    {
        in>>arr[i];  
    }

    in.close(); 

    
    
    int comp1 = max_min_normal(arr, n);
    int max2 = arr[0];
    int min2 = arr[0];
    int comp2 = MaxMin(0, n - 1, arr, max2, min2);

    cout << "Normal Method:\n";
    cout << "Comparisons: " << comp1 << endl;

    cout << "Divide and Conquer Method:\n";
    cout << "Max: " << max2 << ", Min: " << min2 << ", Comparisons: " << comp2 << endl;
}

    

