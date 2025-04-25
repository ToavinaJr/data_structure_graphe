#include "../includes/Graph.hpp"

void Graph::loadNumberOfNodes(std::ifstream& file) {
    file >> m_numberOfNodes;
    m_adjacencyMatrix.resize(m_numberOfNodes, std::vector<bool>(m_numberOfNodes, false));
}

void Graph::loadAdjacencyMatrix(std::ifstream& file) {
    for (int i(0); i < m_numberOfNodes; ++i) {
        for (int j(0); j < m_numberOfNodes; ++j) {
            bool value;
            file >> value;
            m_adjacencyMatrix[i][j] = value;

            if (value) {
                m_edges.emplace_back(i, j);
            }
        }
    }
}

void Graph::printAdjacencyMatrix() const {
    for (const auto& row : m_adjacencyMatrix) {
        for (const bool &value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::printEdges() const {
    for (const auto& edge : m_edges) {
        std::cout << "(" << edge.first << " -> " << edge.second << ")" << std::endl;
    }
}