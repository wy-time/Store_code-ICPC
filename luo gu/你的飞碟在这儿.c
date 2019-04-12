#include<stdio.h>
int main()
{
	char a[7];
	char b[7];
	int i=0;
	int star=1;
	int team =1;
	scanf("%s",a);
	scanf("%s",b);
	for(i=0;a[i]!='\0';i++)
	{
		star*=((int)a[i]-64);
	}
	 for(i=0;b[i]!='\0';i++)
	 {
	 	team*=((int)b[i]-64);
	 }
	 if(star%47==team%47)
	 {
	 	printf("GO");
	 }else
	 {
	 	printf("STAY");
	 }
	 return 0;
} 
