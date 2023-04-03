#include <queue>
#include <iostream>
using namespace std;

int totalNum = 0;

struct MinHeapNode {
    int freq;

    MinHeapNode* left, * right;

    MinHeapNode(int freq)
    {
        left = right = NULL;
        this->freq = freq;
    }
};


struct compare {

    bool operator()(MinHeapNode* l, MinHeapNode* r)

    {
        return (l->freq > r->freq);
    }
};



int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
	
    int size = 0;

    while (cin >> size) {
        totalNum = 0;

        MinHeapNode* left, * right, * mergeNode;

        priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

        for (int i = 0; i < size; i++) {
            int freq;
            cin >> freq;
            minHeap.push(new MinHeapNode(freq));
        }


        while (minHeap.size() != 1) {
            left = minHeap.top();
            minHeap.pop();

            right = minHeap.top();
            minHeap.pop();

            int length = left->freq + right->freq;

            mergeNode = new MinHeapNode(length);

            mergeNode->left = left;
            mergeNode->right = right;

            totalNum += length;

            minHeap.push(mergeNode);
        }

        cout << totalNum;
        cout << "\n";
    }

    return 0;
}
