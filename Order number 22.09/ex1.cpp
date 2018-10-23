/*
1.in fisierul "numere.in" sunt memorate perechi de numere  nat cu cel mult 9 cifre fiecare.
afisati pe ecran perechea cu cei mai multi divizori comuni.
ex: daca fisierul numere.int memoreaza
18 10
35 210
48 240
25 45
8 24
se va afisa pe ecran: 48,240
*/
/*
In the file "numere.in" there are memorised pairs of natural/unsigned numbers with
9 digits at most. Print out the pair with the greatest number of common divisors.
ex: If the File is:
18 10
35 210
48 240
25 45
8 24
The result: 48,240
*/
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream f("numere.in");
    unsigned a, b;
    unsigned p1, p2, max=0, nr, min;
    while(f>>a>>b)
    {
      if(a>b)
        min=b;
      else
        min=a;
      nr=0;
      for(int d=1;d<=min; d++)
      if(a%d==0 && b%d==0)
      nr++;
      if(nr>max)
         {max=nr;
          p1=a;
          p2=b;}
    }
    cout<<p1<<" "<<p2<<endl;

}
