#include<stdio.h>

int main()
{
FILE *fp;
char ch;
fp = fopen("filea.txt", "w");
printf("Enter data\n");
while((ch = getchar())!=EOF){
putc(ch,fp); 
}
fclose(fp);

fp = fopen("filea.txt", "r");
printf("data\n");

while((ch=getc(fp)) != EOF) {
putchar(ch);
}

fclose(fp);
}
