#include<bits/stdc++.h>
#include<algorithm>
#include<fstream>
using namespace std; 


int linear_search(int arr[], int key)
{
    int steps = 0;  //variable definded for step count
    int flag = 0;   //flag is used for exception and throwing error
    for (int i = 0; i < 10001; i++)
    {
        steps++;   //steps would count whenever the loop occurs 
        if (arr[i]==key)
        {
            flag = 1; 
            cout<<"Fount at position "<<i+1<<"th"<<endl; 
            cout<<"Step count for linear search "<<steps<<endl;
            break;
        }
    }
    if (flag ==0)
    {
        cout<<"Invalid Key input"<<endl;
    }
    
}

int binary_search(int arr[], int key)
{
    int steps =0, flag = 0; 
    sort(arr,arr+10001); //hence binary search requires sorting as it's primal condition 
    int s=0, e = 10000-1;
    for (; s <=e ;)
    {
        steps++;
        int m = (s+e);
        if (arr[m]==key)
        {
            flag = 1; 
            cout<<"Found at position "<<m+1<<"th"<<endl; 
            cout<<"Step count for binary search "<<steps<<endl;
            break;
        }
        else if (arr[m]<key)
        {
            s= m +1; 
        }
        else
        {
            e = m-1;
        }
        
    }
    if (!flag)
    {
        cout<<"Invalid key input"<<endl;
    }
    
}

int main()
{
    // ofstream out("task2.txt"); //using constractor to open a file which was previously saved 

    // int rand_n; 
    
    // for (int i = 0; i < 10001; i++)
    // {
    //     rand_n = rand()%10001 + 1;      // this allows to generate eandom numbers which range from 1 to 10000. 
    //     out<<rand_n<<" ";        //writing the random numbers in the file 
    // }

    // out.close(); // closing the file, unless it would run in the background

    ifstream in ("task2.txt"); // ifstream is a class which is included by using a header file which is added as - #include<fstream>. Creating an object of this class - 'in' and also, constracting a text file, used as a parameter, from where the data would be fetched  

    int arr[10001]; 

    for (int i = 0; i < 10001; i++)
    {
        in>>arr[i]; // fetching data from the created object and storing the data in an array consisting the size of 10001. 
    }

    in.close(); // closing the file is a good practice, unless it would run in the background and might result in stressing ram 


    int key; // the number to search. go to task2.txt and pick a number and put
    cout<<endl; 
    cout<<"Enter key: "<<endl;

    cin>>key; 

    linear_search(arr,key);
    cout<<endl<<endl;
    binary_search(arr,key);
    cout<<endl;    
    
}