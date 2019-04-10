#include<stdio.h>

#include<stdlib.h>

int main()
{
	int queue[5000];
        int w;
        int head;
        int t;
        int distance_covered=0;
	printf("Enter total elements in queue= ");
	scanf("%d",&w);
	printf("Enter elements of the queue=");
	for (int i=1;i<=w;i++)
	{
	scanf("%d",&queue[i]);
    }
	printf("Enter head position you want to give=");
	scanf("%d",&head);
	queue[0]=head;
	for(int j=0;j<w;j++)
	{
		t=abs(queue[j+1]-queue[j]);
		distance_covered=distance_covered+t;
	}
	printf("Total distance covered is=%d",distance_covered);
}
