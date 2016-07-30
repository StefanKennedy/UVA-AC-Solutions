// LongestPaths.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

typedef pair<int, int> ii;

struct node {

	int nodeID = -2;
	vector<int> children; // Child ids
	int maxLength = -1;
	int maxEnd = -1;

};

unordered_map<int, node> map;

ii dfs(node n) {

	int max = 0;
	int end = -1;

	if (n.maxLength > 0) {
		return ii(n.maxLength, n.maxEnd);
	}

	for (int i = 0; i < n.children.size(); i++) {

		ii values = dfs(map[n.children[i]]);

		if (values.first > max || (values.first == max && values.second < end)) {
			max = values.first;
			end = values.second;
		}

	}

	if (n.children.size() == 0) {
		end = n.nodeID;
	}

	map[n.nodeID].maxLength = max + 1;
	map[n.nodeID].maxEnd = end;

	ii vals;
	vals.first = map[n.nodeID].maxLength;
	vals.second = end;

	return vals;

}

int main()
{

	vector<string> answers;

	int caseNum = 0;

	while(true) {

		caseNum++;

		map.clear();

		int numNodes;
		cin >> numNodes;

		if (numNodes == 0) {
			break;
		}
		
		int startNodeID;
		cin >> startNodeID;

		node* startNode = new node();

		while (true) {

			int a, b;
			cin >> a >> b;

			if (!a && !b) {

				break;
			}

			if (map.find(a) == map.end()) {
				
				node newNode;
				newNode.children.push_back(b);
				if (map.find(b) == map.end()) {
					map[b].nodeID = b;
				}
				newNode.nodeID = 5;

				map[a] = newNode;

				if (a == startNodeID && (*startNode).nodeID < 0) { // Try to assign startNode if it is not set
					startNode = &map[a];
				}

			}
			else {
				map[a].children.push_back(b);
				if (map.find(b) == map.end()) {
					map[b].nodeID = b;
				}
			}

		}

		// Start search

		ii values = dfs((*startNode));

		if (values.first - 1 == 0) {
			values.second = startNodeID;
		}

		answers.push_back("Case " + to_string(caseNum) + string(": The longest path from ") + to_string(startNodeID) + string(" has length ") + to_string(values.first - 1) + ", finishing at " + to_string(values.second) + ".");

	}

	for (int i = 0; i < answers.size(); i++) {
		cout << answers[i] << endl << endl;
	}

    return 0;
}

