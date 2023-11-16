#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_PATIENTS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Medicine;

typedef struct {
    char name[50];
    int age;
    char gender;
    char diagnosis[100];
} Patient;

Medicine medicines[MAX_MEDICINES];
Patient patients[MAX_PATIENTS];

int numMedicines = 0;
int numPatients = 0;

void addMedicine() {
    if (numMedicines < MAX_MEDICINES) {
        printf("Enter medicine name: ");
        scanf("%s", medicines[numMedicines].name);
        printf("Enter quantity: ");
        scanf("%d", &medicines[numMedicines].quantity);
        printf("Enter price: ");
        scanf("%f", &medicines[numMedicines].price);
        numMedicines++;
        printf("Medicine added successfully!\n");
    } else {
        printf("Maximum limit for medicines reached.\n");
    }
}

void addPatient() {
    if (numPatients < MAX_PATIENTS) {
        printf("Enter patient name: ");
        scanf("%s", patients[numPatients].name);
        printf("Enter age: ");
        scanf("%d", &patients[numPatients].age);
        printf("Enter gender (M/F): ");
        scanf(" %c", &patients[numPatients].gender);
        printf("Enter diagnosis: ");
        scanf("%s", patients[numPatients].diagnosis);
        numPatients++;
        printf("Patient added successfully!\n");
    } else {
        printf("Maximum limit for patients reached.\n");
    }
}

void searchMedicine() {
    char searchName[50];
    printf("Enter medicine name to search: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < numMedicines; ++i) {
        if (strcmp(medicines[i].name, searchName) == 0) {
            printf("Medicine found!\n");
            printf("Name: %s\nQuantity: %d\nPrice: %.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medicine not found.\n");
    }
}

void displayInventory() {
    printf("Current Medicine Inventory:\n");
    for (int i = 0; i < numMedicines; ++i) {
        printf("Medicine %d:\nName: %s\nQuantity: %d\nPrice: %.2f\n\n", i + 1, medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nMedical Inventory System\n");
        printf("1. Add Medicine\n");
        printf("2. Add Patient\n");
        printf("3. Search Medicine\n");
        printf("4. Display Medicine Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                addPatient();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                displayInventory();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
