#include<stdio.h>
int main()
{
        int n;
        scanf("%d",&n);
        int sum=0,temp;
        for(int i=n;i>1;i=i/2)
        {
                if(n%i==0) // if current value is divisibile then do the sum
                        sum=sum+i;

                if(i%2!=0)//if no is odd then +1 in the number then check the divisibility 
                {
                        i++;
                        if(n%i==0)
                        sum=sum+i;
                }

               // printf("sum=%d\n",sum);
        }
        float s=(sum+1)/2.0;
       // printf("%f\n",s);
        if(s==n)
                printf("%d is perfect number\n",n);
        else
                printf("%d is not a perfect number\n",n);
        return 0;
}
