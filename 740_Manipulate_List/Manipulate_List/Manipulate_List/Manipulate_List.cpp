#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node* next; 
    Node* prev ;

    Node() {
        next = NULL;
        prev = NULL;
    }
};


void insert(Node* h, Node* n) {
    Node* h1 = h;
    while (h1->next != NULL)
        h1 = h1->next;

    h1->next = n;
    n->prev = h1;
}

void insertAfter(Node* h, Node* n, int location) {
    Node* h1 = h;
    for(int i=0;i<location;i++)
        h1 = h1->next;

    Node* nextNode = h1->next;

    h1->next = n;
    n->prev = h1;
    n->next = nextNode;
    nextNode->prev = n;
}

void deleteNode(Node* h, int location) {
    Node* h1 = h;
    for (int i = 0; i < location; i++)
        h1 = h1->next;

    Node* nextNode = h1->next;
    Node* prevNode = h1->prev;

    nextNode->prev = prevNode;
    prevNode->next = nextNode;
}

void findNode(Node* h, int location) {
    Node* h1 = h;
    for (int i = 0; i < location; i++)
        h1 = h1->next;

    cout << h1->data;
    cout << "\n";
}

void reverseNode(Node* h, int location1, int location2) {
    Node* h2 = h;
    for (int i = 0; i < location2; i++)
        h2 = h2->next;

    Node* end = h2->next;

    Node* temList = new Node();
    Node* temHead = temList;
    for (int i = 0; i < location2 - location1 + 1; i++) {
        temList->next = h2;
        temList->prev = NULL;
        h2 = h2->prev;
        temList = temList->next;
    }
    temList->next = end;
    temList->prev = NULL;
    temHead = temHead->next;

    Node* h1 = h;
    for (int i = 0; i < location1 - 1; i++)
        h1 = h1->next;

    h1->next = temHead;

    Node* start = h1;
    Node* nextStart = start->next;
    for (int i = 0; i < location2 - location1 + 2; i++) {
        if (nextStart == NULL)
            break;
        nextStart->prev = start;
        start = start->next;
        nextStart = start->next;
    }
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
	
    int size;
    while (cin >> size) {
        Node* head = new Node();

        for (int i = 0; i < size; i++) {
            int num;
            cin >> num;

            Node* newNode = new Node();
            newNode->data = num;
            insert(head, newNode);
        }

        int operation;
        cin >> operation;
        for (int i = 0; i < operation; i++) {
            int move;
            cin >> move;

            if(move == 1){
                int l;
                cin >> l;
                int num;
                cin >> num;

                Node* newNode = new Node();
                newNode->data = num;
                insertAfter(head, newNode, l);
            }
            else if (move == 2) {
                int l;
                cin >> l;

                deleteNode(head, l);
            }
            else if (move == 3) {
                int firstL;
                int secondL;
                cin >> firstL;
                cin >> secondL;

                reverseNode(head, firstL, secondL);
            }
            else if (move == 4) {
                int l;
                cin >> l;

                findNode(head, l);
            }
        }
    }

    return 0;

}

