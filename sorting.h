#include <stdio.h>
#include <stdlib.h>
#include <string.h>


class Sorting{
    public:
        static void MergeSort(int *arr,int len){
            //base case
            if(len <= 1)
                return;

            //split array
            int fSize = (len/2),sSize = (len - fSize),first[fSize],second[sSize],Sorted[len],fIndex = 0,sIndex = 0;
            memcpy(first,arr,fSize*sizeof(int));
            memcpy(second,arr+fSize,sSize*sizeof(int));

            //sort
            MergeSort(first,fSize);
            MergeSort(second,sSize);

            //sort sorted arrays
            while((fIndex+sIndex) != len){
                if((fIndex != fSize && first[fIndex] <= second[sIndex]) || sIndex == sSize){
                    Sorted[(fIndex+sIndex)] = first[fIndex];
                    fIndex++;
                }else{
                    Sorted[(fIndex+sIndex)] = second[sIndex];
                    sIndex++;
                }
            }

            //return
            memcpy(arr,Sorted,len*sizeof(int));
        }
        static void QuickSort(int *arr,int len){
            //base case
            if(len <= 1)
                return;

            //delcare ints
            int pivot = arr[0],smaller[len],larger[len],largerIndex = 0,smallerIndex = 0;

            //sort based on pivot
            for(int index = 1; index != len;index++)
            {
                if(arr[index] < pivot){
                    smaller[smallerIndex] = arr[index];
                    smallerIndex++;
                }else{
                    larger[largerIndex] = arr[index];
                    largerIndex++;
                }
            }

            //sort
            QuickSort(larger,largerIndex);
            QuickSort(smaller,smallerIndex);

            //reassemble
            memcpy(arr,smaller,smallerIndex*sizeof(int));
            arr[smallerIndex] = pivot;
            memcpy(arr+smallerIndex+1,larger,largerIndex*sizeof(int));
        }
    
        int static BinarySearch(int *arr,int len,int num){
            //base case
            if(arr[len/2] == num)
                return(len/2);

            if(len <= 1){
                return -1;
            }
            
            int half[(len/2)+1];

            if(arr[len/2] > num){
                memcpy(half,arr,(len/2)*sizeof(int));
                return BinarySearch(half,(len/2),num);
            }else{
                memcpy(half,arr+(len/2)+1,(len-(len/2))*sizeof(int));
                int out = BinarySearch(half,(len-(len/2)),num);
                return ((out != -1)* (1+(len/2))) + out;
            }
        }
};