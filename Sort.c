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

void quicksort(int * arr, int n)
{
     // p is pivot point
     // r is right index
     // l is left index
     int p, l = 1, r = n-1;
     p = 0;

     if(arr == NULL)
          return;

     for(int i = 1; i < n; i ++)
     {
         // printf("iteration\n");
          if(r <= l)
               return;
          if(arr[r] < arr[p])
          {
               printf("arr[%d] %d > %d arr[%d]\n", p, arr[p], arr[r], r);
               if(arr[l] > arr[p])
               {
                   swap(arr, l, r);

               }
               l ++;
               r --;
          }
     }
}

void insertsort(int * arr, int n)
{
     // let's do this iteratively
     int peach;
     int i = 1;

     int gap;

     for(i = 1; i < n; i ++)
     {
          // pull down the value of 1st index of unsorted arr
          peach = arr[i];

          // loop backwards through the sorted array
          // find index to insert peach
          for(gap = i; gap > 0 & peach < arr[gap - 1]; gap --)
          {
               // shift arr
               arr[gap] = arr[gap - 1];
          }

          // when gap is the right index to insert the peach
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

     printArr(arr, size);
     bucket(arr, size);
     printArr(arr, size);

     if(isSorted(arr, size))
          printf("\narray is sorted\n");
     //insertsort(arr, 15);
    // quicksort(arr, size);
   //  printArr(arr, size);
     printf("\n");
     return 0;
}
