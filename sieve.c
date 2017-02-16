#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#include<string.h>

#define N 100000000
//Change the upper limit up to which you want to  calculate the prime number.

int main()
{
    long long int i,j,val,count=2,flag;
     char *p;
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
    printf("Largest prime number within given range : %lld\nCount : %lld",val,count);

    return 0;
}
