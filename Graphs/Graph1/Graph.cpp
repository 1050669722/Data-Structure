//
// Created by ASUS on 2023/5/22.
//

#include "Graph.h"

EdgeNode::EdgeNode(int key)
{
    m_key = key;
    m_weight = 0;
    m_next = nullptr;
}

EdgeNode::EdgeNode(int key, int weight)
{
    m_key = key;
    m_weight = weight;
    m_next = nullptr;
}
