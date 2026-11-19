#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// Terminal color codes for attractiveness
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define RESET   "\033[0m"

int n, m; // n = number of processes, m = number of resources
int alloc[10][10], max[10][10], avail[10];
int need[10][10], finish[10];

void input() {
    printf(BLUE "Enter number of processes: " RESET);
    scanf("%d", &n);
    printf(BLUE "Enter number of resources: " RESET);
    scanf("%d", &m);

    printf(YELLOW "\nEnter Allocation Matrix:\n" RESET);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf(YELLOW "\nEnter Maximum Requirement Matrix:\n" RESET);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf(YELLOW "\nEnter Available Resources:\n" RESET);
    for (int j = 0; j < m; j++)
        scanf("%d", &avail[j]);

    // Calculate need matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
}

bool isSafe() {
    int work[10], count = 0;
    bool finishLocal[10] = {false};

    for (int i = 0; i < m; i++)
        work[i] = avail[i];

    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finishLocal[i]) {
                int j;
                for (j = 0; j < m; j++)
                    if (need[i][j] > work[j])
                        break;

                if (j == m) {
                    for (int k = 0; k < m; k++)
                        work[k] += alloc[i][k];

                    finishLocal[i] = true;
                    count++;
                    found = true;
                }
            }
        }
        if (!found)
            break;
    }

    return (count == n);
}

void detectAndRecover() {
    for (int i = 0; i < n; i++)
        finish[i] = 0;

    printf("\n" RED "Checking system safety...\n" RESET);
    sleep(1);

    if (isSafe()) {
        printf(GREEN "\nNo deadlock detected. System is in a safe state.\n" RESET);
    } else {
        printf(RED "\nDeadlock detected!\n" RESET);
        printf(YELLOW "Initiating recovery by terminating one process at a time...\n" RESET);

        for (int i = 0; i < n; i++) {
            // Simulate killing process i
            printf(RED "Terminating Process P%d to recover...\n" RESET, i);
            for (int j = 0; j < m; j++)
                avail[j] += alloc[i][j];
            
            alloc[i][0] = alloc[i][1] = 0; // Reset allocation (assumes max 2 resources for simplicity)
            
            if (isSafe()) {
                printf(GREEN "System recovered by terminating P%d.\n" RESET, i);
                break;
            }
        }
    }
}

int main() {
    printf(BLUE "\n--- DEADLOCK DETECTION AND RECOVERY MINI PROJECT ---\n" RESET);
    input();
    detectAndRecover();
    printf(BLUE "\n--- PROGRAM TERMINATED ---\n" RESET);
    return 0;
}