/**
 *
 * \file
 * \brief [Depth First Search Algorithm
 * (Depth First Search)](https://en.wikipedia.org/wiki/Depth-first_search)
 *
 * \author [Ayaan Khan](http://github.com/ayaankhan98)
 *
 * \details
 * Depth First Search also quoted as DFS is a Graph Traversal Algorithm.
 * Time Complexity O(|V| + |E|) where V is number of vertices and E
 * is number of m_edges in graph.
 *
 * Application of Depth First Search are
 *
 * 1. Finding connected components
 * 2. Finding 2-(edge or vertex)-connected components.
 * 3. Finding 3-(edge or vertex)-connected components.
 * 4. Finding the bridges of a graph.
 * 5. Generating words in order to plot the limit set of a group.
 * 6. Finding strongly connected components.
 *
 * And there are many more...
 *
 * <h4>Working</h4>
 * 1. Mark all vertices as unvisited first
 * 2. start exploring from some starting vertex.
 *
 *      While exploring vertex we mark the vertex as visited
 *      and start exploring the vertices connected to this
 *      vertex in recursive way.
 *
 */

#include "Graph.h"

/**
 *
 * \namespace graph
 * \brief Graph Algorithms
 *
 */
namespace graph {
/**
 * \brief
 * Adds and edge between two vertices of graph say u and v in this
 * case.
 *
 * @param adjPtr Adjacency list representation of graph
 * @param u first vertex
 * @param v second vertex
 *
 */
    // void addEdge(std::vector<std::vector<size_t>> *adjPtr, size_t u, size_t v) {
    void addEdge(std::shared_ptr<std::vector<std::vector<size_t>>> adjPtr, size_t u, size_t v)
    {
        /*
         *
         * Here we are considering undirected graph that's the
         * reason we are adding v to the adjacency list representation of u
         * and also adding u to the adjacency list representation of v
         *
         */
        // (*adjPtr)[u - 1].push_back(v - 1);
        // (*adjPtr)[v - 1].push_back(u - 1);
        adjPtr->at(u - 1).push_back(v - 1);
        adjPtr->at(v - 1).push_back(u - 1);
    }

/**
 *
 * \brief
 * Explores the given vertex, exploring a vertex means traversing
 * over all the vertices which are connected to the vertex that is
 * currently being explored.
 *
 * @param adj garph
 * @param v vertex to be explored
 * @param visitedPtr already visited vertices
 *
 */
    void explore(const std::vector<std::vector<size_t>> &adj, size_t v,
                 std::shared_ptr<std::vector<bool>> visitedPtr) {
        std::cout << v + 1 << " ";
        // (*visited)[v] = true;
        visitedPtr->at(v) = true;
        for (auto x : adj[v]) {
            // if (!(*visited)[x]) {
            if (!(visitedPtr->at(x))) {
                explore(adj, x, visitedPtr);
            }
        }
    }

/**
 * \brief
 * initiates depth first search algorithm.
 *
 * @param adj adjacency list of graph
 * @param start vertex from where DFS starts traversing.
 *
 */
    void depth_first_search(const std::vector<std::vector<size_t>> &adj,
                            size_t start) {
        size_t vertices = adj.size();

        // std::vector<bool> visited(vertices, false);
        std::shared_ptr<std::vector<bool>> visitedPtr = std::make_shared<std::vector<bool>>(vertices, false);
        explore(adj, start, visitedPtr);
    }
}  // namespace graph

// /** Main function */
// int main() {
//     size_t vertices = 0, m_edges = 0;
//     std::cout << "Enter the Vertices : ";
//     std::cin >> vertices;
//     std::cout << "Enter the Edges : ";
//     std::cin >> m_edges;
//
//     /// creating graph
//     std::vector<std::vector<size_t>> adj(vertices, std::vector<size_t>());
//
//     /// taking input for m_edges
//     std::cout << "Enter the vertices which have m_edges between them : "
//               << std::endl;
//     while (m_edges--) {
//         size_t u = 0, v = 0;
//         std::cin >> u >> v;
//         graph::addEdge(&adj, u, v);
//     }
//
//     /// running depth first search over graph
//     graph::depth_first_search(adj, 2);
//
//     std::cout << std::endl;
//     return 0;
// }