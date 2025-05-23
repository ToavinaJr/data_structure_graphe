#pragma once

#include <fstream>
#include <vector>
#include <iostream>


class Graph {
public:
    explicit Graph() = default;
    virtual ~Graph() = default;

    void loadNumberOfNodes(std::ifstream& file);
    void loadAdjacencyMatrix(std::ifstream& file);

    inline int getNumberOfNodes() const { return m_numberOfNodes; }
    void printAdjacencyMatrix() const;
    void printEdges() const ;

    void exportToDot(const std::string& filename) const;
    bool isDirectlyConnected(int node1, int node2 ) const;
    bool isIndirectlyConnected(int node1, int node2) const ;
private:    
    int m_numberOfNodes;
    std::vector<std::vector<bool>> m_adjacencyMatrix;
    std::vector<std::pair<int, int>> m_edges;
};