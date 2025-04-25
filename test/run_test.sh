#!/bin/bash

# Configuration des chemins
BASE_DIR=$(dirname $(readlink -f $0))
SRC_DIR="$BASE_DIR/../sources"
INC_DIR="$BASE_DIR/../includes"

# Compilation des fichiers source
g++ -std=c++23 -isystem "$INC_DIR" -I"$INC_DIR" -c "$SRC_DIR/Graph.cpp" -o "$BASE_DIR/Graph.o"
g++ -std=c++23 -isystem "$INC_DIR" -I"$INC_DIR" -c "$BASE_DIR/graph_test.cpp" -o "$BASE_DIR/graph_test.o"

# Lien des fichiers objets
g++ "$BASE_DIR/Graph.o" "$BASE_DIR/graph_test.o" -L../lib -lgtest -lpthread -o "$BASE_DIR/testMain.out"