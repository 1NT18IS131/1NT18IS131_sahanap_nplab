#include<stdio.h>
#include<conio.h>
#include<string.h>
void main() {
	int i, j,count=0,count1=0,n1=0;
	char str[100];
	int k;
	char str1[100];
	char str2[100];
	char frame[100];
	int temp=0;
char str3[8]="01111110";
	printf("enter the bit string:  ");
	gets(str);
	for (i=0;i<strlen(str);i++) {
	
		count=0;
		for (j=i;j<=(i+5);j++) {
			if(str[j]=='1') {
				count++;
			}
		}
		//if there is six ones then folling code execute to bit stuffing after five ones
		if(count==6) {

			n1=strlen(str)+2;
			for (k=n1;k>=(i+5);k--) {
				str[k]=str[k-1];
			}
			str[i+5]='0';
			i=i+7;
		}
	}
	printf("after bit stuffing at the sender end\n ");
	printf("the encoded frame is\n");
	frame[0]='0';
	frame[1]='1';
	frame[2]='1';
	frame[3]='1';
	frame[4]='1';
	frame[5]='1';
	frame[6]='1';
	frame[7]='0';
	for(i=8,j=0;j<=strlen(str);i++,j++)
	{
		frame[i]=str[j];
	}
	temp=i-1;
	frame[temp]='0';
	frame[temp+1]='1';
	frame[temp+2]='1';
	frame[temp+3]='1';
	frame[temp+4]='1';
	frame[temp+5]='1';
	frame[temp+6]='1';
	frame[temp+7]='0';
	for(i=0;i<=temp+7;i++)
	{
		printf("%c",frame[i]);
	}
	printf("\n");
	
	
	printf("after bit unstuffing at the reciever end\n");
	for (i=0;i<strlen(str);i++) {
	count1=0;
		count=0;
		for (j=i;j<=(i+5);j++) {
			if(str[j]=='1') {
				count++;
			}
			if(str[j]=='0')
			{
				count1++;
			}
		}
		//if there is six ones then folling code execute to bit stuffing after five ones
		if(count==5&&count1==1) {

			n1=strlen(str)+2;
			for (k=(i+6);k<=n1;k++) {
				str[k]=str[k+1];
			}
			//str[i+5]=1;
			i=i+7;
		}
	}
	frame[0]='0';
	frame[1]='1';
	frame[2]='1';
	frame[3]='1';
	frame[4]='1';
	frame[5]='1';
	frame[6]='1';
	frame[7]='0';
	for(i=8,j=0;j<=strlen(str);i++,j++)
	{
		frame[i]=str[j];
	}
	
	temp=i-1;
	frame[temp]='0';
	frame[temp+1]='1';
	frame[temp+2]='1';
	frame[temp+3]='1';
	frame[temp+4]='1';
	frame[temp+5]='1';
	frame[temp+6]='1';
	frame[temp+7]='0';
		for(i=0;i<=temp+7;i++)
	{
		printf("%c",frame[i]);
	}
	printf("\n");
	
}
