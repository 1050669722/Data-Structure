//
// Created by ASUS on 2023/5/21.
//

#ifndef DATA_STRUCTURE_GRAPH_H
#define DATA_STRUCTURE_GRAPH_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <memory>

namespace graph
{
    // void addEdge(std::vector<std::vector<size_t>> *adjPtr, size_t u, size_t v);
    void addEdge(std::shared_ptr<std::vector<std::vector<size_t>>> adjPtr, size_t u, size_t v);
    void explore(const std::vector<std::vector<size_t>> &adj, size_t v,
                 std::shared_ptr<std::vector<bool>> visitedPtr);
    void depth_first_search(const std::vector<std::vector<size_t>> &adj,
                            size_t start);

}

#endif //DATA_STRUCTURE_GRAPH_H
