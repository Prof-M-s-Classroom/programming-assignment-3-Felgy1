[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Jose Ramos

## Description
Briefly describe what your program does and how the code is structured.
My program implements Prim's algorithm to create a Minimum Spanning Tree using an Adjacency Matrix graph and a custom Min Heap. main.cpp creates Graph objects and calls on primMST() to print the Minimum Spanning Tree and its total weight. graph.h hold the implementations of the functions that create the Adjacency Matrix graphs, adds edges, and builds/prints the MST using heap.h, which holds the implementations for functions to add a vertex, extract the smallest key, update/reposition vertex keys, restore heap if violated, and check heaps.

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | log v           |
| Extract Min          | log v           |
| Decrease Key         | log v           |
| Prim’s MST Overall   | v^2 log v       |

_Explain why your MST implementation has the above runtime._
My MST implementation includes a nested loop which is responsible for the n^2 considering it runs depending on the number of vertices. Within those loops, it also calls two heap functions, each which have a time complexity of log n, resulting in an overall time complexity of n^2 log n.

## Test Case Description

Input: 
0-1, 2
0-3, 6
1-2, 3
1-3, 8
1-4, 5
2-4, 7
3-4, 9

Output:
16 as total and smallest weight