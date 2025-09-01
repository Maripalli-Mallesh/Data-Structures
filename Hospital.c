#include <stdio.h>
#include <string.h>
int val;

typedef struct {
    char name[100];
    int pri;
} patient;

int f = -1, r = -1;

int EnQueue(patient q[], char d[], int p) {
    if (r == val - 1) {
        printf("\nOverflow");
        return -1;
    } else {
        if (f == -1) {   // first insertion
            f = r = 0;
            strcpy(q[r].name, d);
            q[r].pri = p;
            return 0;
        }
        int i;
        for (i = r; i >= f; i--) {
            if (q[i].pri > p) {
                q[i + 1] = q[i];
            } else {
                break;
            }
        }
        strcpy(q[i + 1].name, d);
        q[i + 1].pri = p;
        r++;
        return 0;
    }
}

void DeQueue() {
    if (f == -1) {
        printf("\nUnderflow");
    } else {
        f++;
        if (f > r) {
            f = r = -1;
        }
    }
}

void Display(patient q[]) {
    if (f == -1) {
        printf("\nQueue is empty");
        return;
    }
    printf("\nPatients in Queue:\n");
    for (int i = f; i <= r; i++) {
        printf("%s ", q[i].name);
    }
	printf("\n");
}

int main() {
	printf("Enter the Hospital Capacity: ");
	scanf("%d",&val);
    patient q[val];
    int k = 0;
    char d[100], tem[100];
    int p, op;

    while (1) {
        printf("\n1:EnQueue\n2:DeQueue\n3:Display\n4:F & R Values\n5:Exit\nEnter Option: ");
        scanf("%d", &op);

        switch (op) {
        case 1:
            printf("Enter (PatientName Severity): ");
            scanf("%s %s", d, tem);

            if (strcmp(tem, "Critical") == 0)
                p = 1;
            else if (strcmp(tem, "Serious") == 0)
                p = 2;
            else if (strcmp(tem, "Normal") == 0)
                p = 3;
            else {
                printf("Invalid severity!\n");
                break;
            }

            EnQueue(q, d, p);
            break;

        case 2:
            DeQueue();
            break;

        case 3:
            Display(q);
            break;

        case 4:
            printf("\nf=%d, r=%d\n", f, r);
            break;

        case 5:
            k = 1;
            break;

        default:
            printf("\nInvalid Input");
        }
        if (k == 1) {
            break;
        }
    }
    return 0;
}
