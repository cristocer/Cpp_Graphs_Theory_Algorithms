/*
3.We consider the file "vecini.in" with the following structure:
On the first line we have p the order of the graph.
On the next p lines there is the grade of a vertex formed by the neighbours of the vertex.
Build and show the adjency matrix.
We assume : if the order is p, the vertexes would be 0,1,2,..,p-1.
*/
#include<iostream>
#include<fstream>
using namespace std;
void constructie_matrice(int A[30][30], int &p)
{
    ifstream f("vecini.in");
    f>>p;
    for(int i=0; i<p; i++)
    for(int j=0; j<p;j++)
    A[i][j]=0;
    for(int i=0;i<p; i++)
    {
        int nr,B[30];
        f>>nr;
        for(int j=0;j<nr; j++)
        {f>>B[j];
        A[i][B[j]]=1;}

    }
    f.close();
}
void afisare_matrice(int A[30][30], int p)
{
    for(int i=0;i<p; i++)
    {
        for(int j=0; j<p; j++)
        cout<<A[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    int p, A[30][30];
    constructie_matrice(A,p);
    afisare_matrice(A,p);

}
