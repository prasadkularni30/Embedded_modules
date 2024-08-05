#include<stdio.h>

int main()
{
	int leap_years=0,leap_years_days,not_leap_days,not_leap=0,y,month,d,days=0,days2=0;
	int i,days_of_m2=0,total_days;
	printf("enter year\n");
	scanf("%d",&y);

	printf("enter month\n");
	scanf("%d",&month);

	printf("enter date\n");
	scanf("%d",&d);

	for (i=1970;i<y;i++)
	{
		if((i%4==0) && ((i%400==0) || (i%100!=0)))
		{
			leap_years=leap_years+1;
		}else 
		{
			not_leap=not_leap+1;
		}
	}

	//printf("leap years= %d\n",leap_years);
	//printf("not leap years= %d\n",not_leap);
	leap_years_days=leap_years*366;
	//printf("leap years days = %d\n",leap_years_days);
	not_leap_days=not_leap*365;
	//printf("not leap days = %d\n",not_leap_days);
	
	
	for (int m=1;m<month;m++)
	{
		if (m==2)
		{
			if((y%4==0) && ((y%400==0) || (y%100!=0)))
			{
				days_of_m2=days_of_m2+29;
			}else
			{
				days_of_m2=days_of_m2+28;
			}
			//printf("days= %d\n",days_of_m2);
		}else if (m==1 || m==3 || m==5 || m==7 || m==9 || m==11 || m==12)
		{
			days=days+31;
		}else
		{
			days2=days2+30;
		}
	}


	total_days=leap_years_days+not_leap_days+days_of_m2+days+days2+d;
	printf("total days = %d\n",total_days);
	
	int day=total_days%7;

	switch (day)
	{
		case 1:
			printf("The day is Thursday\n");
			break;
		case 2:
			printf("The day is Friday\n");
			break;
		case 3:
			printf("The day is Saturday\n");
			break;
		case 4:
			printf("The day is Sunday\n");
			break;
		case 5:
			printf("The day is Monday\n");
			break;
		case 6:
			printf("The day is Tuesday\n");
			break;
		case 0:
			printf("The day is Wednesday\n");
			break;
		default:
			printf("not valid date");
			break;
	}return 0;
} 
