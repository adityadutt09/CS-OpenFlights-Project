#include <iterator>
#include <cmath>
#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "BFS.h"
using namespace cs225;


BFS::BFS() {  
  stack_.push(startPoint_);
}

/**
* Returns an iterator for the traversal starting at the first point.
*/

ImageTraversal::Iterator BFS::begin() {
  /** @todo [Part 1] */
  return 
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */

ImageTraversal::Iterator BFS::end() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator();
}

void BFS::add() {
  
  stack_.push(point);
}


Node BFS::pop() {
  
  Node & n = queue.front();
  queue.pop();
  return n;
}

/**
 * Returns the current Point in the traversal.
 */

Point BFS::peek() const {
  return queue.front();
}

/**
 * Returns true if the traversal is empty.
 */

bool BFS::empty() const {
  
  return queue.empty();
}