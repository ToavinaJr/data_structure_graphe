#include <iostream>
#include <fstream>
#include <cstdlib>

#include "../includes/Graph.hpp"

int main() {
    std::string filename("graph");
    std::string pathname("data/" + filename + ".txt");

    std::ifstream file(pathname);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return EXIT_FAILURE;
    }
    
    auto graph = new Graph;
    graph->loadNumberOfNodes(file);
    graph->loadAdjacencyMatrix(file);
    
    // Affichage du graphe dans le console
    graph->printAdjacencyMatrix();
    graph->printEdges();

    // Exportation du graphe au format DOT
    graph->exportToDot("output/graph/" + filename + ".dot");
    
    delete graph;
    graph = nullptr;

    // Closing the file
    file.close();

    // Generer l'image PNG du graphe
    std::string imagePath = "output/images/" + filename + ".png";
    std::string dotPath = "output/graph/" + filename + ".dot";
    std::string script = "dot -Tpng " + dotPath + " -o " + imagePath;
    
    std::system(script.c_str());

    return EXIT_SUCCESS;
}