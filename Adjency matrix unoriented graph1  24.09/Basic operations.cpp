#include<iostream>
#include<fstream>
using namespace std;
int A[30][30];//matricea de adiacenta/adjency matrix
int p;//numarul de varfuri/number of vertexes
void citire_matrice_ad();//read adjency matrix
void afisare_matrice_ad();//show adjency matrix
void afisare_tip();//show type p,q
void afisare_muchii();//show edges
int grad(int v);//calculate grade
void afisare_grade();//show grades
int main()
{
    citire_matrice_ad();
    afisare_matrice_ad();
    afisare_tip();
    afisare_muchii();
    afisare_grade();
}
void citire_matrice_ad()
{
    ifstream f("matriceadiacenta1.in");
    f>>p;
    for(int i=0; i<p; i++)
    for(int j=0; j<p; j++)
    f>>A[i][j];
    f.close();
}
void afisare_matrice_ad()
{
    for(int i=0; i<p; i++)
    {for(int j=0; j<p; j++)
    cout<<A[i][j]<<" ";
    cout<<endl;}
}
void afisare_tip()
{
    int s=0;
    for(int i=0; i<p; i++)
    for(int j=0; j<p; j++)
    s=s+A[i][j];
    int q=s/2;
    cout<<"tip="<<'('<<p<<','<<q<<')'<<endl;
}
void afisare_muchii()
{
   for(int i=0; i<p-1; i++)
   for(int j=i+1; j<p; j++)
   if(A[i][j]==1)
   cout<<"[v"<<i<<",v"<<j<<"]"<<" ";
   cout<<endl;
}
int grad(int v)
{
	 int s=0;
	 for(int i=0;i<p; i++)
	 s=s+A[i][v];
	 return s;
}
void afisare_grade()
{
	  for(int i=0; i<p; i++)
	  cout<<"deg(v"<<i<<")"<<grad(i)<<endl;
}
