#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void StaticArray(int &size) // declaring static array and filling it with random numbers 0-100
{
    srand(time(NULL));
    static int a[1000];
    int i;
     size = sizeof(a) / sizeof(a[0]);
    
    for (i=0;i<size;i++)
    {
        a[i]=rand() % 100 + 1;
    }
    
    
    
}

void localarray(int &size) // creating local array and filling it with random values 0-100
{
    srand(time(NULL));
    int a[1000];
    int i;
     size = sizeof(a) / sizeof(a[0]);
   
    
    for (i=0;i<size;i++)
    {
        a[i]=rand() % 100 + 1;
    }
    
    
    
    
    
    
    
}

void DynamicArray(int &size) // creating Dynamic array and filling it with random values 0-100
{
    srand(time(NULL));
    int *a = (int *) malloc (1000 * sizeof(int));
    int i;
     size = 1000;
    
    for (i=0;i<size;i++)
    {
        a[i]=rand() % 100 + 1;
    }
    
    free(a);
    
    
}

void calculation_of_StaticArray(int &size) // calculating time and calling 100k times the function
{
    int i=0;
    clock_t t;
        t = clock();
    for(i;i<100000;i++)
    {
         StaticArray(size);
        
    }
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
      
    cout << "StaticArray() of size " << size <<" took " << time_taken <<" seconds to execute " << "and is being called " <<i<< " times\n" << endl;
    
}

void calculation_of_DynamicArray(int &size) //calculating time and calling 100k times the function
{
    int i=0;
    clock_t t;
        t = clock();
    for(i;i<100000;i++)
    {
        DynamicArray(size);
        
    }
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
      
    cout << "DynamicArray() of size " << size <<" took " << time_taken <<" seconds to execute " << "and is being called " <<i<< " times\n" << endl;
    
}


void calculation_of_localarray(int &size) //calculating time and calling 100k times the function and printing results
{
    int i=0;
    clock_t t;
        t = clock();
    for( i;i<100000;i++)
    {
        localarray(size);
        
    }
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
      
    cout << "LocalArray() of size " << size <<" took " << time_taken <<" seconds to execute " << "and is being called " <<i<< " times\n" << endl;
    
}




int main()
{
    int size;
    calculation_of_localarray( size);
    calculation_of_DynamicArray(size);
    calculation_of_StaticArray(size);
    
    return 0;
}


