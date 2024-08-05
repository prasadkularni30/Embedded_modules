#include<stdio.h>
int main()
{
        int a,b,temp1,temp2;
        scanf("%d",&a);
        scanf("%d",&b);
        temp1=0;
        temp2=0;
        int i=1,j=1;
        for (;i<=b&&j<=a;)                 /*LCM Calculation */
                                           /* eg lcm  4 and 10
                                             4= 4 8 12 16 20
                                            10= 10 20
                                            ans =20
                                             */
        {
                temp1=i*a;
                temp2=j*b;
                if(temp1==temp2)
                {
                        printf("LCM is = %d \n",temp1);
                        break;
                }
                else
                {
                        if(temp2>temp1) /* means the first multipliction is lesser than the first one  */
                                i++;
                        else            /* means the first multiplicatoin is greater than the second*/
                                j++;
                }
        }

        int GCD,k;
	k=a*b;
	
	GCD=k/temp1;

        printf("GCD = %d \n",GCD);

        return 0;
}
