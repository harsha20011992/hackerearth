#include<iostream>
#include<list>
using namespace std;

class Tree
{
private:
    int N;
    list<int> *adjacencyList;
    int* independentTreeCount;
    bool *visited;

    void addEdge(int v, int w)
    {
        adjacencyList[v-1].push_back(w-1);
        adjacencyList[w-1].push_back(v-1);
    }

    int getNumberOfChildren(int vertex){
      int count = 0;
      for(list<int>::iterator child = adjacencyList[vertex].begin(); child != adjacencyList[vertex].end(); ++child){
          if(!visited[*child]){
              count++;
          }
      }
      return count;
    }

    void calculateIndependentTreeCountForVertex(int v, int p){
        if(p != -1){
          independentTreeCount[v]=independentTreeCount[p] -1 ;
        }
        independentTreeCount[v]+=getNumberOfChildren(v);
    }

    void calculateIndependentTreeCount(int v, int p)
    {
        visited[v] = true;
        calculateIndependentTreeCountForVertex(v, p);
        for(list<int>::iterator i = adjacencyList[v].begin(); i != adjacencyList[v].end(); ++i)
            if(!visited[*i])
                calculateIndependentTreeCount(*i, v);
    }

public:
    Tree(int N)
    {
        this->N = N;
        adjacencyList = new list<int>[N];
        independentTreeCount = new int[N];
        for(int i=0; i<N;i++){
          independentTreeCount[i]=0;
        }
        visited = new bool[N];
        int V,W;
        for (int i=0; i< N-1; i++){
            scanf("%d %d", &V, &W);
            addEdge(V, W);
        }
    }

    void calculateIndependentTreeCount()
    {
        for (int i = 0; i < N; i++)
            visited[i] = false;
        for (int i = 0; i < N; i++)
            if (visited[i] == false)
                calculateIndependentTreeCount(i, -1);
    }

    int getNumberOfIndependentTreesAtVertex(int v){
        return independentTreeCount[v-1];
    }
};
int main()
{

    int N, V, W, Q;
    scanf("%d", &N);
    Tree tree(N);
    tree.calculateIndependentTreeCount();
    scanf("%d", &Q);
    for (int i=0; i< Q; i++){
        scanf("%d", &V);
        printf("%d\n", tree.getNumberOfIndependentTreesAtVertex(V));
    }
    return 0;
}
