#include<bits/stdc++>
int main()
{
int n,l,i;//n can be of size 10^6
cin>>n;
int ar[n];
for(i=0;i<n;i++)
{
cin>>ar[i];
}
cin>>k; //sum that is needed
bool b[ar[n-1]];
for(i=1;i<ar[n-1];i++)
{
if(ar[l]==i)
{
b[i]=TRUE;
l++;
}
else
b[i]=FALSE;
}
for(i=0;i<n;i++)
{
if(b[k-ar[i])==TRUE)
{
cout<<"present";
return 0;
}
}

cout<<"not present";
return 0;

}
