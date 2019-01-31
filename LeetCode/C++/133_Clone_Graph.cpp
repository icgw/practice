/* Given the head of a graph, return a deep cope (clone) of the graph. Each
 * node in the graph conains a `label (int)' and a list 
 * (List[UndirectedGraphNode]) of its `neighbors'. There is an edge between the 
 * given node and each of the nodes in its neighbors.
 *
 * OJ's undirected graph serialization (so you can understand error output):
 * Nodes are labelel uniquely.
 * We use `#' as a separator for each node, and `,' as a separator for node 
 * label and each neighbor of the node.
 *
 * As an example, consider the serialized graph `{0, 1, 2#1, 2#2, 2}'.
 * The graph has a total of three nodes, and therefore contains three parts as
 * separated by `#'.
 * 	1. First node is labeled as `0'. Connect node `0' to both nodes `1' and `2'.
 * 	2. Second node is labeled as `1'. Connect node `1' to node `2'.
 * 	3. Third node is labeled as `2'. Connect node `2' to node `2' (itself), thus
 * 	   forming a self-cycle.
 */ 
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode*> neighbors;
	UndirectedGraphNode(int x) : label(x) {}
};

class Solution {
	public:
		static UndirectedGraphNode* cloneGraph(UndirectedGraphNode *node){
			unordered_map<int, UndirectedGraphNode*> umap;
			return clone(node, umap);
		}

		static UndirectedGraphNode* clone(UndirectedGraphNode *node, 
				unordered_map<int, UndirectedGraphNode*>& umap){
			if (!node) return NULL;
			if (umap.count(node->label)) return umap[node->label];
			UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
			umap[node->label] = newNode;
			vector<UndirectedGraphNode*> *nbrs = &(newNode->neighbors);
			for (auto& nbr : node->neighbors){
				nbrs->push_back(clone(nbr, umap));
			}
			return newNode;
		}
};

int main(int argc, char* argv[]){
	UndirectedGraphNode *node0 = new UndirectedGraphNode(0);
	UndirectedGraphNode *node1 = new UndirectedGraphNode(1);
	UndirectedGraphNode *node2 = new UndirectedGraphNode(2);
	node0->neighbors.push_back(node1); node0->neighbors.push_back(node2);
	node1->neighbors.push_back(node2);
	node2->neighbors.push_back(node2);

	UndirectedGraphNode* copy = Solution::cloneGraph(node0);

	return 0;
}
