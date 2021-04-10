Final Project Proposal
(asdutt2-rmorus2-deeyab2) 

Leading Question

Our chosen datasheet comes from the Stanford Large Dataset Collection, from their collection we have chosen the Stanford Web Graph. Using our chosen algorithms we hope to be able to take the data and find out what is the most visited page on Stanford’s website.


Dataset Acquisition and Processing

The datasheet we have chosen comes from the Stanford Large Dataset Collection, from their collection we have chosen the Stanford Web Graph.  The dataset is a Directed data set with 281,903 nodes, 2,312,497 edges, and is a web graph of Stanford.edu website. We plan to download, store, and process our data in smaller chunks. Given that our chosen dataset is comparatively large compared to what we have worked with before, we believe it would be wise to break the data down into smaller sets and test algorithms on each set before deciding what proportion of the total set we are able to run on our machines. One way we plan to account for missing entries in our dataset is code in the capability to count the number of missing slots. If we can perform a count, we can try sorting our columns (both ‘ascending’ and ‘descending’) to see if any missing values exist in your columns, or by filtering our dataset such that we are only looking at records with a missing value. 


Graph Algorithms

The three algorithms we plan on using are :
The graph coloring algorithm as part of the complex/uncovered option. Input could be the nodes of the web graph from the dataset and the output would be some pattern that could be recognised based on the hyperlinks connecting two nodes of what sequence of pages starting from the homepage is being visited. The big-O running time of a general k-colorable greedy coloring algorithm would be O( m + n ) where m denotes the number of edges and n denotes the number of nodes. This would be the target running time we wish to achieve as well. We may also need to look at different characteristics of graph-coloring that could help optimize the running time like the chromatic number.

The covered algorithm we want to make is the shortest-path algorithm: Djikstra’s algorithm.  The input to the algorithm is a directed and weighted graph consisting of 2 or more nodes, generally represented by an adjacency matrix or list,  and a start node. The output will generally be a set of edges depicting the shortest path to each destination node. The big-O running time of Djikstra’s algorithm is in the worst case graph will be a complete graph i.e total edges = n(n-1)/2 where n is the number of vertices therefore in the worst case the run time will be O = nlog(n).

The final algorithm we want to use is the BFS algorithm. The input would be a directed graph, which would be the nodes of the web graph from the dataset, and the output could be the most visited node, as the BFS algorithm keeps track of booleans of each node and is aimed to only be checked once. The big-O running time of BFS is O(V + E) O(V + E) O(V+E), where V is a vertex/node and E is an edge. This would be the ideal running time since each node/edge would be checked once. 


Timeline

Our timeline of completing all the required tasks assigned is as follows:
First, each member will research and shortlist an algorithm and a traversal to develop and on the next meeting the team will finalise a traversal method and two algorithms to use in the final project. 

Next, each team member will work on one of the three outlines separately. At each meeting for the next few weeks before the Mid-Project Check-in, each member will then discuss and collaborate to further optimize the code. Notes taken on rotations by each member can be reviewed bi-weekly. After the Mid-Project Check-in, a meeting will be held to go over any corrections discussed with the project mentor and another schedule will be made to distribute the work, including sections of the Final project report, the final code as well as the final video until the final deadline.

A few weeks before the final deadline, we will get started on the final project video, making sure that our code works and is optimized efficiently. We will review this video with the project mentor as well as review the final project report to make sure there is enough time to make any necessary changes to either of the two deliverables.