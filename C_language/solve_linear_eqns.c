#include<stdio.h>
//Q8. WAP to Solving linear equations
//a1x+b1y=c1; a2x+b2y=c2
//a1x+b1y+c1z=d1; a2x+b2y+c2z=d2; a3x+b3y+c3z=d3
int replace(int [][2],int [][1],int);
int det(int [][2]);
void print(int a[2][2]);

int main()
{
int matrix[2][2]={2,3,1,1};
int con[2][1]={4,1};

int D=det(matrix);
printf("D=%d\n",D);

if(D==0)
	return -1;
int i,j;
int r1[2][2];
for(i=0;i<2;i++,j++)
{
	for(j=0;j<2;j++)
	{
		r1[i][j]=matrix[i][j];
	}
}

int k=0;

int Dy=replace(r1,con,k);


printf("Dy=%d\n",Dy);
int y=(Dy/D);


int r2[2][2];
for(i=0;i<2;i++,j++)
{
	for(j=0;j<2;j++)
	{
		r2[i][j]=matrix[i][j];
	}
}
k=1;
int Dx=replace(r2,con,k);

printf("Dx=%d\n",Dx);
int x=(Dx/D);


printf("X=%d\n",x);
printf("Y=%d\n",y);


}

int det(int a[2][2])
{
        int deter;
        deter=(a[0][0]*a[1][1])-(a[0][1]*a[1][0]);
        //printf("det 2X2: %d",det);
        //printf("\n");

	return deter;
}

int replace(int r[2][2],int b[2][1],int x)
{
	int i,j,k,z=0;

	if(x==1)
	{
		i=0,k=0;
	}else{
		i=1,k=1;
	}

		for(i;i==k;i++)
		{
			for(j=0,z;j<2;j++)
			{
				r[j][i]=b[j][z];
			}

		}

int D=det(r);
return D;

	
}
void print(int a[2][2])
{
	int i,j;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
		printf("%d ",a[i][j]);
		}

	printf("\n");
	}
}
