//
// Created by ASUS on 2023/5/20.
//

#include <iostream>

#include "Graphs/Graph0/Graph.h"

int main(int argc, char* argv[])
{
    std::cout << "Hello World" << std::endl;

    size_t vertices = 0, edges = 0;
    std::cout << "Enter the Vertices : ";
    std::cin >> vertices;
    std::cout << "Enter the Edges : ";
    std::cin >> edges;

    /// creating graph
    // std::vector<std::vector<size_t>> adj(vertices, std::vector<size_t>());
    std::shared_ptr<std::vector<std::vector<size_t>>> adjPtr = std::make_shared<std::vector<std::vector<size_t>>>(vertices, std::vector<size_t>());

    /// taking input for m_edges
    std::cout << "Enter the vertices which have m_edges between them : "
              << std::endl;
    while (edges--) {
        size_t u = 0, v = 0;
        std::cin >> u >> v;
        // graph::addEdge(&adj, u, v);
        graph::addEdge(adjPtr, u, v);
    }

    /// running depth first search over graph
    graph::depth_first_search(*adjPtr, 2);

    std::cout << std::endl;

    return 0;
}