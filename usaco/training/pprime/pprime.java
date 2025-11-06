/*
ID: shanker3
LANG: JAVA
TASK: pprime
*/
import java.util.*;
import java.io.*;
class pprime {
   public static void main(String[] args) throws IOException {
      BufferedReader scan = new BufferedReader(new FileReader("pprime.in"));
      StringTokenizer firstLine = new StringTokenizer(scan.readLine());
      int lower = Integer.parseInt(firstLine.nextToken());
      int upper = Integer.parseInt(firstLine.nextToken());
      scan.close();
      Set<Integer> ppalindromes = new HashSet<Integer>();
      for (int i = 0; i < 10; i++) {
         for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
               for (int l = 0; l < 10; l++) {
                  for (int m = 0; m < 10; m++) {
                     String palindrome = Integer.toString(i)+Integer.toString(j)+Integer.toString(k)+Integer.toString(l)+Integer.toString(m)+Integer.toString(l)+Integer.toString(k)+Integer.toString(j)+Integer.toString(i);
                     String palindrome1 = Integer.toString(i)+Integer.toString(j)+Integer.toString(k)+Integer.toString(l)+Integer.toString(l)+Integer.toString(k)+Integer.toString(j)+Integer.toString(i);
                     while (true) {
                        if (palindrome.length() < 2) {
                           break;
                        }
                        if (palindrome.charAt(0) == '0') {
                           palindrome = palindrome.substring(1,palindrome.length()-1);
                        }
                        else {
                           break;
                        }
                     }
                     while (true) {
                        if (palindrome1.length() < 2) {
                           break;
                        }
                        if (palindrome1.charAt(0) == '0') {
                           palindrome1 = palindrome1.substring(1,palindrome1.length()-1);
                        }
                        else {
                           break;
                        }
                     }
                     int Palindrome = Integer.parseInt(palindrome);
                     if (Palindrome >= lower && Palindrome <= upper && !primeCheck(Palindrome)) {
                        ppalindromes.add(Palindrome);
                     }
                     if (palindrome1.length() != 0) {
                        int Palindrome1 = Integer.parseInt(palindrome1);
                        if (Palindrome1 >= lower && Palindrome1 <= upper && !primeCheck(Palindrome1)) {
                           ppalindromes.add(Palindrome1);
                        }
                     }                     
                  }
               }
            }
         }
      }
      ArrayList<Integer> list = new ArrayList<Integer>(ppalindromes);
      int[] nums = new int[list.size()];
      for (int i = 0; i < list.size(); i++) {
         nums[i] = list.get(i);
      }
      Arrays.sort(nums);
      PrintWriter out = new PrintWriter(new File("pprime.out"));
      for (int i = 0; i < nums.length; i++) {
         out.println(nums[i]);
      }
      out.close();
   }
   
   public static boolean primeCheck(int num) {
      boolean isPrime = false;
         for (int i = 2; i < (int)(Math.sqrt(num))+1; i++) {
            if (num % i == 0) {
               isPrime = true;
               return isPrime;
            }
         }
      return isPrime;
   }
}