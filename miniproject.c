#include <stdio.h>
#include <stdbool.h>

#define P 3 // Number of processes
#define R 2 // Number of resources

int allocation[P][R] = {{0, 1}, {2, 0}, {3, 0}};
int max[P][R]        = {{7, 5}, {3, 2}, {9, 0}};
int available[R]     = {3, 2};
bool finish[P] = {false};

bool is_deadlock() {
    int work[R];
    for (int i = 0; i < R; i++)
        work[i] = available[i];

    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < P; i++) {
            if (!finish[i]) {
                bool can_finish = true;
                for (int j = 0; j < R; j++) {
                    if (max[i][j] - allocation[i][j] > work[j]) {
                        can_finish = false;
                        break;
                    }
                }
                if (can_finish) {
                    for (int j = 0; j < R; j++)
                        work[j] += allocation[i][j];
                    finish[i] = true;
                    changed = true;
                }
            }
        }
    }

    for (int i = 0; i < P; i++) {
        if (!finish[i]) return true;
    }
    return false;
}

void recover_deadlock() {
    printf("\nDeadlock detected! Recovering...\n");
    for (int i = 0; i < P; i++) {
        if (!finish[i]) {
            printf("Preempting resources from Process %d\n", i);
            for (int j = 0; j < R; j++)
                available[j] += allocation[i][j];
            finish[i] = true;
        }
    }
    printf("Recovery completed. System is now safe.\n");
}

int main() {
    if (is_deadlock())
        recover_deadlock();
    else
        printf("No deadlock detected.\n");
    return 0;
}