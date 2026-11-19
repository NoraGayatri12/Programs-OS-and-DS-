#include<stdio.h>
int main()
{
    int a[]={10,20,30,40,50,60,70,80,90,100};
    printf("elements in array");
    for(int i=0;i<=9;i++)
    {
        printf("\n%d",a[i]);
        }
       int key=100;
        int result=binarySearch(a,key);
        if(result!=-1){
            printf("\nelement found at %d index",result);
            }
            else{
                printf("element is not found\n");
                return-1;
                }
}
        int binarySearch(int a[],int key)
        {
            int l=0,h=9;
            int mid=0;
            while(l<=h)
            {
               mid=(l+h)/2;
                 if(key==a[mid])
                 {
                return mid;
            }
            else if(key<a[mid]){
                h=mid-1;
                }
                else{
                    l=mid+1;
                }
                
                }
         }       