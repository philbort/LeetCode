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
    /*  For DFS, it will first visit a node, then one neighbor of it, 
        then one neighbor of this neighbor... and so on. If it meets 
        a node which was visited in the current process of DFS visit, 
        a cycle is detected and we will return false. Otherwise it will 
        start from another unvisited node and repeat this process till 
        all the nodes have been visited. Note that you should make two 
        records: one is to record all the visited nodes and the other 
        is to record the visited nodes in the current DFS visit.
    */
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        // If no course to take or no prerequisites, of course we can finish
        if(!numCourses || prerequisites.empty())  
            return true;
        
        // multiset is faster than unordered_set here, why?
        unordered_map<int, multiset<int>> graph;
        
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
    bool dfs_cycle(unordered_map<int, multiset<int>>& graph, int i,
                   vector<bool>& current, vector<bool>& visited) {
        // If we reach a node visited before, we don't have a cycle
        // Like Fibonacci recursion, make sure we don't search the 
        // same node over and over again
        if(visited[i])
            return false;
        // Set the current node to visited
        current[i] = visited[i] = true;
        // Go through all the nodes from the current nodes ("outdegree")
        for(auto it = graph[i].begin(); it != graph[i].end(); it++) {
            // If this or any next node is on the current path, we have a cycle
            if(current[*it] || dfs_cycle(graph, *it, current, visited))
                return true;
        }
        
        // Reset the node to false in the current path,
        // just like the "swap back" in permutation
        current[i] = false;
        
        // Otherwise we don't have a cycle in the current path
        return false;
    }
    
};

class Solution2 {
public:
    /*  For BFS, we map all the indegree and outdegree edges, and we find the
        nodes without any prerequisites (i.e., zeroInDegree). We start with 
        zeroInDegree and we traverse all the nodes in the InDegree and OutDegree
        hash tables with respect to it.
    */
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        // If no course to take or no prerequisites, of course we can finish
        if(!numCourses || prerequisites.empty())  
            return true;
            
        // Queue for zero indegrees
        queue<int> zeroInDegree;
        // Hash table for indegree and outdegree
        unordered_map<int, unordered_set<int>> inDegree, outDegree;
        // Transform edge lists to adjacency lists
        for (int i = 0; i < prerequisites.size(); i++) {
            inDegree[prerequisites[i].first].insert(prerequisites[i].second);
            outDegree[prerequisites[i].second].insert(prerequisites[i].first);
        }
        // Find if we have zeroInDegree, and put them in the queue
        for (int i = 0; i < numCourses; i++) {
            if(inDegree.find(i) == inDegree.end())
                zeroInDegree.push(i);
        }
        
        while(!zeroInDegree.empty()) {
            // The current course
            int course = zeroInDegree.front();
            zeroInDegree.pop();
            // Find all the courses require the current course
            for (auto it = outDegree[course].begin(); it != outDegree[course].end(); it++) {
                // Erase it from InDegree since we already took it
                inDegree[*it].erase(course);
                // If a course doesn't have any indegrees, put it in the queue
                if(inDegree[*it].empty())
                    zeroInDegree.push(*it);
            }
            // Erase the current course from outdegree
            outDegree.erase(course);
        }
        
        // If we still have outdegree, we hace a cycle
        if(!outDegree.empty())
            return false;
            
        // Othewsise we don't
        return true;
    }
};
