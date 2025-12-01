/*
ID: shanker3
LANG: JAVA
TASK: sort3
*/
import java.util.*;
import java.io.*;
class sort3 {
   public static void main(String[] args) throws IOException {
      BufferedReader scan = new BufferedReader(new FileReader("sort3.in"));
      StringTokenizer amount = new StringTokenizer(scan.readLine());
      int num = Integer.parseInt(amount.nextToken());
      int[] og = new int[num];
      int[] sorted = new int[num]; 
      for (int i = 0; i < num; i++) {
         StringTokenizer n = new StringTokenizer(scan.readLine());
         int a = Integer.parseInt(n.nextToken());
         og[i] = a;
         sorted[i] = a;
      }
      scan.close();
      Arrays.sort(sorted);
      ArrayList<Integer> one = new ArrayList();
      ArrayList<Integer> two = new ArrayList();
      ArrayList<Integer> three = new ArrayList();
      for (int i = 0; i < num; i++) {
         if (sorted[i] == 1 && og[i] != 1) {   
            one.add(og[i]);
         }
         else if (sorted[i] == 2 && og[i] != 2) {
            two.add(og[i]);
         }
         else if (sorted[i] == 3 && og[i] != 3) {
            three.add(og[i]);
         }
      }
      ArrayList<ArrayList<Integer>> a = new ArrayList();
      a.add(one); a.add(two); a.add(three);
      int count = 0;
      for (int i = 0; i < 3; i++) {
         for (int j = 0; j < 3; j++) {
            if (i != j) {
               while (a.get(i).contains(j+1) && a.get(j).contains(i+1)) {
                  a.get(i).remove(new Integer(j+1));
                  a.get(j).remove(new Integer(i+1));
                  count++;
               }
            }
         }
      }   
      int t = one.size()+two.size()+three.size();
      count += 2*(t/3);
      if (t%3 == 2) {
         count += 1;
      } 
      PrintWriter out = new PrintWriter(new File("sort3.out"));
      out.println(count);
      out.close();
   }
}