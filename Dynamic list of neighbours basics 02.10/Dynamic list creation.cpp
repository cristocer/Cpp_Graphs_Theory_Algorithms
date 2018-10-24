#include<iostream>
#include<fstream>
using namespace std;
struct nod{ int vecin;
           nod* next;
          };
int p;
nod *L[30];
void citire_liste();//read neighbour list
void afisare_liste();//show created list
void introducere(nod *&f, int u);//introducem vf u in lista f/add u vertex in f list
void afisare(nod*f);//show vertex
int main()
{
  citire_liste();
  afisare_liste();
}
void citire_liste()
{
    ifstream f("liste_vecini.in");
    f>>p;int nr, u;
    for(int i=0;i<p;i++)
    {
        //creez lista L[i]
        f>>nr;
        for(int j=1; j<=nr; j++)
        {
            f>>u;
            introducere(L[i],u);
        }
    }
}
void afisare_liste()
{
    for(int i=0; i<p; i++)
    {
        cout<<"Lista vecini ai lui "<<i<<": ";
        afisare(L[i]);
        cout<<endl;
    }
}
void introducere(nod *&f, int u)
{
    try{
    if(f==NULL)
    {
        f=new nod;
        f->next=NULL;
        f->vecin=u;
    }
    else
    {
      nod*p=new nod;
      p->vecin=u;
      p->next=f;
      f=p;
    }
    }
    catch(bad_alloc)
    {
        cout<<"eroare la alocare"<<endl;
    }
}
void afisare(nod *f)
{
    if(f==NULL)
    cout<<" fara vecini";
    else
    for(nod*p=f;p!=NULL;p=p->next)
    cout<<p->vecin<<" ";
}
