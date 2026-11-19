import java.util.Arrays;

public class TSPBacktracking {

    // Recursive function to find the minimum cost
    static void findShortestRoute(int[][] cost, boolean[] visited,
                                  int currPos, int n, int count,
                                  int costSoFar, int[] minCost) {

        // If all cities are visited and we can return to start
        if (count == n && cost[currPos][0] != 0) {
            minCost[0] = Math.min(minCost[0], costSoFar + cost[currPos][0]);
            return;
        }

        // Try all possible next cities
        for (int i = 0; i < n; i++) {
            if (!visited[i] && cost[currPos][i] != 0) {
                visited[i] = true;
                findShortestRoute(cost, visited, i, n, count + 1,
                                  costSoFar + cost[currPos][i], minCost);
                visited[i] = false; // Backtrack
            }
        }
    }

    // Main function to solve TSP
    static int tsp(int[][] cost) {
        int n = cost.length;
        boolean[] visited = new boolean[n];
        Arrays.fill(visited, false);
        visited[0] = true; // Start from city 0

        int[] minCost = { Integer.MAX_VALUE };

        findShortestRoute(cost, visited, 0, n, 1, 0, minCost);

        return minCost[0];
    }

    public static void main(String[] args) {
        int[][] cost = {
            { 0, 10, 15, 20 },
            { 10, 0, 35, 25 },
            { 15, 35, 0, 30 },
            { 20, 25, 30, 0 }
        };

        int result = tsp(cost);
        System.out.println("Minimum cost to visit all cities: " + result);
    }
}