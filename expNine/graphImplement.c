#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int adjacencyMatrix[MAX_NODES][MAX_NODES];
int numNodes = 0;
int isDirected = 0; 

struct Node {
    int data;
    struct Node* next;
};

struct Node* adjacencyList[MAX_NODES];


void insertNode() {
    if (numNodes < MAX_NODES) {
        numNodes++;
    } else {
        printf("Graph is at maximum capacity, cannot insert a new node.\n");
    }
}

void insertEdge(int source, int destination) {
    if (source < 1 || source > numNodes || destination < 1 || destination > numNodes) {
        printf("Invalid node indices. Node indices must be between 1 and %d.\n", numNodes);
        return;
    }

    adjacencyMatrix[source - 1][destination - 1] = 1;


    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = destination;
    newNode->next = adjacencyList[source - 1];
    adjacencyList[source - 1] = newNode;

    if (!isDirected) {
        adjacencyMatrix[destination - 1][source - 1] = 1;

        struct Node* reverseNode = (struct Node*)malloc(sizeof(struct Node));
        reverseNode->data = source;
        reverseNode->next = adjacencyList[destination - 1];
        adjacencyList[destination - 1] = reverseNode;
    }
}

// Function to find the adjacent nodes to a given node
void findAdjacentNodes(int node) {
    if (node < 1 || node > numNodes) {
        printf("Invalid node index. Node index must be between 1 and %d.\n", numNodes);
        return;
    }

    printf("Adjacent nodes to Node %d: ", node);
    for (int i = 0; i < numNodes; i++) {
        if (adjacencyMatrix[node - 1][i] == 1) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}

int findDegree(int node) {
    if (node < 1 || node > numNodes) {
        printf("Invalid node index. Node index must be between 1 and %d.\n", numNodes);
        return -1;
    }

    int degree = 0;
    for (int i = 0; i < numNodes; i++) {
        degree += adjacencyMatrix[node - 1][i];
    }
    return degree;
}

int isDirectedGraph() {
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i]) {
                return 1; // Directed graph
            }
        }
    }
    return 0; // Undirected graph
}

int main() {
    int choice;
    int source, destination;
    int node;

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);

    printf("Is the graph directed? (1 for directed, 0 for undirected): ");
    scanf("%d", &isDirected);

    while (1) {
        printf("\nGraph Operations:\n");
        printf("1. Insert a new node\n");
        printf("2. Insert an edge between two nodes\n");
        printf("3. Find adjacent nodes to a given node\n");
        printf("4. Find the degree of a given node\n");
        printf("5. Check whether the graph is directed or undirected\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertNode();
                break;

            case 2:
                printf("Enter source and destination nodes (e.g., 1 2): ");
                scanf("%d %d", &source, &destination);
                insertEdge(source, destination);
                break;

            case 3:
                printf("Enter the node to find adjacent nodes: ");
                scanf("%d", &node);
                findAdjacentNodes(node);
                break;

            case 4:
                printf("Enter the node to find its degree: ");
                scanf("%d", &node);
                int degree = findDegree(node);
                if (degree != -1) {
                    printf("Degree of Node %d: %d\n", node, degree);
                }
                break;

            case 5:
                if (isDirectedGraph()) {
                    printf("The graph is directed.\n");
                } else {
                    printf("The graph is undirected.\n");
                }
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}