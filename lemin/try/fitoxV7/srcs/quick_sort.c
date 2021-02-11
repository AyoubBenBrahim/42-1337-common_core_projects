
#include "../inc/lem_in.h"

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int tab[], int start, int end)
{
    int pivot;
    int partition_index;
    int i;

    pivot = tab[end];
    partition_index = start; // Index of smaller element

    i = start;
    while (i < end)
    {
        // If current element is smaller than the pivot
        if (tab[i] <= pivot)
        {
            swap(&tab[partition_index], &tab[i]);
            partition_index++; // increment index of smaller element
        }

        i++;
    }

    swap(&tab[partition_index], &tab[end]);
    return (partition_index);
}

void quick_sort(int tab[], int start, int end)
{
    int partition_index;

    if (start < end)
    {
        partition_index = partition(tab, start, end);
        //  sort right side
        quick_sort(tab, start, partition_index - 1);
        //  sort left side
        quick_sort(tab, partition_index + 1, end);
    }
}

// void printArray(int arr[], int size)
// {
//     int i;

//     for (i=0; i < size; i++)
//         printf("%d ", arr[i]);
//     printf("\n");
// }

/*
int main() 
{ 
    int tab[] = {987654321, 110, 71, 1098, 90, 111, 5, 0 , 1, 90, 12345678, 0, 1, 2 ,44, 8}; 
    int n = sizeof(tab)/sizeof(tab[0]);
    printf("sizeof(tab) = %d\n", (int)sizeof(tab));
    printf("sizeof(tab[0]) = %d\n", (int)sizeof(tab[0]));
    printf("n = %d\n", (int)sizeof(tab)/(int)sizeof(tab[0]));
    quick_sort(tab, 0, n - 1);
    printf("sorted array: \n");
    printArray(tab, n); 
    return 0; 
} 
*/
