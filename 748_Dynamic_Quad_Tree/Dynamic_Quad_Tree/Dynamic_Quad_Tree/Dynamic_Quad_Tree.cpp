#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct Tree {
	char** image;
	int n;
	Tree(int h) {
		n = h;
		image = new char* [n];
		for (int r = 0; r < n; r++) {
			image[r] = new char[n];
			for (int c = 0; c < n; c++) {
				image[r][c] = -1;
			}
		}
	}
	void setImage(int r, int c, char data) {
		image[r][c] = data;
	}

	char getImage(int r, int c) {
		return image[r][c];
	}

	~Tree() {
		for (int i = 0; i < n; i++) {
			delete[] image[i];
		}
		delete[] image;
	}
};

struct TreeNode {
	int nodeType;
	int numOfNode;
	TreeNode* NW;
	TreeNode* SW;
	TreeNode* SE;
	TreeNode* NE;
	TreeNode(int nodeType) {
		this->nodeType = nodeType;
		numOfNode = 1;
		NW = nullptr;
		SW = nullptr;
		SE = nullptr;
		NE = nullptr;
	}
	int getNodeType() {
		return nodeType;
	}
};

int recurse(Tree* image, TreeNode*& qt, int n) {
	int half = n / 2;
	if (half == 0) {
		if (image->getImage(0, 0) == '0') {
			return 0;
		}
		else {
			return 1;
		}
	}
	Tree* nw = new Tree(half);
	Tree* sw = new Tree(half);
	Tree* se = new Tree(half);
	Tree* ne = new Tree(half);
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			if (r < half && c < half) {
				nw->setImage(r % half, c % half, image->getImage(r, c));
			}
			else if (r < half && c >= half) {
				ne->setImage(r % half, c % half, image->getImage(r, c));
			}
			else if (r >= half && c < half) {
				sw->setImage(r % half, c % half, image->getImage(r, c));
			}
			else if (r >= half && c >= half) {
				se->setImage(r % half, c % half, image->getImage(r, c));
			}
		}
	}
	int recurse_status[4] = {};
	TreeNode* qts[4] = {};
	recurse_status[0] = recurse(nw, qts[0], half);
	recurse_status[1] = recurse(sw, qts[1], half);
	recurse_status[2] = recurse(se, qts[2], half);
	recurse_status[3] = recurse(ne, qts[3], half);

	delete nw;
	delete sw;
	delete se;
	delete ne;

	if (recurse_status[0] == 1 && recurse_status[1] == 1 && recurse_status[2] == 1 && recurse_status[3] == 1) {
		TreeNode* node = new TreeNode(1);
		qt = node;
		return 1;
	}
	else if (recurse_status[0] == 0 && recurse_status[1] == 0 && recurse_status[2] == 0 && recurse_status[3] == 0) {
		TreeNode* node = new TreeNode(0);
		qt = node;
		return 0;
	}
	else {
		TreeNode* node = new TreeNode(2);
		if (recurse_status[0] == 1) {
			TreeNode* node0 = new TreeNode(1);
			node->NW = node0;
			node->numOfNode += node0->numOfNode;
		}
		else if (recurse_status[0] == 0) {
			TreeNode* node0 = new TreeNode(0);
			node->NW = node0;
			node->numOfNode += node0->numOfNode;
		}
		else {
			node->NW = qts[0];
			node->numOfNode += qts[0]->numOfNode;
		}
		if (recurse_status[1] == 1) {
			TreeNode* node1 = new TreeNode(1);
			node->SW = node1;
			node->numOfNode += node1->numOfNode;
		}
		else if (recurse_status[1] == 0) {
			TreeNode* node1 = new TreeNode(0);
			node->SW = node1;
			node->numOfNode += node1->numOfNode;
		}
		else {
			node->SW = qts[1];
			node->numOfNode += qts[1]->numOfNode;
		}
		if (recurse_status[2] == 1) {
			TreeNode* node2 = new TreeNode(1);
			node->SE = node2;
			node->numOfNode += node2->numOfNode;
		}
		else if (recurse_status[2] == 0) {
			TreeNode* node2 = new TreeNode(0);
			node->SE = node2;
			node->numOfNode += node2->numOfNode;
		}
		else {
			node->SE = qts[2];
			node->numOfNode += qts[2]->numOfNode;
		}
		if (recurse_status[3] == 1) {
			TreeNode* node3 = new TreeNode(1);
			node->NE = node3;
			node->numOfNode += node3->numOfNode;
		}
		else if (recurse_status[3] == 0) {
			TreeNode* node3 = new TreeNode(0);
			node->NE = node3;
			node->numOfNode += node3->numOfNode;
		}
		else {
			node->NE = qts[3];
			node->numOfNode += qts[3]->numOfNode;
		}
		qt = node;
		return 2;
	}


}


TreeNode* dynamicInsert(int row, int col, int n, int nodeType) {
	int half = n / 2;
	if (half == 0)
		return new TreeNode(nodeType);
	else {
		TreeNode* node = new TreeNode(2);
		int opponent = nodeType == 0 ? 1 : 0;
		node->nodeType = 2;
		if (row < half && col < half) {
			node->NW = dynamicInsert(row % half, col % half, half, nodeType);
			node->NE = new TreeNode(opponent);
			node->SW = new TreeNode(opponent);
			node->SE = new TreeNode(opponent);
		}
		else if (row < half && col >= half) {
			node->NE = dynamicInsert(row % half, col % half, half, nodeType);
			node->NW = new TreeNode(opponent);
			node->SW = new TreeNode(opponent);
			node->SE = new TreeNode(opponent);
		}
		else if (row >= half && col < half) {
			node->SW = dynamicInsert(row % half, col % half, half, nodeType);
			node->NW = new TreeNode(opponent);
			node->NE = new TreeNode(opponent);
			node->SE = new TreeNode(opponent);
		}
		else if (row >= half && col >= half) {
			node->SE = dynamicInsert(row % half, col % half, half, nodeType);
			node->NW = new TreeNode(opponent);
			node->NE = new TreeNode(opponent);
			node->SW = new TreeNode(opponent);
		}
		node->numOfNode = 1 + node->NW->numOfNode + node->NE->numOfNode + node->SW->numOfNode + node->SE->numOfNode;
		return node;
	}
}
void shrinkNode(TreeNode*& node) {
	if (node->NW->nodeType == node->SW->nodeType && node->SW->nodeType == node->SE->nodeType && node->SE->nodeType == node->NE->nodeType && node->NW->nodeType != 2) {
		node->nodeType = node->NW->nodeType;
		delete node->NW;
		delete node->SW;
		delete node->NE;
		delete node->SE;
		node->NW = nullptr;
		node->SW = nullptr;
		node->NE = nullptr;
		node->SE = nullptr;
	}
}

void dynamicFlip(TreeNode*& node, int row, int col, int n) {

	int half = n / 2;
	if (node == nullptr) {
		return;
	}
	if (node->nodeType == 2) {
		if (row < half && col < half) {
			dynamicFlip(node->NW, row % half, col % half, half);
		}
		else if (row < half && col >= half) {
			dynamicFlip(node->NE, row % half, col % half, half);
		}
		else if (row >= half && col < half) {
			dynamicFlip(node->SW, row % half, col % half, half);
		}
		else if (row >= half && col >= half) {
			dynamicFlip(node->SE, row % half, col % half, half);
		}
		shrinkNode(node);
		if (node->SW != nullptr)
			node->numOfNode = 1 + node->NW->numOfNode + node->NE->numOfNode + node->SW->numOfNode + node->SE->numOfNode;
		else
			node->numOfNode = 1;
	}
	else if (node->nodeType == 0) {
		delete node;
		node = dynamicInsert(row, col, n, 1);
	}
	else if (node->nodeType == 1) {
		delete node;
		node = dynamicInsert(row, col, n, 0);
	}
}



void delete_qtree(TreeNode*& root) {
	if (root == nullptr)
		return;
	delete_qtree(root->NW);
	delete_qtree(root->SW);
	delete_qtree(root->NE);
	delete_qtree(root->SE);
	delete root;
	root = nullptr;
}


class QuadTree {
private:
	TreeNode* root;
public:
	QuadTree(Tree* image, int  size) {
		recurse(image, root, size);
	}
	~QuadTree() {
		delete_qtree(root);
	}
	TreeNode* get_root() {
		return root;
	}
	void updateTree(int row, int col, int n) {
		dynamicFlip(root, row, col, n);
	}
	int count(TreeNode* node) {
		if (node->SE == nullptr)
			return 1;
		return (1 + count(node->NW) + count(node->SW) + count(node->SE) + count(node->NE));
	}
};


void printTree(TreeNode* node) {
	if (node != NULL) {
		printTree(node->NW);
		printTree(node->SW);
		printTree(node->SE);
		printTree(node->NE);
	}
}



int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
	
	int taskNum, k, n;

	cin >> taskNum;
	for (int x = 0; x < taskNum; x++) {
		cin >> k;
		if (k != 0) {
			n = pow(2, k);

			Tree* tree = new Tree(n);



			for (int r = 0; r < n; r++) {
				string word;
				cin >> word;
				for (int c = 0; c < n; c++) {
					tree->setImage(r, c, word.at(c));
				}
			}
			QuadTree* qt = new QuadTree(tree, n);

			int m;
			cin >> m;


			for (int i = 0; i < m; i++) {
				int row, col;
				cin >> row >> col;
				if (tree->getImage(row - 1, col - 1) == '0') {
					tree->setImage(row - 1, col - 1, '1');
				}
				else {
					tree->setImage(row - 1, col - 1, '0');
				}

				qt->updateTree(row - 1, col - 1, n);
				cout << qt->get_root()->numOfNode << endl;
			}

			delete qt;
			delete tree;
		}
		else {
			int theOnlybit;
			cin >> theOnlybit;
			int m;
			cin >> m;
			for (int i = 0; i < m; i++) {
				int row, col;
				cin >> row >> col;
				cout << 1 << endl;
			}
		}
	}
	return 0;

}