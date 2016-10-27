/*

207. Course Schedule

There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

*/

class Solution {
public:
    //  For BFS, we map the indegree of all the nodes, and we find the
    //  nodes without any prerequisites (i.e., zeroInDegree). We start with 
    //  zeroInDegree and we traverse all the nodes to eliminate their indegrees
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        // If no course to take or no prerequisites, of course we can finish
        if(!numCourses || prerequisites.empty())  
            return true;
            
        // Hash table with known size
        vector<unordered_set<int>> graph(numCourses);   
        
        // Queue for zero indegrees
        queue<int> zeroInDegree;
        // Number of indegrees
        vector<int> InDegree(numCourses, 0);
        
        // Transform edge lists to adjacency lists
        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i].second].insert(prerequisites[i].first);
        }
        
        // Check number of indegrees
        for (int i = 0; i < numCourses; i++) {
            for(int node: graph[i])
                InDegree[node]++;
        }
        
        // Queue the zero indegree courses
        for (int i = 0; i < numCourses; i++) {
            if(InDegree[i] == 0)
                zeroInDegree.push(i);
        }
        
        while(!zeroInDegree.empty()) {
            // The current course
            int course = zeroInDegree.front();
            zeroInDegree.pop();
            // Find all the courses require the current course
            for (int node: graph[course]) {
                // indegree minus 1 for these courses
                InDegree[node]--;
                // If a course doesn't have any indegrees, put it in the queue
                if(InDegree[node] == 0)
                    zeroInDegree.push(node);
            }
        }
        
        // If we still have indegrees for any course, we hace a cycle
        for (int i = 0; i < numCourses; i++) {
            if(InDegree[i] > 0)
                return false;
        }
            
        // Othewsise we don't
        return true;
    }
};


/*

class Solution {
public:
     // For DFS, it will first visit a node, then one neighbor of it, 
     // then one neighbor of this neighbor... and so on. If it meets 
     // a node which was visited in the current process of DFS visit, 
     // a cycle is detected and we will return false. Otherwise it will 
     // start from another unvisited node and repeat this process till 
     // all the nodes have been visited. Note that you should make two 
     // records: one is to record all the visited nodes and the other 
     // is to record the visited nodes in the current DFS visit.
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        // If no course to take or no prerequisites, of course we can finish
        if(!numCourses || prerequisites.empty())  
            return true;
        
        // Hash table with known size
        vector<unordered_set<int>> graph(numCourses);
        
        // All the visited nodes
        vector<bool> visited(numCourses, false);
        // All the visited nodes on the current path
        vector<bool> current(numCourses, false);
        
        // Transform edge lists to adjacency lists
        for(int i = 0; i < prerequisites.size(); i++)
            graph[prerequisites[i].second].insert(prerequisites[i].first);
        
        // Go through all the nodes one by one    
        for(int i = 0; i < numCourses; i++) {
            // If it has a cycle...
            if(dfs_cycle(graph, i, current, visited))
                return false;
        }
        // Otherwise we don't have a cycle
        return true;
    }
private:
    bool dfs_cycle(vector<unordered_set<int>>& graph, int i,
                   vector<bool>& current, vector<bool>& visited) {
        // If we reach a node visited before, we don't have a cycle
        // Like Fibonacci recursion, make sure we don't search the 
        // same node over and over again
        if(visited[i])
            return false;
        // Set the current node to visited
        current[i] = visited[i] = true;
        // Go through all the nodes from the current nodes ("outdegree")
        for(int node:  graph[i]) {
            // If this or any next node is on the current path, we have a cycle
            if(current[node] || dfs_cycle(graph, node, current, visited))
                return true;
        }
        
        // Reset the node to false in the current path,
        // just like the "swap back" in permutation
        current[i] = false;
        
        // Otherwise we don't have a cycle in the current path
        return false;
    }
    
};

*/