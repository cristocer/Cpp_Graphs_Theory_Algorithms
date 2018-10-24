/*
Lists of edges
1.Check if the edge [x,y] exists.
2.Calculus of a vertex v
3.Build of the adjncey matrix
4.Build of the list of neighbours
5.Check of the chain property
*/
#include<iostream>
#include<fstream>
using namespace std;
int p,q;//tipul grafului/type of graph
struct nod{int a, b;//extremitatile unei muchii/extremities of edges
           nod*next;
};
nod*L;//pointer catre primul nod din lista de muchii/pointer to the head node
struct nod2{int vecin;
           nod2* next;};
void citire();//read
void afisare();//write
void introducere(nod*&L, int x, int y);//insert edge
bool exista_muchia(int x, int y);//edge exist
int grad(int v);//grade
void constructie_matrice();//build of matrix
int A[30][30];
void afisare_matrice();//show matrix
void contructie_liste_vecini();//build list of neighbours
void afisare_liste_vecini();//show list of neigbours
void introducere2(nod*&L, int x);//insert2
nod2*LV[30];
void citire_succesiune();//read sequence
void afisare_succesiune();//show sequence
bool este_lant();//is chain
int v[30], nr=0;
int main()
{
    citire();
    afisare();int a, b, v;
    cout<<"Verificare muchie: ";
    cin>>a>>b;
    if(exista_muchia(a,b)==true)
    cout<<"Muchia exista"<<endl;
    else
    cout<<"Nu exista muchia"<<endl;
    cout<<"Afisare grad varful: ";
    cin>>v;
    cout<<grad(v)<<endl;
    constructie_matrice();
    afisare_matrice();
    contructie_liste_vecini();
    afisare_liste_vecini();
    citire_succesiune();
    afisare_succesiune();
    if(este_lant()==true)
    cout<<"Succesiunea este lant"<<endl;
    else
    cout<<"Nu este succesiune lant"<<endl;
}
void citire()
{
    ifstream f("muchii.txt");
    f>>p>>q; int a, b;
    for(int i=0;i<q;i++)
    {
        f>>a>>b;
        introducere(L,a,b);
    }
}
void introducere(nod*&L, int x, int y)
{
    if(L==NULL)
    {
        L=new nod;
        L->next=NULL;
        L->a=x;
        L->b=y;
    }
    else
    {
        nod*r=new nod;
        r->next=L;
        r->a=x;
        r->b=y;
        L=r;
    }
}
void introducere2(nod2*&L, int x)
{
    if(L==NULL)
    {
        L=new nod2;
        L->next=NULL;
        L->vecin=x;

    }
    else
    {
        nod2*r=new nod2;
        r->next=L;
        r->vecin=x;
        L=r;
    }
}
void afisare()
{
    cout<<"Lista de muchii este: ";
    if(L==NULL)
    cout<<"Nu sunt muchii";
    else
    for(nod*p=L;p!=NULL;p=p->next)
    cout<<"["<<p->a<<","<<p->b<<"] ";
    cout<<endl;
}
bool exista_muchia(int x, int y)
{
  for(nod*p=L;p!=NULL;p=p->next)
  if(p->a==x&&p->b==y|| p->a==y&&p->b==x)
  return true;
  return false;
}
int grad(int v)
{
    int nr=0;
    for(nod*p=L;p!=NULL;p=p->next)
    if(p->a==v||p->b==v)
    nr++;
    return nr;
}
void constructie_matrice()
{
   for(int i=0;i<p;i++)
   for(int j=0;j<p;j++)
   A[i][j]=0;
   for(int i=0;i<p;i++)
   for(int j=0;j<p;j++)
   if(exista_muchia(i,j)==true)
   A[i][j]=1;
}
void afisare_matrice()
{
    for(int i=0;i<p;i++)
    {for(int j=0;j<p;j++)
    cout<<A[i][j]<<" ";
    cout<<endl;}
}
void contructie_liste_vecini()
{
    for(int i=0;i<p;i++)
    for(int j=0;j<p;j++)
    if(exista_muchia(i,j)==true)
    introducere2(LV[i],j);
}
void afisare_liste_vecini()
{
    for(int i=0;i<p;i++)
    {if(LV[i]==NULL)
    cout<<"Nu are vecini";
    else
    for(nod2*r=LV[i];r!=NULL;r=r->next)
    cout<<r->vecin<<" ";
    cout<<endl;}
}
void citire_succesiune()
{
    ifstream f("succesiune.in");
    while(f>>v[nr])
    {
        nr++;
    }
    f.close();
}
void afisare_succesiune()
{
    cout<<"Succesiunea este: "<<endl;
    for(int i=0;i<nr;i++)
    cout<<v[i]<<" ";
    cout<<endl;
}
bool este_lant()
{
    for(int i=0;i<nr-1;i++)
    if(exista_muchia(v[i],v[i+1])==false)
    return false;
    return true;
}
