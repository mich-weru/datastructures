#include <stdio.h>

#define MAX_SIZE 100

void display(int arr[], int size) {
    printf("Current Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert(int arr[], int *size, int number, int position) {
    if (*size >= MAX_SIZE) {
        printf("Error: Array is full!\n");
        return;
    }

    if (position < 0 || position > *size) {
        printf("Error: Invalid position!\n");
        return;
    }


    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = number;
    (*size)++;

    printf("Inserted %d at position %d\n", number, position);
}


void delete(int arr[], int *size, int position) {
    if (*size == 0) {
        printf("Error: Array is empty!\n");
        return;
    }

    if (position < 0 || position >= *size) {
        printf("Error: Invalid position!\n");
        return;
    }

    printf("Deleted element: %d\n", arr[position]);

    // Shift elements to the left
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
}


void calculateRectangleArea() {
    float length, width, area;

    // Input length and width
    printf("Enter length of the rectangle: ");
    scanf("%f", &length);
    printf("Enter width of the rectangle: ");
    scanf("%f", &width);

    if (length <= 0 || width <= 0) {
        printf("Error: Length and width must be positive values.\n");
        return;
    }

    area = length * width;
    printf("Area of the rectangle: %.2f\n", area);
}

int main() {
    int arr[MAX_SIZE];
    int size = 0, choice, element, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a number\n");
        printf("2. Delete an number\n");
        printf("3. Display Array\n");
        printf("4. Calculate Rectangle Area\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position (0 to %d): ", size);
                scanf("%d", &position);
                insert(arr, &size, element, position);
                break;

            case 2:
                printf("Enter position to delete (0 to %d): ", size - 1);
                scanf("%d", &position);
                delete(arr, &size, position);
                break;

            case 3:
                display(arr, size);
                break;

            case 4:
                calculateRectangleArea();
                break;

            case 5:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
