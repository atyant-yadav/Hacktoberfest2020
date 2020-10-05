#include <stdio.h>
int BS(int a[], int beg, int end, int element){
   if (end >= beg){
      int mid = beg + (end - beg )/2;
      if (a[mid] == element)
         return mid;
      if (a[mid] > element)
         return BS(a, beg, mid-1, element);
      return BS(a, mid+1, end, element);
   }
   return -1;
}
int main(){
	int a[100],i,element,n;
	printf("enter size");
	scanf("%d",&n);
	printf("enter elements");
	for(i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
	}
	printf("enter element to be searched");
	scanf("%d",&element);
   int index = BS(a, 0, n-1, element);
   if(index == -1 ) {
      printf("Element not found in the array ");
   }
   else {
      printf("Element found at index : %d",index);
   }
   return 0;
}
