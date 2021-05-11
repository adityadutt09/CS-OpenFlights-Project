A two-page proposal which includes: (1) the dataset you are using, with details including source location, format, and how it will be processed. (2) the specific algorithms you have chosen to implement, including their input and output, (3) what final deliverable you will complete to prove your methods have worked and (4) a timeline to accomplish these goals.

We have changed some of our goals from when the project proposal was due. 

Leading Question
Our chosen datasheet used to be the Stanford Web Graph from the Stanford Large Dataset Collection, we have changed the dataset to be the set of airports from OpenFlights. Using our chosen algorithms we hope to be able to take the data and find out what is the fastest path from any two given nodes - one node is a airport's location and coordinates.

Dataset Acquisition and Processing
The datasheet we have chosen comes from the OpenFlights Collection, from their collection we have chosen the first Airport Database.  The dataset has 14110 nodes. We plan to download, store, and process our data in smaller chunks. We will upload it as a file into our VSCode workspace. Given that our chosen dataset is comparatively large compared to what we have worked with before, we believe it would be wise to break the data down into smaller sets and test algorithms on each set before deciding what proportion of the total set we are able to run on our machines. One way we plan to account for missing entries in our dataset is code in the capability to count the number of missing slots. If we can perform a count, we can try sorting our columns (both ‘ascending’ and ‘descending’) to see if any missing values exist in your columns, or by filtering our dataset such that we are only looking at records with a missing value. 

Graph Algorithms
The three algorithms we plan on using are :

The covered algorithm we want to make is the shortest-path algorithm: Djikstra’s algorithm.  The input to the algorithm is a starting node and a target node. The output will generally be a set of edges depicting the shortest path to each destination node. The big-O running time of Djikstra’s algorithm is in the worst case graph will be a complete graph i.e total edges = n(n-1)/2 where n is the number of vertices therefore in the worst case the run time will be O = nlog(n).

The Landmark algorithm as part of the complex/uncovered option. This algorithm finds the fastest path between any two nodes. The input would be the two nodes, or airports from the dataset, in which we want to find the fastest path between. The output would be a string containing the path that is the fastest between the two nodes. The big-O running time of a general Landmark algorithm is about O(nlog(n)), same as Djikstra's. 

The final algorithm we want to use is the BFS algorithm. The input would be a two nodes from the datasets, so two airports, and the output would be the fastest path between those two nodes. The BFS algorithm keeps track of booleans of each node and is aimed to only be checked once. The big-O running time of BFS is O(V + E) O(V + E) O(V+E), where V is a vertex/node and E is an edge. This would be the ideal running time since each node/edge would be checked once. 

Final Deliverable:
We will be implementing these three algorithms in VSCode to make sure they give us the fastest path between any two nodes. There will be a graph class that contains the functions and a main class that asks the user for the two airports they want to find the fastest path between. It would be run by running make and then ./finalproj, and after inputting the two airports, the output will be a string of airports (edges) representing the fastest path between the two airports. 
We will know if our methods have worked if the running time of the program is under 2 minutes and the string of edges that is outputted is the smallest string between the two nodes. 

Timeline
Our timeline of completing all the required tasks assigned is as follows:
First, each member will research and shortlist an algorithm and a traversal to develop and on the next meeting the team will finalise a traversal method and two algorithms to use in the final project. 
Next, each team member will work on one of the three outlines separately. At each meeting for the next few weeks before the Mid-Project Check-in, each member will then discuss and collaborate to further optimize the code. Notes taken on rotations by each member can be reviewed bi-weekly. After the Mid-Project Check-in, a meeting will be held to go over any corrections discussed with the project mentor and another schedule will be made to distribute the work, including sections of the Final project report, the final code as well as the final video until the final deadline.
A few weeks before the final deadline, we will get started on the final project video, making sure that our code works and is optimized efficiently. We will review this video with the project mentor as well as review the final project report to make sure there is enough time to make any necessary changes to either of the two deliverables.