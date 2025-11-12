/*
ID: shanker3
LANG: JAVA
TASK: castle
*/
import java.util.*;
import java.io.*;
class castle {
   public static void main(String[] args) throws IOException {
      BufferedReader scan = new BufferedReader(new FileReader("castle.in"));
      StringTokenizer dimension = new StringTokenizer(scan.readLine());
      int length = Integer.parseInt(dimension.nextToken());
      int width = Integer.parseInt(dimension.nextToken());
      int[][] castle = new int[width+1][length+1];
      for (int i = 0; i < width; i++) {
         StringTokenizer str = new StringTokenizer(scan.readLine());
         for (int j = 0; j < length; j++) {
            castle[i][j] = Integer.parseInt(str.nextToken());
         }
      }
      scan.close();
      boolean[][] taken = new boolean[width][length];
      int[] sizes = new int[width*length];
      int[][] rooms = new int[width][length];
      int spot = 0;
      int[] xchange = {1,0,-1,0};
      int[] ychange = {0,1,0,-1};
      int[] check = {8,4,2,1};
      for (int i = 0; i < width; i++) {
         for (int j = 0; j < length; j++) {
            if (!taken[i][j]) {
               Stack<int[]> stack = new Stack<int[]>();
               int[] first = {i,j};
               stack.add(first);
               while (true) {
                  if (stack.isEmpty()) {
                     break;
                  }
                  int[] current = stack.pop();
                  if (!taken[current[0]][current[1]]) {
                     int x = current[0];
                     int y = current[1];
                     taken[x][y] = true;
                     sizes[spot]++;
                     rooms[x][y] = spot;
                     int c = castle[x][y];
                     for (int k = 0; k < 4; k++) { 
                        if (c/check[k] == 1) {
                           c -= check[k];
                           continue;
                        }
                        int[] next = {x+xchange[k],y+ychange[k]};
                        if (next[0] >= 0 && next[0] < width && next[1] >= 0 && next[1] < length && !taken[x+xchange[k]][y+ychange[k]]) {
                           stack.push(next);
                        }
                     }
                  }
               }
               spot++;
            }
         }
      }
      String[] order = {"N","E"};
      int[] xc = {0,1};
      int[] yc = {-1,0};
      String wall = "";
      int removeWallSize = 0;
      int largest = 0;
      for (int i = 0; i < length; i++) {
         for (int j = width-1; j >= 0; j--) {
            largest = Math.max(largest,sizes[rooms[j][i]]);
            int room = rooms[j][i];
            for (int k = 0; k < 2; k++) {
               if (i+xc[k] < 0 || i+xc[k] > length-1 || j+yc[k] < 0 || j+yc[k] > width-1) {
                  continue;
               } 
               int room2 = rooms[j+yc[k]][i+xc[k]];
               if (room == room2) {
                  continue;
               }
               if (removeWallSize < sizes[room]+sizes[room2]) {
                  removeWallSize = sizes[room]+sizes[room2];
                  wall = (j+1) + " " + (i+1) + " " + order[k];
               }
            }
         }
      }
      PrintWriter out = new PrintWriter(new File("castle.out"));
      out.println(spot);
      out.println(largest);
      out.println(removeWallSize);
      out.println(wall);
      out.close();
   }
}