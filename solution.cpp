#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <list>
#include <set>

using namespace std;


class Graph {

    private:
        int vertices;
        set<int>* neighbours;
        set<int>* neighboursReverse;

        int differentComponentEdges; //count of edges connecting different components (components from condensed graph)
        int condensationVerticesCount;

    public:
        Graph (int vertices)
        {
            this->vertices = vertices;
            differentComponentEdges = 0;
            condensationVerticesCount = 0;
            neighbours = new set<int>[vertices];
            neighboursReverse = new set<int>[vertices];
        }


        Graph (int vertices, set<int>* neighbours, set<int>* neighboursReverse)
        {
            this->vertices = vertices;
            differentComponentEdges = 0;
            condensationVerticesCount = 0;
            this->neighbours = new set<int>[vertices];
            this->neighboursReverse = new set<int>[vertices];

            for (int i = 0; i < vertices; ++i) {
                for (int j : neighboursReverse[i]) {
                    addEdge(j, i);
                }
            }
        }


        ~Graph ()
        {
            delete[] neighbours;
            delete[] neighboursReverse;
        }


        int getVertices ()
        {
            return vertices;
        }


        void addEdge (int start, int end)
        {
            neighbours[start].insert(end);
            neighboursReverse[end].insert(start);
        }


        Graph reverseEdges ()
        {
            return Graph(vertices, neighboursReverse, neighbours);
        }

        int differentComponentEdgesCount ()
        {
            return differentComponentEdges;
        }


        int sourceCount ()
        {
            int cnt = 0;

            for (int i = 0; i < vertices; ++i) {
                if (neighboursReverse[i].empty()) {
                    cnt++;
                }
            }

            return cnt;
        }


        int sinkCount ()
        {
            int cnt = 0;

            for (int i = 0; i < vertices; ++i) {
                if (neighbours[i].empty()) {
                    cnt++;
                }
            }

            return cnt;
        }


        /*
         * princip:
         * 1. prejdem si otoceny (zmenene orientacie hran) graf pomocou DFS a "poznacim si kedy ich uzatvaram" (v mojom pripade davam na stack lebo mi ide len o poradie nie o konkretny cas)
         * 3. zase pustam DFS ale na povodnom grafe - idem od posledneho vrcholu (stack) a tym ze oproti povodnemu su otocene hrany nedostanem sa cez hranu von zo silne suvislej komponenty
         */
        Graph getCondensed ()
        {
            stack<int> stack;
            bool* visited = new bool[vertices];
            int* components = new int[vertices];
            Graph reversed = reverseEdges();

            for (int i = 0; i < vertices; ++i) {
                visited[i] = false;
            }

            for (int i = 0; i < vertices; i++) {
                if (!visited[i]) {
                    reversed.DFS_stack(i, visited, stack);
                }
            }

            for (int i = 0; i < vertices; i++) {
                components[i] = -1;
            }

            while (!stack.empty()) {
                int v = stack.top();
                stack.pop();

                if (components[v] == -1) {
                    DFS(v, components);
                    condensationVerticesCount++;
                }
            }

            Graph condensed = Graph(condensationVerticesCount);

            for (int i = 0; i < vertices; ++i) {
                for (int j : neighbours[i]) {
                    if (components[i] != components[j]) {
                        condensed.addEdge(components[i], components[j]);
                        differentComponentEdges++;
                    }
                }
            }

            delete[] visited;
            delete[] components;

            return condensed;
        }

    private:
        //helper for countCondesationVertices
        void DFS (int v, int* components)
        {
            components[v] = condensationVerticesCount;

            for (int i : neighbours[v]) {
                if (components[i] == -1) {
                    DFS(i, components);
                }
            }
        }

        //helper for countCondensationVertices
        void DFS_stack (int v, bool visited[], stack<int>& stack)
        {
            visited[v] = true;

            for (int i : neighbours[v]) {
                if (!visited[i]) {
                    DFS_stack(i, visited, stack);
                }
            }

            stack.push(v);
        }
};


int main() {
    int vertices, edges;

    //input loading
    if (scanf("%d %d", &vertices, &edges) != 2) {
        return 1;
    }

    Graph graph = Graph(vertices);

    for (int i = 0; i < edges; ++i) {
        int start, end;

        if (scanf("%d %d", &start, &end) != 2) {
            return 1;
        }

        graph.addEdge(start, end);
    }

    //calculations
    Graph condensed = graph.getCondensed();

    //output
    printf("%d %d %d\n", graph.differentComponentEdgesCount(), condensed.sourceCount(), condensed.sinkCount());

    return 0;
}