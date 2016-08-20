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
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(!numCourses || prerequisites.empty())  
            return true;
        unordered_map<int, multiset<int>> graph;
        vector<bool> visited(numCourses, false);
        vector<bool> current(numCourses, false);
        for(int i = 0; i < prerequisites.size(); i++)
            graph[prerequisites[i].second].insert(prerequisites[i].first);
        for(int i = 0; i < numCourses; i++) {
            if(!visited[i] && dfs_cycle(graph, i, current, visited))
                return false;
        }
        return true;
    }
private:
    bool dfs_cycle(unordered_map<int, multiset<int>>& graph, int i,
                   vector<bool>& current, vector<bool>& visited) {
        if(visited[i])
            return false;
        current[i] = visited[i] = true;
        for(auto it = graph[i].begin(); it != graph[i].end(); it++) {
            if(current[*it] || dfs_cycle(graph, *it, current, visited))
                return true;
        }
        return current[i] = false;
    }
};
