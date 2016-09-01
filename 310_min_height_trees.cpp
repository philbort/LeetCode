/*

310. Minimum Height Trees

For a undirected graph with tree characteristics, we can choose any node as the root. 
The result graph is then a rooted tree. 
Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). 
Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. 
You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. 
Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1:

Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3
return [1]

Example 2:

Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5
return [3, 4]

*/

class Solution {
public:
    // Topological sort:
    // The idea is to find and remove the leafs (degree= 1) and approach the
    // root (i.e., opposite of the leaf)

    // time: O(V), space: O(V+E) 
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> leaf;
        if(!n)  return leaf;
        if(n == 1)  { leaf.push_back(0); return leaf; }
        // Hash table with known size
        vector<unordered_set<int>> map(n);
        // Edge list to adjacent list
        for (int i = 0; i < edges.size(); i++) {
            map[edges[i].first].insert(edges[i].second);
            map[edges[i].second].insert(edges[i].first);
        }
        
        // Add all the leafs
        for (int i = 0; i < n; i++) {
            if(map[i].size() == 1)
                leaf.push_back(i);
        }
        
        // Number of the nodes
        int num = n;
        
        // Remove and find new leafs
        // Since a tree has no cycle, we can have at most 2 roots
        while(num > 2) {
            // Next set of leafs
            vector<int> next;
            // For every leaf
            for (int node: leaf) {
                // Find its neighbor
                // Although there is only one neighbor here
                // we have to use an iterator
                // as "int neighbor = map[node]" doesn't work
                for (int neighbor: map[node]) {
                    // Erase the leaf from its neighbor's adjacent list
                    map[neighbor].erase(node);
                    // Reduce neighbor's degree, if it's 1, it's a new leaf
                    if( map[neighbor].size()== 1) {
                        next.push_back(neighbor);
                    }
                }
            }
            // Update the number of remaining nodes
            num -= leaf.size();
            // Update the new leaf for the next iteration
            leaf = next;
        }
        return leaf;
    }
};
