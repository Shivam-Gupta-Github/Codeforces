import java.util.*;
import java.io.*;

public class Ques {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            String[] firstLine = br.readLine().split(" ");
            int n = Integer.parseInt(firstLine[0]);
            int k = Integer.parseInt(firstLine[1]);

            String[] costStr = br.readLine().split(" ");
            int[] costs = new int[n];
            for (int i = 0; i < n; i++) {
                costs[i] = Integer.parseInt(costStr[i]);
            }

            // Sort the costs
            Arrays.sort(costs);

            int prek[] = new int[n];
            initK(prek, costs, k);

            // Prefix sum array
            long[] prefixSum = new long[n + 1];
            prefixSum[0] = costs[0];
            for (int i = 1; i < n; i++) {
                // prefixSum[i + 1] = prefixSum[i] + costs[i];
                prefixSum[i] = prefixSum[i - 1] + costs[i];
            }

            long[] result = new long[n];

            for (int i = 0; i < n; i++) {
                result[i] = prefixSum[i] - prek[i];
            }

            for (int i = 0; i < n; i++) {
                out.print(result[i] + " ");
            }
            out.println();
        }

        out.flush();
        out.close();
    }

    public static void initK(int prefix[], int[] arr, int k) {
        int n = arr.length;

        for (int i = 0; i < k; i++)
            prefix[i] = 0;

        prefix[k] = arr[0];
        for (int i = k + 1; i < n; i++) {
            prefix[i] = arr[i - k] + prefix[i - k - 1];
        }
        // return prefix;
    }
}