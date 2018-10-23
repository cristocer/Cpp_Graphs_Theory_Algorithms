/*
1.From a text file we get the order and the adjency matrix of an unoriented graph.
From another file we get a sequence of vertexes.
Check if the sequence is a chain in the graph.
If possitive check if the chain is elementary or not.
We assume : if the order is p, the vertexes would be 0,1,2,..,p-1.
*/
#include<iostream>
#include<fstream>
using namespace std;
int A[30][30];//matricea de adiacenta
int p;//numarul de varfuri
int B[100];//succesiunea de varfuri/sequence of vertexes
int nr=0;//numarul de varfuri/number check of vertexes 
void citire_matrice_ad();
void afisare_matrice_ad();
void citire_succesiune();//read sequence
void afisare_succesiune();//show sequence
bool este_lant(int v[], int nr);//is chain
bool este_lant_elementar(int v[], int nr);//is elementary chain
int main()
{
    citire_matrice_ad();
    afisare_matrice_ad();
    citire_succesiune();
    afisare_succesiune();
    if(este_lant(B, nr)==true)
    {if(este_lant_elementar(B, nr)==true)
    cout<<"este lant elementar"<<endl;
    else
    cout<<"Nu este elementar"<<endl;}
    else
      cout<<"Nu este lant."<<endl;
}
void citire_matrice_ad()
{
    ifstream f("matrice_adiacenta.in");
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
    ifstream g("varfuri.in");
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
