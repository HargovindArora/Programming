#include<iostream>
#include<list>
#include<unordered_map>
#include<string>
using namespace std;

class Graph{

    private:

        unordered_map<string, list<pair<string, int>>> l;

    public:

        void addEdge(string x, string y, bool bidir, int weight){

            l[x].push_back(make_pair(y, weight));
            if(bidir){
                l[y].push_back(make_pair(x, weight));
            }
        }

        void printList(){

            for(auto p:l){
                string city = p.first;
                list<pair<string,int>> neighbours = p.second;
                cout << city << " -> ";
                for(auto x:neighbours){
                    string dest = x.first;
                    int weight = x.second;
                    cout << dest << " " << weight << ", ";
                }
                cout << endl;
            }

        }
};

int main(){

    Graph g;
    g.addEdge("A", "B", true, 20);
    g.addEdge("A", "C", true, 10);
    g.addEdge("C", "B", false, 30);
    g.addEdge("C", "D", true, 25);
    g.addEdge("D", "B", true, 35);
    g.printList();

    return 0;
}