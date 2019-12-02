// Author : FangY
// Date   :
/*******************************************************************************
*Given the head of a graph, return a deep copy (clone) of the graph. Each node in the graph contains a label (int) and a list (List[UndirectedGraphNode]) of its neighbors. There is an edge between the given node and each of the nodes in its neighbors.
*
*
*OJ's undirected graph serialization (so you can understand error output):
*Nodes are labeled uniquely.
*
*We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
*
*
*As an example, consider the serialized graph {0,1,2#1,2#2,2}.
*
*The graph has a total of three nodes, and therefore contains three parts as separated by #.
*
*First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
*Second node is labeled as 1. Connect node 1 to node 2.
*Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
*
*
*Visually, the graph looks like the following:
*
*       1
*      / \
*     /   \
*    0 --- 2
*         / \
*         \_/
*Note: The information about the tree serialization is only meant so that you can understand error output if you get a wrong answer. You don't need to understand the serialization to solve the problem.
*******************************************************************************/
#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
#include<map>
using namespace std;

 //Definition for undirected graph.
 struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode*> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
 };

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return node;
        queue<UndirectedGraphNode*> dfs;
        unordered_set<UndirectedGraphNode*> created_node;
        map<UndirectedGraphNode*,UndirectedGraphNode*> hashmap;
        UndirectedGraphNode* head=new UndirectedGraphNode(node->label);
        UndirectedGraphNode* temp;
        created_node.insert(node);
        dfs.push(node);
        hashmap[node]=head;
        while(!dfs.empty()){
            temp=dfs.front();dfs.pop();
            for(auto pnode=temp->neighbors.begin();pnode!=temp->neighbors.end();pnode++){
                if(created_node.find(*pnode)==created_node.end()){
                    UndirectedGraphNode* new_=new UndirectedGraphNode((*pnode)->label);
                    hashmap[*pnode]=new_;
                    dfs.push(*pnode);
                    created_node.insert(*pnode);
                }
                hashmap[temp]->neighbors.push_back(hashmap[*pnode]);
            }
        }
        return head;
    }
};
int main()
{


}

