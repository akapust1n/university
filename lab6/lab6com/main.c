#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

typedef vector<int> adjacent_t;
typedef vector<adjacent_t> graph_t;

void read_graph(const char * fname, graph_t & g)
{
    ifstream inp(fname);
    int n, m;
    inp >> n >> m;
    g.clear();
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int from, to;
        inp >> from >> to;
        g[from].push_back(to);
    }
}

void write_dot(const char * fname, const graph_t & g)
{
    ofstream out(fname);
    out << "digraph {\n";
    for (size_t i = 0; i < g.size(); ++i) {
        out << "  " << i << ";\n";
    }
    for (size_t v = 0; v < g.size(); ++v) {
        for (size_t u=0;u<v;u++) {
            out << "  " << v << " -> " << u << ";\n";
        }
    }
    out << "}\n";
}

int main()
{
    graph_t g;
    read_graph("input.txt", g);
    write_dot("g.dot", g);
    system("dot g.dot -Tpng -og.png");
}
