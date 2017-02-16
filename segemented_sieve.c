#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#include<string.h>

#define M 100000000
//Change the upper limit up to which you want to  calculate the prime number.

long long int k=0;
long long int val;
void sieve(long long int a[])
{
    long long int i,j,val,count=2,flag,N;
    char *p;
     N= floor(sqrt(M));
     a[k++]=2;
     a[k++]=3;
     p=(char *)malloc((N+1)*sizeof(char));
    //for(i=3;i<N+1;i+=2)
      //  p[i]=1;
    memset(p,1,N+1);
    flag=0;
    for(i=5;i<=sqrt(N);i+=2)
    {
        if(p[i]==0 || i%3==0)
            continue;
        for(j=i*i;j<=N;j+=i+i)
        {
            p[j] = 0;
        }

    }
    flag=0;
    for(i=5;i<N+1;)
    {
        if(p[i]==1)
        {
            val=i;
            a[k++]=val;
            count++;
           // printf("%lld  ",val);
        }
        if(flag==0)
        {
            i=i+2;  flag=1;
        }
        else if(flag==1)
        {
            i+= 4; flag=0;
        }
    }
    //printf("%lld %lld",val,count);
    //printf("\n%ld  %ld",k,a[k-1]);
}

void seg_sieve(long long int a[])
{
    long long int low,high,limit,i,j,loLim,arr_size,start,flag;
    char *p;
    arr_size= k;
    limit= floor(sqrt(M))+1;
    low= limit;
    high= limit*2;
    while(low<M)
    {
        p = (char*)malloc((limit+1)*sizeof(char));
        memset(p,'1',limit+1);
        for(i=2;i<arr_size;i++)
        {
            loLim = floor(low/a[i]) * a[i];
            if (loLim < low)
                loLim += a[i];
           // j= (low % a[i]) ? (low/a[i]+1)*a[i] : low ;
            for(j=loLim; j<high; j+=a[i])
                p[j-low]='0';
        }

        if(low%2==0)
        {
            if( (low+1) % 3)
            {
                start= low+1;
                //flag= 0;
            }
            else
            {
                start= low+3;
                //flag= 0;
            }
        }
        else
        {
            if(low%3)
            {
                start= low;
            }
            else
            {
               start= low+2;
            }
        }
        if( (start+2) % 3)             //checking to set the value of flag. whether start comes 1st or 2nd in the pair.(like 11,13)
            flag=0;
        else
            flag=1;
        for(i= start ; i<high;)
        {
            if(p[i-low]=='1')
            {
                k++;  val = i;
            }
            if(flag==0)
            {
                i=i+2;  flag=1;
            }
            else if(flag==1)
            {
                i+= 4; flag=0;
            }
        }
        low= low+limit;
        high= high+limit;
        if(high>=M)
            high=M;
    }
    printf("\nLargest prime number within given range : %lld",val);

}

int main()
{
    long long int size= floor(sqrt(M)+1);

    long long int *a=(long long int*)malloc(size*sizeof(long long int));

    sieve(a);
    seg_sieve(a);
    printf("\ncount : %lld",k);
    return 0;
}
