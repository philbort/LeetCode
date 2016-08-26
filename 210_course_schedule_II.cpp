/*

210. Course Schedule II

There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. 
To take course 3 you should have finished both courses 1 and 2. 
Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. 
Another correct ordering is[0,2,1,3].

*/

class Solution {
public:
    // BFS, check 207_course_schedule for details
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        if(!numCourses)  
            return vector<int>();
            
        vector<int> result;
        
        // graph with known size
        vector<unordered_set<int>> graph(numCourses);
        
        // Queue for zero indegrees
        queue<int> zeroInDegree;
        // Vector for indegrees
        vector<int> InDegree(numCourses, 0);
        
        // Transform edge lists to adjacency lists
        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i].second].insert(prerequisites[i].first);
        }
        
        // Count the indegrees for each course
        for (int i = 0; i < numCourses; i++) {
            for (int node: graph[i])
                InDegree[node]++;
        }
        
        // Queue the courses with zero indegree
        for (int i = 0; i < numCourses; i++) {
            if (InDegree[i] == 0)
                zeroInDegree.push(i);
        }
        
        while(!zeroInDegree.empty()) {
            // The current course
            int course = zeroInDegree.front();
            zeroInDegree.pop();
            
            result.push_back(course);
            
            // Find all the courses require the current course
            for (int node: graph[course]) {
                // Indegree minus 1 for those courses
                InDegree[node]--;
                // If a course doesn't have any indegrees, put it in the queue
                if(InDegree[node] == 0)
                    zeroInDegree.push(node);
            }
        }
        
        // If we still have indegrees, we hace a cycle
        for (int i = 0; i < numCourses; i++) {
            if (InDegree[i] > 0)
                return vector<int> ();
        }
            
        // Othewsise we don't
        return result;
    }

};

/*  DFS solution:

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(!numCourses)  return vector<int> ();
        
        vector<int> result;
        vector<unordered_set<int>> graph(numCourses);
        vector<bool> visited(numCourses, false);
        vector<bool> current(numCourses, false);
        
        for (int i = 0; i < prerequisites.size(); i++)
            graph[prerequisites[i].second].insert(prerequisites[i].first);
            
        for (int i = 0; i < numCourses; i++) {
            if(dfs_cycle(graph, i, current, visited, result))
                return vector<int> ();
        }
        reverse(result.begin(), result.end());
        return result;
    }
private:
    bool dfs_cycle(vector<unordered_set<int>>& graph, int i,
                   vector<bool>& visited, vector<bool>& current,
                   vector<int> & result) {
     if(visited[i])  return false;
     current[i] = visited[i] = true;
     for(int node: graph[i]) {
         if(current[node] || dfs_cycle(graph, node, visited, current, result))
            return true;
     }  
     result.push_back(i);
     current[i] = false;
     return false;
   }
};

*/