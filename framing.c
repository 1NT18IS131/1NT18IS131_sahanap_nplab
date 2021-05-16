#include<stdio.h>
void sender(int numofframes,int frame[numofframes]){
	int i;
	int n;
	int total=0;
	for(i=0;i<numofframes;i++)
	{
		int count=0;
		n=frame[i];
	    do
		{
			n=n/10;
			count++;
		}while(n!=0);
		printf("\nNumber of frames in %d frame is %d\n",i+1,count);
		total+=count;
		count=0;	
	}
	printf("\nThe total number of bytes is %d\n",total);	
	 receiver( numofframes,frame);
}
void receiver(int nof,int fr[nof])
{
	int k;
	for(k=0;k<nof;k++)
	{
	printf("\n The %d received frame is %d\n",k+1,fr[k]);
	}
}
void main(){
	int no;
	int frame[no];
	int i;
	printf("Enter the number of frames ");
	scanf("%d",&no);
	printf("Enter the pattern for each frame");
	for(i=0;i<no;i++)
	{
		scanf("%d",&frame[i]);
	}
	sender(no,frame);	
}
