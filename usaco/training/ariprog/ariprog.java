/*
ID: shanker3
LANG: JAVA
TASK: ariprog
*/
import java.util.*;
import java.io.*;
class ariprog {
   public static void main(String[] args) throws IOException {
      Scanner scan = new Scanner(new File("ariprog.in"));
      int n = scan.nextInt();
      int m = scan.nextInt();
      scan.close();
      HashMap<Integer, Boolean> bisquares = new HashMap<Integer, Boolean>();
      for (int i = 0; i < m+1; i++) {
         for (int j = 0; j < m+1; j++) {
            bisquares.put(i*i+j*j,true);
         }
      }
      ArrayList<Integer> Bisquares = new ArrayList<Integer>(bisquares.keySet());
      Collections.sort(Bisquares);
      ArrayList<Integer[]> answers = new ArrayList<Integer[]>();
      int max = Bisquares.get(Bisquares.size()-1);
      for (int i = 0; i < Bisquares.size(); i++) {
         int start = Bisquares.get(i);
         for (int j = i+1; j < Bisquares.size(); j++) {
            int second = Bisquares.get(j);
            int difference = second-start;
            if (start + (n - 1)*difference > max) {
               continue;
            }
            boolean isValid = true;
            for (int k = 0; k < n-1; k++) {
               if (!bisquares.containsKey(second + difference*k)) {
                  isValid = false;
                  break;
               }
            }
            if (isValid) {
               Integer[] answer = new Integer[2];
               answer[0] = start;
               answer[1] = difference;
               answers.add(answer);
            }
         }
      }
      int[][] Answers = new int[answers.size()][2];
      for (int i = 0; i < answers.size(); i++) {
         Answers[i][0] = answers.get(i)[0];
         Answers[i][1] = answers.get(i)[1];
      }
      Arrays.sort(Answers, Comparator.comparingDouble(o -> o[1]));
      PrintWriter out = new PrintWriter(new File("ariprog.out"));
      if (Answers.length == 0) {
         out.println("NONE");
      }
      else {
         for (int i = 0; i < Answers.length; i++) {
            out.print(Answers[i][0]);
            out.print(" ");
            out.println(Answers[i][1]);
         }
      }
      out.close();
   }
}