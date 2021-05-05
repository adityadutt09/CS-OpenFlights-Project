/**
 * @file BFS.h
 */
#pragma once
#include <iterator>
#include <cmath>
#include <list>
#include <queue>
#include "../cs225/PNG.h"

using namespace cs225;

/**
 * A breadth-first search of our Graph 
*/

class BFS{
  public:
  
  BFS();
  
  ImageTraversal::Iterator begin();
  ImageTraversal::Iterator end();
  
  void add();
  Node pop();
  void peek() const;
  bool empty() const;
  
  private:
    std::queue<Node> queue;
    
};


/** Pseudo code
 * BFSTraversal(start_node):
 * visited := a set to store references to all visited nodes

  queue := a queue to store references to nodes we should visit later
  queue.enqueue(start_node)
  visited.add(start_node)

  while queue is not empty:
    current_node := queue.dequeue()

    process current_node
    # for example, print(current_node.value)

    for neighbor in current_node.neighbors:
      if neighbor is not in visited:
        queue.enqueue(neighbor)
        visited.add(neighbor)

*/