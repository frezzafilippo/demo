#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

struct arco{
  int otherEnd;
  bool visited=false;
  int peso;
};

struct nodo{
  vector<int> adj;
  vector<arco> archi;
  int maxDistance;
};

vector<nodo> grafo;


void longestPath(vector<nodo> & grafo,int & start,int & padre,int & figlio, int actual);
int getPeso(int padre,int figlio);


int main(void)
{
  ifstream in("input.txt");
  ofstream out("output.txt");
  int N;
  in>>N;
  grafo.resize(N);
  //Lettura del grafo
  for(int i=0;i<N;i++){
    
    int from,to,peso;
    arco arcoDaFrom,arcoDaTo;
    in>>from>>to>>peso;
    
    arcoDaTo.peso=peso;
    arcoDaFrom.peso=peso;
    arcoDaTo.otherEnd=from;
    arcoDaFrom.otherEnd=to;


    grafo[to].adj.push_back(from);
    grafo[from].adj.push_back(to);

    grafo[to].archi.push_back(arcoDaTo);
    grafo[from].archi.push_back(arcoDaFrom);

  }

cout<<"Input fatto"<<endl;

//ora inserisco nell'array numeroIntervalli i L intervalli k per cui richiede la soluzione

int numeroIntervalli;
in>>numeroIntervalli;
vector<int> deltaK;

  
int k;

for (int i = 0; i < numeroIntervalli; i++){
      in>>k;
      deltaK.push_back(k);
    } 


for (int start=0;start<N;start++){
    longestPath(grafo,start,start,start,0);
  }
for (int i = 0; i < N; i++){
  out<<grafo[i].maxDistance<<endl;
  }

  return 0;
}

void longestPath(vector<nodo> & grafo,int & start,int & padre,int & figlio, int actual){
  for (int v:grafo[figlio].adj){
    cout<<"1"<<endl;
    if (v!=padre){
      actual+=getPeso(figlio,v);
      cout<<"2"<<endl;
      if (actual>grafo[start].maxDistance){
        grafo[start].maxDistance=actual;
        cout<<"3"<<endl;
        longestPath(grafo,start,figlio,v,actual);
        cout<<"4"<<endl;
        actual-=getPeso(figlio,v);
        cout<<"5"<<endl;
      }else{
        longestPath(grafo,start,figlio,v,actual);
        cout<<"6"<<endl;
        actual-=getPeso(figlio,v);
        cout<<"7"<<endl;
      }
    } 
  }
}

int getPeso(int padre,int figlio){
  for (arco arc:grafo[padre].archi){
    if (arc.otherEnd==figlio){
      return arc.peso;
    }
  }
}

/*void visit(int n){
  //Se il nodo é stato giá visitato, ignoralo
  if(grafo[n].visited)
    return;
  grafo[n].visited=true;
  //Aumenta il contatore
  count++;
  //Visita tutti i vicini
  for(int v:grafo[n].adj)
    visit(v);
}
*/