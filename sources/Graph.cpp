#include "../includes/Graph.hpp"
#include <cassert>
#include <functional>

void Graph::loadNumberOfNodes(std::ifstream& file) {
    if (!file) {
        std::cerr << "Erreur lors de l'ouverture du fichier !" << std::endl;
        return;
    }

    file >> m_numberOfNodes;
    m_adjacencyMatrix.resize(m_numberOfNodes, std::vector<bool>(m_numberOfNodes, false));
}

void Graph::loadAdjacencyMatrix(std::ifstream& file) {
    if (!file) {
        std::cerr << "Erreur lors de l'ouverture du fichier !" << std::endl;
        return;
    }
    
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

void Graph::exportToDot(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Erreur lors de l'ouverture du fichier DOT !" << std::endl;
        return;
    }

    out << "digraph G {\n";
    for (const auto& edge : m_edges) {
        out << "    " << edge.first << " -> " << edge.second << ";\n";
    }
    out << "}" << std::endl;

    out.close();
    std::cout << "Fichier DOT exporté vers " << filename << std::endl;
}

bool Graph::isDirectlyConnected(int node1, int node2 ) const {
    assert(node1 >= 0 && node1 < m_numberOfNodes);
    assert(node2 >= 0 && node2 < m_numberOfNodes);

    return m_adjacencyMatrix[node1][node2];    
}

bool Graph::isIndirectlyConnected(int node1, int node2) const {
    assert(node1 >= 0 && node1 < m_numberOfNodes);
    assert(node2 >= 0 && node2 < m_numberOfNodes);
    
    // Vérification de la connexion directe
    if (isDirectlyConnected(node1, node2)) return true;

    // Exploration en profondeur pour trouver une connexion indirecte
    std::vector<bool> visited(m_numberOfNodes, false);
    
    std::function<bool(int)> dfs = [&](int current) {
        visited[current] = true;
        
        // Explorer tous les voisins du nœud actuel
        for (int i = 0; i < m_numberOfNodes; ++i) {
            if (!visited[i] && m_adjacencyMatrix[current][i]) {
                if (i == node2) return true;  // Si on atteint le nœud 2
                if (dfs(i)) return true;     // Poursuite de la recherche
            }
        }
        
        return false;
    };
    
    return dfs(node1);
}
