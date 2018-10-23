/*
2.fisierul text "permutari.in" contine pe prima linie un nr nat n(1<=n<=1000), iar
pe fiecare dintre urmatoarele n linii cate n numere intregi de cel mult 2 cifre fiecare.
afisati pe ecran nr de ordine al liniilor care reprezinta o permutare a primului sir de numere.
ex: daca fisierul contine
5
4 5 1 2 3
3 4 5 1 8
2 1 5 4 3
1 2 3 5 4
5 6 7 1 2
pe ecran se afiseaza 3,4
*/
/*
2.The text file "permutari.in" has on the first line an unsigned numer n(1<=n<=1000),and
on each of the following n lines, n Integers with 2 digits at most each.
Print on screen the order number of the lines which represent 
a permutation of the first sequence of numbers.
ex: if the file has
5
4 5 1 2 3
3 4 5 1 8
2 1 5 4 3
1 2 3 5 4
5 6 7 1 2
The result  3,4
*/
#include<iostream>
#include<fstream>
using namespace std;
void sorteaza(unsigned A[], unsigned n)
{
    bool sortat;
    do{ sortat=true;
    for(int i=0; i<n-1;i++)
    if(A[i]>A[i+1])
    {
        sortat=false;
        unsigned x=A[i];
        A[i]=A[i+1];
        A[i+1]=x;
    }
    }
 while(sortat==false);
}
int main()
{
    ifstream f("permutari.in");
    unsigned n, A[1000], B[1000];
    f>>n;
    for(int i=0; i<n; i++)
    f>>A[i];
    sorteaza(A, n);
    bool permutare;
    for(int j=2; j<=n;j++)
    {
       permutare=true;
       for(int i=0; i<n; i++)
        f>>B[i];
        sorteaza(B,n);
        for(int i=0; i<n; i++)
        if(A[i]!=B[i])
        {
            permutare=false;
            break;
        }
        if(permutare==true)
        cout<<j<<" ";
    }
    cout<<endl;
}
