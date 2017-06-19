// https://www.cnblogs.com/ider/archive/2012/04/01/binary_search.html
#include <stdio.h>

int bsearchWithRecursion(int array[], int low, int high, int target)
{
    if (low > high) return -1;
    
    int mid = (low + high)/2;
    
    if (array[mid]> target)
        return bsearchWithRecursion(array, low, mid - 1, target);
        
    if (array[mid]< target)
        return bsearchWithRecursion(array, mid + 1, high, target);
    
    //if (midValue == target)
        return mid;
}

int bsearchWithoutRecursion(int array[], int low, int high, int target)
{
    while(low <= high)
    {
        int mid = (low + high)/2;
        if (array[mid] > target)
            high = mid - 1;
        else if (array[mid] < target)
            low = mid + 1;
        else //find the target
            return mid;
    }
    //the array does not contain the target
    return -1;
}

int binarySearch(int array[], int low, int high, int target)
{
    return bsearchWithoutRecursion(array, low, high, target);
}

int main()
{
    int i, val, ret;
    int a[8] = {-32, 12, 16, 24, 36, 45, 59, 98};

    val = 16;
    
    ret = binarySearch(a, 0, 7, val);
    if(-1 == ret)
        printf("failed.\n");
    else
        printf ("sucess.\n");
    return 0;
}