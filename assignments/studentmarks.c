#include<stdio.h>
int main(){
int n,i,j,key,shifts=0;
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=1;i<n;i++){
key=a[i];
j=i-1;
while(j>=0&&a[j]>key){
a[j+1]=a[j];
shifts++;
j--;
}
a[j+1]=key;
printf("Pass %d: ",i);
for(j=0;j<n;j++)
printf("%d ",a[j]);
printf("\n");
}
printf("Sorted array: ");
for(i=0;i<n;i++)
printf("%d ",a[i]);
printf("\nTotal shifts: %d\n",shifts);
return 0;
}
