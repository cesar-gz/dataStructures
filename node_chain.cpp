#include <iostream>
#include <cstdlib> //for random number generation
#include <ctime>
using namespace std;

class Node{
    public:
        int Value;
        Node * Next;
};

void PrintNode(Node * node){
    // it will print the initial node until it finds NULL for
    // the next pointer that indicates the end of the node chain
    while(node != NULL){
        cout << node->Value << " -> ";
        node = node->Next;
    }
    cout << "NULL" << endl;
    }

int main(){
    srand(time(0)); //initialize random number generator

    int randomValue = (rand()%99) + 1; // create a random between 1 and 99
    Node * node1 = new Node;
    node1->Value = randomValue;

    randomValue = (rand()%99) + 1;
    Node * node2 = new Node;
    node2->Value = randomValue;

    randomValue = (rand()%99) + 1;
    Node * node3 = new Node;
    node3->Value = randomValue;

    node1->Next = node2;    //  node1 points to node2
    node2->Next = node3;
    node3->Next = NULL;

    PrintNode(node1);

    return 0;
}