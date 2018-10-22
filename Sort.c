#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int printArr(int *arr, int n)
{
     for(int i = 0; i < n; i ++)
     {
          if(i % 80 == 0)
               printf("\n");
          printf("%d ", arr[i]);
     }
     printf("\n");
}

void swap(int * arr, int j, int k)
{
     int tmp = arr[j];

     arr[j] = arr[k];
     arr[k] = tmp;
}

void bubble(int *arr, int n)
{
     int i, x, inOrder;

     for(i = 0; i < n; i ++)
     {
          inOrder = 1;
          for(x = 0; x < n; x ++)
          {
               if(arr[x] > arr[x+1])
               {
                    swap(arr, x, x+1);
                    inOrder = 0;
               }

          }
     }
}

void selection(int *arr, int n)
{
     // selection sort algorithm

     if(arr == NULL || n <= 0)
          return;

     int min = 100000000, minIndex;
     for(int i = 0; i < n; i ++)
          if(arr[i] < min)
          {
              minIndex = i;
              min = arr[i];
          }


    // printf("\nmin = %d\n", min);
     swap(arr, 0, minIndex);
    // printArr(arr, n);

    // recursive call
     selection(arr + 1, n - 1);
}


void insertSort(int * arr, int n)
{
     // let's do this iteratively
     int i, j, val, gap;

     for(i = 1; i < n; i ++)
     {
          val = arr[i];
          gap = i;

          for(j = gap-1; j >=0 && arr[j] > val; j--)
          {
               arr[j+1] = arr[j];
               gap--;
          }

          arr[gap] = val;
     }
}

void insertionSortAgain(int * arr, int n)
{
     int peach, x, i, gap;

     for(i = 1; i < n; i ++)
     {
          peach = arr[i];

          for(x = i; x > 0 || arr[x -1] > peach; x --)
          {
               arr[gap] = arr[gap - 1];
          }

          arr[gap] = peach;
     }
}
int range(int *arr, int n)
{
     // This function finds the range of values of an array
     // Will be used for bucket sort

     // set min and max roughly at +- 2 billion
     int max = -2000000000, min = 2000000000;
     for(int i = 0; i < n; i ++)
     {
          if(arr[i] > max)
               max = arr[i];

          if(arr[i] < min)
               min = arr[i];
     }

     return max - min;
}

int findMax(int *arr, int n)
{
     // This function finds the range of values of an array
     // Will be used for bucket sort

     // set min and max roughly at +- 2 billion
     int max = -2000000000;
     for(int i = 0; i < n; i ++)
     {
          if(arr[i] > max)
               max = arr[i];
     }

     return max;
}

int findMin(int *arr, int n)
{
     // This function finds the range of values of an array
     // Will be used for bucket sort

     // set min and max roughly at +- 2 billion
     int min = 2000000000;
     for(int i = 0; i < n; i ++)
     {
          if(arr[i] < min)
               min = arr[i];
     }

     return min;
}

void bucket(int * arr, int n)
{
     int i, x = 0;
     int min = findMin(arr, n);
     int max = findMax(arr, n);
     int * bucket = calloc(max + 1, sizeof(int));

     // assume integers are non negative
     // increment value of bucket whose index is the array's value
     for(i = 0; i < n; i ++)
          bucket[arr[i]]++;

     // loop through all bucket values
     for(i = 0; i <= max; i ++)
     {
          // if a bucket is greater than zero, empty that bucket into the array
          while(bucket[i] > 0)
          {
               arr[x] = i;
               bucket[i]--;
               x++;
          }
     }

     free(bucket);
}


int isSorted(int * arr, int n)
{
     int i;

     for(i = 0; i < n - 1; i ++)
          if(arr[i] > arr[i + 1])
               return 0;

     return 1;
}

void mergeSort(int * arr, int lo, int hi)
{
     int * tmp = NULL;
     int i = lo, k = 0;
     int mid = lo + (hi - lo) / 2;
     int j = mid + 1;

     if(lo >= hi)
          return;

     mergeSort(arr, lo, mid);
     mergeSort(arr, mid + 1, hi);

     tmp = malloc(sizeof(int) * (hi - lo + 1));


     while(i <= mid || j <= hi)
     {
          if(i > mid)
          {
               tmp[k++] = arr[j++];
          }
          else if (j > hi)
          {
               tmp[k++] = arr[i++];
          }
          else if (arr[i] < arr[j])
          {
               tmp[k++] = arr[i++];
          }
          else
          {
               tmp[k++] = arr[j++];
          }
     }

     for(i = lo; i <= hi; i ++)
          arr[i] = tmp[i - lo];

     free(tmp);

}

int main(void)
{
     srand(time(NULL));

     int size = 15;
     int * arr = malloc(sizeof(int) * size);
     int i;

     for(i = 0; i < 15; i++)
     {
          arr[i] = rand() % 100;
     }

     int arr2[8] = { 36, 56, 29, 47, 17, 46, 23, 41};
     printArr(arr2, 8);
     //bucket(arr, size);
     // mergeSort(arr, 0, 14);
    // quicksort(arr2, 8);
    insertSort(arr2, 8);
     printArr(arr, 8);

     if(isSorted(arr, size))
          printf("\narray is sorted\n");
     //insertsort(arr, 15);
    // quicksort(arr, size);
   //  printArr(arr, size);
     printf("\n");
     return 0;
}
