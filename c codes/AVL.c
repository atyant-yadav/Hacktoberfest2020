#include<stdio.h>
#include<math.h>

int heightfunc(int h){
if(h == 0){
	return 1;
}
if(h == 1){
	return 2;
}

return heightfunc(h-1) + heightfunc(h-2) + 1;

}

int main(){
	int n, h, temp;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	printf("When the height of an AVL tree with a single node is 0");
	printf("\nMinimum height of the AVL tree is: %d", (int)(log(n)/log(2)));
    for(h = 0; ; h++){
    	if(heightfunc(h) > n){
    		printf("\nMaximum height of the AVL tree is: %d \n",h-1);
    		break;
    	}
    }
    printf("\nWhen the height of an AVL tree with a single node is 1");
    printf("\nMinimum height of the AVL tree is: %d", ((int)(log(n)/log(2))+1));
    printf("\nMaximum height of the AVL tree is: %d",h);
    return 0;

}
