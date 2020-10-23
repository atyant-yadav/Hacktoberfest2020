#include <stdio.h>

int hitung(int a, int *b){
    *b = 15;
    return a + *b;

}

main(){
    int y,z,hasil;
    y=10;
    z=50;
    printf("Sebelum Jalankan Fungsin");
    printf("y=%d\n",y);
    printf("z=%d\n",z);
    hasil=hitung(y,&z);
    printf("Sebelum Jalankan Fungsin");
    printf("y=%d\n",y);
    printf("z=%d\n",z);
    printf("hasil=%d\n",hasil);
}
