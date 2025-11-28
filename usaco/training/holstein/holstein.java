/*
ID: shanker3
LANG: JAVA
TASK: holstein
*/
import java.util.*;
import java.io.*;
class holstein {
   public static void main(String[] args) throws IOException {
      BufferedReader scan = new BufferedReader(new FileReader("holstein.in"));
      StringTokenizer a = new StringTokenizer(scan.readLine());
      int v = Integer.parseInt(a.nextToken());
      StringTokenizer b = new StringTokenizer(scan.readLine());
      int[] vitamins = new int[v];
      for (int i = 0; i < v; i++) {
         vitamins[i] = Integer.parseInt(b.nextToken());
      }
      StringTokenizer d = new StringTokenizer(scan.readLine());
      int g = Integer.parseInt(d.nextToken());
      int[][] feeds = new int[g][v];
      for (int i = 0; i < g; i++) {
         StringTokenizer e = new StringTokenizer(scan.readLine());
         for (int j = 0; j < v; j++) {
            feeds[i][j] = Integer.parseInt(e.nextToken());
         }
      }      
      scan.close();
      boolean[] sw = new boolean[g];
      for (int i = 0; i < g; i++) {
         sw[i] = false;
      }
      ArrayList<boolean[]> c = new ArrayList();
      c = possible(sw, 0, c);
      Integer[][] sums = new Integer[c.size()][2];
      int m = g;
      for (int i = 0; i < c.size(); i++) {
         sums[i] = computeSum(c.get(i),feeds, vitamins);
         if (sums[i][1] != 0 && sums[i][0] != -1) { 
            m = Math.min(sums[i][1],m); 
         }
      }
      ArrayList<boolean[]> f = new ArrayList();
      ArrayList<Integer> sums2 = new ArrayList();
      for (int i = 0; i < c.size(); i++ ) {
         if (sums[i][1] <= m && sums[i][0] != -1) {
            f.add(c.get(i));
            sums2.add(sums[i][0]);
         }
      }
      int sm = 0;
      for (int i = 0; i < sums2.size(); i++ ) {
         if (sums2.get(i) < sums2.get(sm)) {
            sm = i;
         }
      }
      PrintWriter out = new PrintWriter(new File("holstein.out"));
      out.print(m);
      for (int i = 0; i < f.get(sm).length; i++) {
         if (f.get(sm)[i]) {
            out.print(" "+(i+1));
         }
      }
      out.println();
      out.close();
   }
   public static Integer[] computeSum(boolean[] c, int[][] feeds, int[] vitamins) {
      int v = vitamins.length;
      int[] total = new int[v];
      int s = 0;
      int u = 0;
      for (int i = 0; i < c.length; i++) {
         if (c[i]) {
            u++;
            for (int j = 0; j < v; j++) {
               total[j] += feeds[i][j];
               s += feeds[i][j];
            }
         }
      }
      boolean correct = true;
      for (int i = 0; i < v; i++) {
         if (total[i] < vitamins[i]) {
            correct = false;
         }
      }
      if (!correct) {
         s = -1;
      }
      Integer[] t = {s,u};
      return t;
   }
   public static ArrayList<boolean[]> possible(boolean[] sw, int index, ArrayList<boolean[]> a) {
      if (index == sw.length) {
         boolean[] n = new boolean[sw.length];
         for (int i = 0; i < sw.length; i++) {
            n[i] = sw[i];
         }
         a.add(n);
         return a;
      }
      sw[index] = true;
      possible(sw,index+1,a);
      sw[index] = false;
      possible(sw,index+1,a);
      return a;
   }
}