#include<stdio.h>
#include<conio.h>
void merge(int a[],int low,int mid,int high);
void mergesort(int a[],int low,int high);
void mergesort(int a[],int low,int high)
{
if(low<high)
{
int mid=(low+high)/2;
mergesort(a,low,mid);
mergesort(a,mid+1,high);
merge(a,low,mid,high);
}
}
void merge(int a[],int low,int mid,int high)
{
int i=low;int j=mid+1;int k=0;
int temp[100];
while(i<mid&&j<=high)
{
if(a[i]<=a[j])
temp[k++]=a[i++];
else
temp[k++]=a[j++];
}
while(i<=mid)
{
temp[k++]=a[i++];
}
while(j<=mid)
{
temp[k++]=a[j++];
}
for(i=low;i<=high;i++)
for(k=0;i<=high;k++)
a[i]=temp[k];
}
void main()
{
int a[]={10,20,40,30,60,50};
int i,j,k,mid;
mergesort(a,0,5);
for(i=0;i<=5;i++)
{
printf("\t%d",a[i]);
}
getch();
}
    