#include <stdio.h>
#define MAX 5

int n, m;
int available[MAX];
int maximum[MAX][MAX];
int allocation[MAX][MAX];
int need[MAX][MAX];
int finish[MAX];

void calculateNeed() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            need[i][j] = maximum[i][j] - allocation[i][j];
}

int isSafe() {
    int work[MAX];
    for(int i = 0; i < m; i++)
        work[i] = available[i];
    
    for(int i = 0; i < n; i++)
        finish[i] = 0;

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            if(finish[i] == 0) {
                int canRun = 1;
                for(int j = 0; j < m; j++)
                    if(need[i][j] > work[j]) {
                        canRun = 0;
                        break;
                    }
                
                if(canRun) {
                    for(int j = 0; j < m; j++)
                        work[j] += allocation[i][j];
                    finish[i] = 1;
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
        if(finish[i] == 0) return 0;

    return 1;
}

int main() {
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);

    printf("\nEnter allocation matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);

    printf("\nEnter maximum requirement matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &maximum[i][j]);

    printf("\nEnter available resources:\n");
    for(int j = 0; j < m; j++)
        scanf("%d", &available[j]);

    calculateNeed();

    if(isSafe())
        printf("\nThe system is in a safe state.\n");
    else
        printf("\nThe system is NOT in a safe state.\n");

    return 0;
}