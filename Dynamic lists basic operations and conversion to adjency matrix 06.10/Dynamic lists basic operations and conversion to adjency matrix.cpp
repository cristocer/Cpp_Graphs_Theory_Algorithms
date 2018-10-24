/*
Lists of neighbours(lists of adjency)
1.Calculus of a vertex grade
2.Check if the edge a-b exits
3.Build the adjecncy matrix based on list
4.Calculus of he size of the graph(number of edges)
5.Check for the chain and elementary chain
6.Check if there is a cycle
7.Build the list of neighbours of the complementary graph 
8.Show the edges of the subgraph with vertexes stored in a array s
*/
#include<iostream>
#include<fstream>
using namespace std;
struct nod{ int vecin;
           nod* next;
          };
int p;
int s[30];
nod *L[30];
nod *LC[30];//Listele de vecini ale grafului complementar/complementary graph list
int A[30][30];
int v[30],nr;
void citire_liste();//Read list
void afisare_liste();//Show list
void introducere(nod *&f, int u);//introducem vf u in lista f/add vertex u in list f
void afisare(nod*f);//show neighbours
int grad(int v);//grade of vertex
bool este_muchie(int a, int b);//is edge
void matrice_ad();//adjecncy matrix
void afisare_matrice();//show matix
int dimensiune();//size
bool este_lant(int v[30]);//is chain
void citire_succesiune();//read sequence
void afisare_succesiune();//show sequence
bool este_lant(int v[], int nr);//is chain
bool lant_elementar(int v[], int nr);//is elementary chain
bool este_ciclu(int v[], int nr);//is cycle
bool este_ciclu_elementar(int v[], int nr);//is elementary cycle
void graf_complementar();//complementary graph
void afisare_liste2();//show list2 differently
void afisare_muchii_subgraf()//show edges subgraph
{
    int nr2;
    cout<<"Nr elemente subgraf: ";cin>>nr2;
    for(int i=0;i<nr2;i++)
    cin>>s[i];
    for(int i=0;i<nr2;i++)
    for(int j=0;j<nr2;j++)
    if(este_muchie(s[i],s[j])==true&&i<j)
    cout<<"["<<i<<","<<j<<"]"<<" ";
    cout<<endl;
}
int main()
{
  citire_liste();
  afisare_liste();int a, b;
  cout<<"Gradul varfului a=";cin>>a;cout<<"este: "<<grad(a)<<endl;
  cout<<"Caut muchia"<<endl;cin>>a;
  cin>>b;cout<<"=";
  if(este_muchie(a,b)==true)
  cout<<"este muchie";
  else
  cout<<"nu este muchie"<<endl;
  cout<<endl;
  matrice_ad();
  afisare_matrice();
  cout<<"Dimensiune graf="<<dimensiune()<<endl;
  citire_succesiune();
  afisare_succesiune();
  if(este_lant(v, nr)==true)
  {if(lant_elementar(v, nr)==true)
  cout<<"Este lant elementar"<<endl;
  else
  cout<<"Este lant neelementar"<<endl;}
  else
  cout<<"Nu este lant"<<endl;
  int m, w[30];
  cout<<"nr elemente ciclu: ";
  cin>>m;
  for(int i=0;i<m;i++)
  cin>>w[i];
  if(este_ciclu(w,m)==true)
  {if(este_ciclu_elementar(w,m)==true)
  cout<<"este ciclu elementar"<<endl;
  else
  cout<<"Este ciclu neelementar"<<endl;}
  else
  cout<<"Nu este ciclu"<<endl;
  graf_complementar();
  afisare_liste2();
  afisare_muchii_subgraf();
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
int grad(int v)
{
    int nr=0;
    for(nod*q=L[v];q!=NULL;q=q->next)
    nr++;
    return nr;
}
bool este_muchie(int a, int b)
{
    for(nod*q=L[a];q!=NULL;q=q->next)
    if(q->vecin==b)
    return true;
    return false;
}
void matrice_ad()
{
    for(int i=0;i<p;i++)
    for(int j=0;j<p;j++)
    A[i][j]=0;
    for(int i=0;i<p;i++)
    for(nod*q=L[i];q!=NULL;q=q->next)
    A[i][q->vecin]=1;

}
void afisare_matrice()
{
    for(int i=0;i<p;i++)
    {for(int j=0;j<p;j++)
    cout<<A[i][j]<<" ";
    cout<<endl;}
}
int dimensiune()
{
    int nr=0;
    for(int i=0;i<p;i++)
    for(nod*q=L[i];q!=NULL;q=q->next)
    nr++;
    return nr;
}
void citire_succesiune()
{
    ifstream f("succesiune.in");
    while(f>>v[nr])
    {nr++;}
}
void afisare_succesiune()
{
    cout<<"Afisare succesiune:"<<endl;
    for(int i=0;i<nr;i++)
    cout<<v[i]<<" ";
    cout<<endl;
}
bool este_lant(int v[], int nr)
{
    for(int i=0;i<nr-1;i++)
    if(este_muchie(v[i],v[i+1])==false)
    return false;
    return true;
}
bool lant_elementar(int v[], int nr)
{
    for(int i=0;i<nr;i++)
    for(int j=i+1;j<nr;j++)
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
  {if(este_muchie(v[i],v[i+1])==false)
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
if(lant_elementar(v,nr-1)==true)
return true;
else
return false;}
void graf_complementar()
{
    for(int i=0;i<p;i++)
    for(int j=0;j<p;j++)
    if(este_muchie(i,j)==false&&i!=j)
    introducere(LC[i],j);
}
void afisare_liste2()
{
    for(int i=0; i<p; i++)
    {
        cout<<"Lista vecini ai lui "<<i<<": ";
        afisare(LC[i]);
        cout<<endl;
    }
}
