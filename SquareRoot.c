/*
Author : Aashish Shirgave
Email : aashish.shirgave@gmail.com
*/

#include <stdio.h>
int main(){
    int n = 9;
    int start, end, mid, i, ans;
    start = 0;
    end = n;

    while(start <= end){
        mid = ( start + end ) / 2;
        i = mid * mid;
        if(i == n){
            ans = mid;
            break;
        }
        if(i < n){
            start = mid + 1;
            ans = mid;
        }
        else{
            end = mid - 1;
        }
    }
    printf("%d \n", ans);
}
