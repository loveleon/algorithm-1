#include <stdio.h>

static void merge(int unsorted[] , int first, int mid, int last, int sorted[])
{
    int i = first, j = mid;
    int k = 0;
    while (i < mid && j < last)
        if (unsorted[i] < unsorted[j])
            sorted[k++] = unsorted[i++];
        else
            sorted[k++] = unsorted[j++];

    while (i < mid)
        sorted[k++] = unsorted[i++];
    while (j < last)
        sorted[k++] = unsorted[j++];

    for (int v = 0; v < k; v++)
        unsorted[first + v] = sorted[v];
}

static void merge_sort(int unsorted[], int first, int last, int *sorted)
{
    if (first + 1 < last)
    {
        int mid = (first + last) / 2;
        merge_sort(unsorted, first, mid, sorted);
        merge_sort(unsorted, mid, last, sorted);
        merge(unsorted, first, mid, last, sorted);
    }
}

int main()
{
    int x[] = {6, 2, 4, 1, 5, 9};
    int x_length = sizeof(x)/sizeof(int);
    int *sorted = new int[x_length];
    
    merge_sort(x, 0, x_length, sorted);
    
    for (int i = 0; i < x_length; i++)
    {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    for (int i = 0; i < x_length; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");
    
    return 0;
}