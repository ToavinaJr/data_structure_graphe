#include <gtest/gtest.h>
#include "../includes/Graph.hpp"

class GraphTest : public ::testing::Test {
 protected:
    Graph g;
    
    void SetUp() override {
        std::ifstream test("test_graph.txt");
        g.loadNumberOfNodes(test);
        g.loadAdjacencyMatrix(test);
        std::cout << "Graph loaded for testing." << g.getNumberOfNodes() << std::endl;
        g.exportToDot("output/graph/test_graph.dot");
    }
};

TEST_F(GraphTest, DirectlyConnectedNodes) {
    // Test de nœuds directement connectés
    EXPECT_TRUE(g.isDirectlyConnected(0, 1));
    EXPECT_FALSE(g.isDirectlyConnected(0, 3));
}

TEST_F(GraphTest, IndirectlyConnectedNodes) {
    // Test de nœuds indirectement connectés
    EXPECT_TRUE(g.isIndirectlyConnected(0, 3));  // via 0->1->3
    EXPECT_FALSE(g.isIndirectlyConnected(3, 0)); // graphe orienté
}

TEST_F(GraphTest, InvalidNodes) {
    // Test de nœuds invalides
    ASSERT_DEATH(g.isDirectlyConnected(-1, 0), ".*");
    ASSERT_DEATH(g.isDirectlyConnected(10, 0), ".*");
}

TEST_F(GraphTest, SameNodes) {
    // Test de même nœud
    EXPECT_FALSE(g.isDirectlyConnected(0, 0));
    EXPECT_FALSE(g.isIndirectlyConnected(0, 0));
}

TEST_F(GraphTest, FileLoading) {
    // Test du chargement du fichier
    std::ifstream file("test_graph.txt");
    ASSERT_TRUE(file);
    g.loadNumberOfNodes(file);
    EXPECT_EQ(g.getNumberOfNodes(), 4);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}