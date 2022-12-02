#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void heap(int a[],int n, int c[], int temp,int i,int j)
{
    for(i=0;i<n;i++)
    {
        c[i]=0;
    }
    for(j=0;j<n;j++)
    {
        printf("%d",a[j]);
    }
    printf("\n");
    i=0;
    while(i<n)
    {
        if(c[i]<i)
        {
            if(i%2==0)
            {
                temp=a[0];
                a[0]=a[i];
                a[i]=temp;
            }
            else
            {
                temp=a[c[i]];
                a[c[i]]=a[i];
                a[i]=temp;
            }
            for(j=0;j<n;j++)
            {
                printf("%d",a[j]);
            }
            printf("\n");
            c[i]+=1;
            i=0;
        }
        else
        {
            c[i]=0;
            i+=1;
        }
    }
}
void main()
{
    int a[]={1,2,3};
    int n=sizeof a / sizeof a[0];
    clock_t start, end;
    int temp,i,j;
    int c[n];
    //for(int l=0;l<25;l++)
    {
    start = clock();
    heap(a, n,c,temp,i,j);
    end = clock();
    printf("\n%d",(end-start));
    }
}