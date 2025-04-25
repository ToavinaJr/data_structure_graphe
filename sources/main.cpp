#include <iostream>
#include "../includes/Graph.hpp"
#include <fstream>

int main() {
    std::ifstream file("data/graph.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return EXIT_FAILURE;
    }
    
    // Closing the file
    auto graph = new Graph;
    graph->loadNumberOfNodes(file);
    graph->loadAdjacencyMatrix(file);
    
    graph->printAdjacencyMatrix();
    graph->printEdges();
    
    delete graph;
    file.close();

    return EXIT_SUCCESS;
}