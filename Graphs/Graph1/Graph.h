//
// Created by ASUS on 2023/5/22.
//

#ifndef DATA_STRUCTURE_GRAPH_H
#define DATA_STRUCTURE_GRAPH_H

#include <vector>
#include <memory>

class EdgeNode
{
public:
    int m_key{};
    int m_weight{};
    std::shared_ptr<EdgeNode> m_next{};
    EdgeNode(int key);
    EdgeNode(int key, int weight);
};

class Graph
{
public:
    Graph();
    ~Graph();
    int insertEdge(int vertexA, int vertexB, bool directed);
    int printGraph();
    int breadthFirstSearch(int vertex);
    int depthFirstSearch(int vertex);
    int findPath(int vertexA, int vertexB);

private:
    std::vector<EdgeNode> m_edges{};
    std::vector<int> m_degrees{};
    int m_numEdges{};
    bool m_directed{};



};

#endif //DATA_STRUCTURE_GRAPH_H
