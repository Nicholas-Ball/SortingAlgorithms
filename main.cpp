#include <iostream>
#include <chrono>
#include <vector>
#include "sorting.h"


using namespace std::chrono;

void testQuick()
{
    int total = 0;
    for(int i = 0; i != 1000;i++){
        //make a list
        int x[500];
        for(int i = 0; i != 500; i++)
            x[i] = (rand()%1000)+1;

        auto start = high_resolution_clock::now();

        Sorting::QuickSort(x,(int)( sizeof(x) / sizeof(int)));

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        total += duration.count();
    }
    std::cout << "Average Time taken by QuickSort: "<< (total/1000)<< " microseconds" << std::endl;
}

void testMerge()
{
    int total = 0;
    for(int i = 0; i != 1000;i++){
        //make a list
        int x[500];
        for(int i = 0; i != 500; i++)
            x[i] = (rand()%1000)+1;
        auto start = high_resolution_clock::now();

        Sorting::MergeSort(x,(int)( sizeof(x) / sizeof(int)));

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        total += duration.count();
    }
    std::cout << "Average Time taken by MergeSort: "<< (total/1000)<< " microseconds" << std::endl;

}

int main()
{
    /**/
    int x[] = {5,65,8,12,64,8};
    testMerge();
    testQuick();

    Sorting::MergeSort(x,(int)( sizeof(x) / sizeof(int)));

    for(int i = 0; i != (int)( sizeof(x) / sizeof(int)); i++){
        printf("%d ",x[i]);
    }
    printf("\n");

    std::cout<<Sorting::BinarySearch(x,(int)( sizeof(x) / sizeof(int)),-3)<<std::endl;
    /**/

    return 0;
}
