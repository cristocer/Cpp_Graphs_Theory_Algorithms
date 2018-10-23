/*
3.fisierul text "date.in" contine pe prima linie un nr nat n, iar pe fiecare dintre
urmatoarele n linii cate n cifre de 0 sau 1. afisati numerele de ordine ale
liniilor cu aceeasi suma. cifrele nu sunt separate prin spatii, iar n<=1000.
ex: daca fisierul contine
5
11011
10010
00011
10001
11110
se afiseaza 1 5
            2 3 4
*/
/*3.The text file "date.in" has on the first line an unsigned numer n(1<=n<=1000),and
on each of the following n lines, n Integers of 0s or 1s.
Print on screen the order number of the lines with the same sum. 
The digits are not separated by spaces and n<=1000 .
ex: if the file has
5
11011
10010
00011
10001
11110
The result  1 5
            2 3 4
*/
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
 ifstream f("date.in");
 unsigned n;
 f>>n;f.get();
 unsigned A[1000], B[1000];
 for(int i=0; i<n; i++)
 A[i]=0;
 char s[1000];
 int x=0;
 while(!f.eof())
 {
    f.getline(s,1000);
    cout<<s<<endl;
    for(int j=0; s[j]!='\0'; j++)
    if(s[j]=='1')
    A[x]++;
    x++;
}
f.close();
for(int i=0; i<n; i++)
cout<<A[i]<<" ";
cout<<endl;
int m=0;
bool ok;
for(int j=0; j<n; j++)
{ ok=true;
for(int i=0; i<m; i++)
if(B[i]==A[j])
{
    ok=false;break;
}
if(ok==true)
B[m++]=A[j];
}
for(int j=0; j<m; j++)
{for(int i=0; i<n; i++)
if(B[j]==A[i])
cout<<i+1<<" ";
cout<<endl;}
}
