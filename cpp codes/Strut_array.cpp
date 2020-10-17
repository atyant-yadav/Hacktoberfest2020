#include<iostream>
using namespace std;

struct nama{
char dp[20];
char tgh[20];
char blk[20];
};

struct ttl{
char tempat[50];
int tgl;
char bulan[10];
int thn;
};

struct alamat
{
char jl[50];
int rt;
int rw;
char des[50];
char kec[50];
char kab[50];
};

struct jalan
{
struct nama i;
int nik;
struct ttl j;
char jk[10];
struct alamat k; //salah
};

main()
{
int x;
cout<<"PROGRAM PENDATAAN PENDUDUK"<<endl;
cout<<"=========================="<<endl;
cout<<"\nJumlah Warga Yang Akan Di Data : ";cin>>x;
jalan wrg[x]; //salah

cout<<"=================="<<endl;
cout<<"Masukan Data Warga"<<endl;
cout<<"=================="<<endl;

for(int i=0;i<x;i++){
cout<<"Warga "<<i+1<<endl; //salah
cout<<"\nMASUKKAN NAMA "<<endl;
cout<<"Nama Depan : ";
cin>>wrg[i].i.dp; //salah
cout<<"Nama Tengah : ";
cin>>wrg[i].i.tgh; //salah
cout<<"Nama Belakang : ";
cin>>wrg[i].i.blk; //salah
cout<<"Masukan NIK (10 digit): ";
cin>>wrg[i].nik; //salah
cout<<"\nMASUKKAN TEMPAT - TANGGAL - LAHIR"<<endl;
cout<<"Tempat lahir : ";
cin>>wrg[i].j.tempat; //salah
cout<<"Tanggal lahir : ";
cin>>wrg[i].j.tgl;
cout<<"Bulan lahir : ";
cin>>wrg[i].j.bulan;
cout<<"Tahun lahir : ";
cin>>wrg[i].j.thn;
cout<<"\nMasukan jenis kelamin :";
cin>>wrg[i].jk;
cout<<"\nMASUKKAN ALAMAT "<<endl;
cout<<"Jalan : ";
cin>>wrg[i].k.jl;
cout<<"RT : ";
cin>>wrg[i].k.rt;
cout<<"RW : ";
cin>>wrg[i].k.rw;
cout<<"Desa/Kelurahan : ";
cin>>wrg[i].k.des;
cout<<"Kecamatan : ";
cin>>wrg[i].k.kec;
cout<<"Kab./Kota : ";
cin>>wrg[i].k.kab;
cout<<"=============================================="<<endl;
cout<<endl;
}

for(int a=0;a<x;a++){
cout<<"Warga "<<a+1<<endl;
cout<<"Nama : "<<wrg[a].i.dp<<" "<<wrg[a].i.tgh<<" "<<wrg[a].i.blk<<endl;
cout<<"NIK : "<<wrg[a].nik<<endl;
cout<<"TTL : "<<wrg[a].j.tempat<<" "<<wrg[a].j.tgl<<" "<<wrg[a].j.bulan<<" "<<wrg[a].j.thn<<endl;
cout<<"Jenis Kelamin : "<<wrg[a].jk<<endl;
cout<<"Alamat : Jl."<<wrg[a].k.jl<<" RT."<<wrg[a].k.rt<<" RW."<<wrg[a].k.rw<<" Desa/Kel."<<wrg[a].k.des<<" Kec."<<wrg[a].k.kec<<" Kab./Kota"<<wrg[a].k.kab<<endl;
cout<<"================================================================"<<endl;
cout<<endl;
cout<<endl;
}
}
