//Michelle Weru SCT221-0222/2023
//Zaina Muthoni SCT221-0277/2023
#include <stdio.h>
#include <stdlib.h>

#define MAX_TEMPERATURES 100


struct Node {
    float temperatures[MAX_TEMPERATURES];
    int count;
    struct Node* next;
};


struct Node* createNode() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->count = 0;
    newNode->next = NULL;
    return newNode;
}


int insertTemperature(struct Node* node, float temperature) {
    if (node->count < MAX_TEMPERATURES) {
        node->temperatures[node->count++] = temperature;
        return 1;
    }
    return 0;
}


void insertNode(struct Node** head, struct Node* newNode) {
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("Temperatures: ");
        for (int i = 0; i < temp->count; i++) {
            printf("%.2f ", temp->temperatures[i]);
        }
        printf("\n");
        temp = temp->next;
    }
}


int deleteTemperature(struct Node* head, float temperature) {
    int found = 0;
    struct Node* current = head;

    while (current != NULL) {
        for (int i = 0; i < current->count; i++) {
            if (current->temperatures[i] == temperature) {

                for (int j = i; j < current->count - 1; j++) {
                    current->temperatures[j] = current->temperatures[j + 1];
                }
                current->count--;
                found = 1;
                i--;
            }
        }
        current = current->next;
    }
    return found;
}


int main() {
    struct Node* head = NULL;
    int numNodes, numTemperatures, numToDelete;
    float temperatureToDelete;


    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);


    for (int i = 0; i < numNodes; i++) {
        struct Node* newNode = createNode();
        insertNode(&head, newNode);
        printf("Enter the number of temperatures for node %d: ", i + 1);
        scanf("%d", &numTemperatures);

        for (int j = 0; j < numTemperatures; j++) {
            float temp;
            printf("Enter temperature %d: ", j + 1);
            scanf("%f", &temp);
            insertTemperature(newNode, temp);
        }
    }


    printf("\nTemperature List:\n");
    displayList(head);


    printf("Enter the number of temperatures to delete: ");
    scanf("%d", &numToDelete);

    for (int i = 0; i < numToDelete; i++) {
        printf("Enter temperature to delete %d: ", i + 1);
        scanf("%f", &temperatureToDelete);


        if (deleteTemperature(head, temperatureToDelete)) {
            printf("Temperature %.2f deleted.\n", temperatureToDelete);
        } else {
            printf("Temperature %.2f not found.\n", temperatureToDelete);
        }
    }


    printf("\nTemperature List after deletion:\n");
    displayList(head);

    return 0;
}
