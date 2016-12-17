#include <iostream>
#include <fstream>
#include <vector>



using namespace std
/*archi inutili per i 30 punti
struct arco{
	int otherEnd;
	bool visited=false;
	int peso;
}
*/
struct citta{
  vector<int> cittaVicine;
  vector<arco> archi;
  int maxDistance;
}

vector<int> grafo;

int main(){

  ifstream in("input.txt");
  ofstream out("output.txt");
  int numeroCitta;
  in>>numeroCitta;
  // matrice delle distanze tra due città qualsiasi
  int [numeroCitta][numeroCitta] matriceDistanze;

  //la riempio di valori -1 che stanno a significare che tra i due nodi i e j non c'è un arco

  for(int i=0;i<numeroCitta;i++){
    for (int j=0;j<numeroCitta;j++){
      matriceDistanze[i][j]=-1;
    }
  }

  // inserisco tutte le città nel grafo e anche gli archi
  int from,to,peso;
  
  for (int i = 0; i < num; i++)
  {	
    in>>from>>to>>peso;
    
    //compilo le posizioni della matrice in cui c'è un arco
    matriceDistanze[to][from]=peso;
    matriceDistanze[from][to]=peso;
  }

  //prendo in input L e i vari delta k

  int numeroIntervalli;
  in>>numeroIntervalli;

  int deltaK[numeroIntervalli];
  
  for (int i = 0; i < numeroIntervalli; i++)
  {
      in>>deltaK[i];
  }

  

}
