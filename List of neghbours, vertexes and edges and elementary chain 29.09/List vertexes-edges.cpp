/*
2. We consider the text file "muchii.in" with the following structure:
On the first line we have p and q the type of the unoriented graph, on the next q lines
q pairs, representing the extremities of the edges.
Build and show the adjency matrix.
*/
#include<iostream>
#include<fstream>
using namespace std;
void constructie_matrice(int A[25][25], int &p);
void afisare_matrice_adiacenta(int A[25][25], int p);
int main()
{
  int p;//ordinul grafului/order of graph
  int A[25][25];//matricea de adiacenta/adjency matrix
  constructie_matrice(A,p);
  afisare_matrice_adiacenta(A,p);

}
void constructie_matrice(int A[25][25], int &p)
{
  int q;
  ifstream f("muchii.in");
  f>>p>>q;
  for(int i=0; i<p; i++)
  for(int j=0; j<p; j++)
  A[i][j]=0; int a, b;
  for(int j=0; j<p; j++)
  {
      f>>a>>b;
      A[a][b]=1;
      A[b][a]=1;}

}
void afisare_matrice_adiacenta(int A[25][25], int p)
{
  for(int i=0; i<p; i++)
  {for(int j=0; j<p; j++)
  cout<<A[i][j]<<" ";
  cout<<endl;}
}
