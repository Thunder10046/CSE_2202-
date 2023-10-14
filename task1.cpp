#include<bits/stdc++.h>
using namespace std; 

int selection(int ax[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int temp = 0;
            if (ax[i] < ax[j])
            {
                continue;
            }
            else
            {
                temp = ax[i];
                ax[i] = ax[j];
                ax[j] = temp;
            }
        }
    }
    cout << "Sorted Elements are: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ax[i] << endl;
    }
}

int insertion(int ax[], int n)
{
    for (int i = n; i >=0; i--)
    {
        
        int temp=ax[i];
        int j=i-1;
        while (j>-1 && ax[j]>temp)
        {
            ax[j+1]=ax[j];
            j--;
        }
        ax[j+1] = temp;
        
    }

}

int main()
{

}