/*
ID: shanker3
LANG: JAVA
TASK: frac1
*/
import java.util.*;
import java.io.*;
class frac1 {
   public static void main(String[] args) throws IOException {
      BufferedReader scan = new BufferedReader(new FileReader("frac1.in"));
      StringTokenizer num = new StringTokenizer(scan.readLine());
      scan.close();
      int n = Integer.parseInt(num.nextToken());
      ArrayList<Fraction> fractions = fractions(n);
      Collections.sort(fractions);
      PrintWriter out = new PrintWriter(new File("frac1.out"));
      for (int i = 0; i < fractions.size(); i++) {
         out.println(fractions.get(i));
      }
      out.close();
      
   }
   public static ArrayList<Fraction> fractions(int n) {
      HashSet<Fraction> fraction = new HashSet();
      ArrayList<Double> taken = new ArrayList();
      fraction.add(new Fraction(0,1));
      taken.add(0.0);
      for (int i = 1; i < n; i++) { 
         for (int j = i+1; j < n+1; j++) {
            if (!taken.contains((double)(i)/j)) {
               fraction.add(new Fraction(i,j));
               taken.add((double)(i)/j);
            }
         }
      }
      fraction.add(new Fraction(1,1));
      ArrayList<Fraction> f = new ArrayList<Fraction>(fraction);
      return f;
   }
}
class Fraction implements Comparable<Fraction>{
   int num;
   int denom;
   
   public Fraction(int num, int denom) {
      this.num = num;
      this.denom = denom;
   }
   
   public int compareTo(Fraction other) {
      double f1 = (double)(num)/denom;
      double f2 = (double)(other.num)/other.denom;
      if (f1 > f2) {
         return 1;
      }
      else if (f1 < f2) {
         return -1;
      }
      else {
         return 0;
      }
   }
   
   public String toString() {
      return num+"/"+denom;
   }
}