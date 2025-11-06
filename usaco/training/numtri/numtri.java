/*
ID: shanker3
LANG: JAVA
TASK: numtri
*/
import java.util.*;
import java.io.*;
class numtri {
   public static void main(String[] args) throws IOException {
      BufferedReader scan = new BufferedReader(new FileReader("numtri.in"));
      int length = Integer.parseInt(scan.readLine());
      int[][] tree = new int[length][length];
      for (int i = 0; i < length; i++) {
         StringTokenizer str = new StringTokenizer(scan.readLine());
         for (int j = 0; j < i+1; j++) {
            tree[i][j] = Integer.parseInt(str.nextToken());
         }
      }
      scan.close();
      for (int i = length-1; i > 0; i--) {
         for (int j = 0; j < i; j++) {
            tree[i-1][j] += Math.max(tree[i][j], tree[i][j+1]);
         }
      }
      PrintWriter out = new PrintWriter(new File("numtri.out"));
      out.println(tree[0][0]);
      out.close();
   }
}