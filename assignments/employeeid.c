#include<stdio.h>
int main()
{
int a[100],n,key,low,high,mid,comp=0,found=0,i;
printf("Enter number of employee IDs: ");
scanf("%d",&n);
printf("Enter employee IDs in ascending order:\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("Enter ID to search: ");
scanf("%d",&key);
low=0;
high=n-1;
while(low<=high)
{
mid=(low+high)/2;
comp++;
if(a[mid]==key)
{
printf("Employee ID found at position %d\n",mid+1);
found=1;
break;
}
else if(a[mid]<key)
low=mid+1;
else
high=mid-1;
}
if(found==0)
printf("Employee ID not found\n");
printf("Number of comparisons: %d\n",comp);
return 0;
}
