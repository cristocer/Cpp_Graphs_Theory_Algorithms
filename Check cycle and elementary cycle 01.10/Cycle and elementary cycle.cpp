/*From a text file we get the adjency matrix of a unoriented graph with p vertexes from 0,1,...p-1
The file has on the first line p value then on the next p lines the adjency matrix.
From another file we get a sequence of numbers.
Check if the sequence  is or not cycle,if so also check if it is an elementary cycle.
*/
#include<iostream>
#include<fstream>
using namespace std;
int A[25][25];//matricea de adiacenta
int p;//numarul de varfuri
int B[100];//succesiunea de varfuri
int nr=0;//numarul de varfuri
void citire_matrice_ad();
void afisare_matrice_ad();
void citire_succesiune();
void afisare_succesiune();
bool este_lant(int v[], int nr);//is chain
bool este_lant_elementar(int v[], int nr);//is elementary chain
bool este_ciclu(int v[], int nr);//is cycle
bool este_ciclu_elementar(int v[], int nr);//is elemtary cycle
int main()
{
    citire_matrice_ad();
    afisare_matrice_ad();
    citire_succesiune();
    afisare_succesiune();
    if(este_ciclu(B,nr)==true)
    {if(este_ciclu_elementar(B,nr)==true)
    cout<<"este ciclu elementar";
    else
    cout<<"este ciclu neelementar";}
    if(este_ciclu(B,nr)==false)
    cout<<"nu este ciclu";
}
void citire_matrice_ad()
{
    ifstream f("matrice.in");
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
void citire_succesiune()
{
    ifstream g("succesiune.in");
    int a;
    while(g>>a)
    {
        B[nr++]=a;
    }
    g.close();
}
void afisare_succesiune()
{
    cout<<"Afisare succesiune: "<<endl;
    for(int i=0; i<nr; i++)
    cout<<B[i]<<" ";
    cout<<endl;
}
bool este_lant(int v[], int nr)
{
    for(int i=0; i<nr-1; i++)
    if(A[v[i]][v[i+1]]==0)
    return false;
    return true;
}
bool este_lant_elementar(int v[], int nr)
{
    for(int i=0; i<nr; i++)
    for(int j=i+1; j<nr; j++)
    if(v[i]==v[j])
    return false;
    return true;
}
bool este_ciclu(int v[], int nr)
{
  int C[25][25]={0};
  if(nr-1<3)
  return false;
  if(v[0]!=v[nr-1])
  return false;
  for(int i=0; i<=nr-2; i++)
  {if(A[v[i]][v[i+1]]==0)
  return false;
  else
  if(C[v[i]][v[i+1]]==1)
  return false;
  else
  {C[v[i]][v[i+1]]=1;
  C[v[i+1]][v[i]]=1;}}
  return true;
}
bool este_ciclu_elementar(int v[], int nr)
{
if(este_lant_elementar(v,nr-1)==true)
return true;
else
return false;}

