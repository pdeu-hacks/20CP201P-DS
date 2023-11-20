#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

// Define the graph using an adjacency list
struct Node {
    int data;
    struct Node* next;
};

struct Node* adjacencyList[MAX_NODES];
int numNodes = 0;

// Function to insert a new node
void insertNode() {
    if (numNodes < MAX_NODES) {
        numNodes++;
    } else {
        printf("Graph is at maximum capacity, cannot insert a new node.\n");
    }
}

// Function to insert an edge between two nodes
void insertEdge(int source, int destination) {
    if (source < 1 || source > numNodes || destination < 1 || destination > numNodes) {
        printf("Invalid node indices. Node indices must be between 1 and %d.\n", numNodes);
        return;
    }

    // Add to the adjacency list
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = destination;
    newNode->next = adjacencyList[source - 1];
    adjacencyList[source - 1] = newNode;
}

// Function to perform Breadth-First Search
void BFS(int startNode) {
    // Initialize an array to keep track of visited nodes
    bool visited[MAX_NODES] = {false};

    // Create a queue for BFS
    int queue[MAX_NODES];
    int front = 0, rear = 0;

    // Mark the start node as visited and enqueue it
    visited[startNode - 1] = true;
    queue[rear++] = startNode;

    while (front < rear) {
        // Dequeue a vertex from the queue
        int current = queue[front++];
        printf("%d ", current);

        // Traverse the adjacency list of the current node
        struct Node* temp = adjacencyList[current - 1];
        while (temp != NULL) {
            int adjacentNode = temp->data;
            if (!visited[adjacentNode - 1]) {
                visited[adjacentNode - 1] = true;
                queue[rear++] = adjacentNode;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int choice;
    int source, destination;
    int startNode;

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);

    while (1) {
        printf("\nGraph Operations:\n");
        printf("1. Insert a new node\n");
        printf("2. Insert an edge between two nodes\n");
        printf("3. Perform BFS traversal\n");
        printf("4. Exit\n");
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
                printf("Enter the start node for BFS: ");
                scanf("%d", &startNode);
                printf("BFS Traversal: ");
                BFS(startNode);
                printf("\n");
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}