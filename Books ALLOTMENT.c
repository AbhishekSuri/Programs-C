#include<stdio.h>
int check(int A[],int n1,int B,int mid)
 {
     int d,s=1,i,sum=0;
     for(i=0;i<n1;i++)
     {
         if((sum+A[i])<=mid)
         {
             sum=sum+A[i];
             //printf(" %d ",sum);
         }
         else
         {
             sum=A[i];
             s++;
             if(s>B)
             return 0;
         }
     }
         //printf("%d ",s);
         return 1;
 }
int books(int A[], int n1, int B) {
    int max=A[0],i,sum=0,index=0,k;
    if(n1<B)
    return -1;
    for(i=0;i<n1;i++)
    {
        if(max<A[i])
        {
            max=A[i];
        }
    }
    for(i=0;i<n1;i++)
    {
            sum+=A[i];

    }

    int l=max,r=sum,mid,f;
    while(l<r)
    {
        mid=(l+r)/2;
        //printf("%d",mid);
        k=check(A,n1,B,mid);
        if(k==0)
        {

            l=mid+1;
        }
        if(k==1)
        {
            r=mid;
        }

    }
    return r;
}

int main()
{
    int a,n1,B,i;
    printf("ENTER NO OF BOOKS\n");
    scanf("%d",&n1);
    printf("ENTER NO OF STUDENTS\n");
    scanf("%d",&B);
    printf("ENTER BOOKS PAGES\n");
    int A[100];
    for(i=0;i<n1;i++)
    {
        scanf("%d",&A[i]);
    }
    a=books(A,n1,B);
    printf(" The maximum number of pages alloted to a student which are minimum = %d",a);
    return 0;
}
