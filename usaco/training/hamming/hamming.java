/*
ID: shanker3
LANG: JAVA
TASK: hamming
*/
import java.util.*;
import java.io.*;
class hamming {
   public static void main(String[] args) throws IOException {
      BufferedReader scan = new BufferedReader(new FileReader("hamming.in"));
      StringTokenizer nums = new StringTokenizer(scan.readLine());
      int N = Integer.parseInt(nums.nextToken());
      int B = Integer.parseInt(nums.nextToken());
      int D = Integer.parseInt(nums.nextToken());
      ArrayList<Integer> ans = new ArrayList();
      scan.close();
      for(int i = 0; i < Math.pow(2,B); i++) {
         if (ans.size() == N) break;
         String binary = Integer.toBinaryString(i);
         int len = binary.length();
         for(int j = 0; j < B-len; j++) {
            binary = "0" + binary;
         }
         boolean correct = true;   
         for(int j = 0; j < ans.size(); j++) {
            String compare =  Integer.toBinaryString(ans.get(j));
            int len1 = compare.length();
            for(int k = 0; k < B-len1; k++) {
               compare = "0" + compare;
            }
            int d = 0;
            for(int k = 0; k < B; k++) {
               if (binary.charAt(k) != compare.charAt(k)) {
                  d++;
               }
            }
            if (d < D) {
               correct = false;
            }
         }
         if (!correct) continue;
         ans.add(i);
      }
      int ind = 0;
      PrintWriter out = new PrintWriter(new File("hamming.out"));
      while(ind < ans.size()) {
         if (ind%10 == 0 && ind != 0) {
            out.print("\n");
         }
         out.print(ans.get(ind));
         if (ind%10 != 9 && ind != ans.size() - 1) {
            out.print(" ");
         }
         ind++;
      }
      out.print("\n");
      out.close();
   }
}