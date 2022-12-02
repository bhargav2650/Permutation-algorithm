#include<stdio.h>
#include<stdlib.h>
#include <time.h>
void mypermutation(int a[], int n, int li[], long fact[], int *l[], int j,int i, int temp1, int s,int p, int *temp)
{
    fact[0]=1;
    li[0]=0;
    l[0]=li;
    for(int i=1;i<n-1;i++)
    {
        li[i]=i;
        fact[i]=(i+1)*fact[i-1];
        l[i]=li+i;
    }
    s=1;
    p=0;
    while(s<fact[n-2])
    {
        j=0;
        p=0;
        while(p<n) 
        {
            //print array
            // for(int i=0;i<n;i++)
            // {
            //     printf("%d",a[(i+p)%n]);
            // }
            // printf("\n");
            p+=1;
        }
        for(i=0;i<n-1;i++)
        {
            if(s%fact[i]==0)
            {
                if(i>j)
                {
                    j=i;
                }
            }
        }
        //printf("%d",*l[j]);
        temp1=a[(p+n-2-li[*l[j]])%n];
        a[(p+n-2-li[*l[j]])%n]=a[(p+n-1)%n];
        a[(p+n-1)%n]=temp1;
        if(j>1)
        {
            for(i=0;i<j-2;i++)
            {
                if(l[i]>l[i+1])
                {
                temp=l[i];
                l[i]=l[i+1];
                l[i+1]=temp;
                }
            }
            if(l[j-1]<l[0])
            {
                temp1=0;
                for(i=1;i<j;i++)
                {
                    if(l[i]>l[temp1])
                    {
                        temp1=i;
                    }
                }
                temp=l[j-1];
                l[j-1]=l[temp1];
                l[temp1]=temp;
            }
            else
            {
                for(i=j-2;i>-1;i--)
                {
                    if(l[i]<l[j-1])
                    {
                        temp=l[i];
                        l[i]=l[j-1];
                        l[j-1]=temp;
                        i=-1;
                    }
                }
            }
        }
        s+=1;
    }
    p=0;
    while(p<n)
    {
    //print array for final cycle
    // for(int i=0;i<n;i++)
    //         {
    //             printf("%d",a[(i+p)%n]);
    //         }
    //         printf("\n");
    p+=1;
    }
}
void main()
{
    int a[]={1,2,3,4,5,6,7,8,9,10,11,12};
    int n=sizeof a / sizeof a[0];
    clock_t start, end;
    int li[n-1];
    int *l[n-1];
    long fact[n-1];
    int j,i,temp1,s,p;
    int *temp;
   //for(int y=0;y<25;y++)
    {
    start = clock();
    mypermutation(a, n,li,fact,l,j,i,temp1,s,p,temp);
    end = clock();
    printf("%d",(end-start));
    printf("\n");
    }
}
            // for(int i=0;i<n;i++)
            // {
            //     printf("%d",a[(i+p)%n]);
            // }
            // printf("\n");