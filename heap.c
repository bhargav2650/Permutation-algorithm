    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
void heapPermutation(int a[], int size, int n)
{
    int temp;
    if (size == 1) {
        return;
    }
 
    for (int i = 0; i < size; i++) {
        heapPermutation(a, size - 1, n);
        if (size % 2 == 1)
            {temp=a[0];
            a[0]=a[size-1];
            a[size-1]=temp;}
 
        else
           { temp=a[i];
            a[i]=a[size-1];
            a[size-1]=temp;}
    }
}
 
// Driver code
int main()
{
    int a[] = { 1,2,3,4,5,6,7,8,9,10,11,12};
    int n = sizeof a / sizeof a[0];
    clock_t start, end;
    start = clock();
    heapPermutation(a, n, n);
    end = clock();
    printf("%d",(end-start)/CLOCKS_PER_SEC);
    return 0;
}