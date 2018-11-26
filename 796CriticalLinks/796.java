import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import static java.util.AbstractMap.SimpleEntry;

// UVA 796 Critical Links

class Main {

  static void findBridges(
      List<Integer>[] adjList, int cur, int[] disc, int[] low, int p, int r,
      List<SimpleEntry<Integer, Integer>> criticalLinks) {
    disc[cur] = p;
    low[cur] = p;

    List<Integer> adjacents = adjList[cur];
    for (Integer adj : adjacents) {
      if (adj == r) {
        continue;
      }
      if (disc[adj] == 0) {
        findBridges(adjList, adj, disc, low, p+1, cur, criticalLinks);
      }
      if (low[adj] < low[cur]) {
        low[cur] = low[adj];
      } else if (low[adj] > disc[cur]) {
        criticalLinks.add(new SimpleEntry(cur, adj));
      }
    }
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    while (scanner.hasNext()) {
      int numServers = scanner.nextInt();
      
      List<Integer>[] adjList = new List[numServers];
      for (int i = 0; i < numServers; i++) {
        int id = scanner.nextInt();
        List<Integer> adjacents = new ArrayList<Integer>();
        adjList[id] = adjacents;
  
        String numConnectionsString = scanner.next();
        int numConnections = Integer.parseInt(
            numConnectionsString.substring(1, numConnectionsString.length()-1));
        for (int j = 0; j < numConnections; j++) {
          adjacents.add(scanner.nextInt());
        }
      }
      
      List<SimpleEntry<Integer, Integer>> criticalLinks
          = new ArrayList<SimpleEntry<Integer, Integer>>();
      int[] low = new int[numServers];
      int[] disc = new int[numServers];
      for (int i = 0; i < numServers; i++) {
        if (disc[i] > 0) {
          continue;
        }
        findBridges(adjList, i, disc, low, 1, i,
                    criticalLinks);
      }
      /*List<Integer> lowList = new ArrayList<Integer>();
      for (int l : low) {
        lowList.add(l);
      }
      System.out.println("low: " + lowList.toString());
      List<Integer> discList = new ArrayList<Integer>();
      for (int d : disc) {
        discList.add(d);
      }
      System.out.println("disc: " + discList.toString());*/
      System.out.println(criticalLinks.size() + " critical links");
      List<SimpleEntry<Integer, Integer>> links
          = new ArrayList<SimpleEntry<Integer, Integer>>();
      for (SimpleEntry<Integer, Integer> link : criticalLinks) {
        if (link.getKey() > link.getValue()) {
          links.add(
            new SimpleEntry<Integer, Integer>(link.getValue(), link.getKey()));
        } else {
          links.add(link);
        }
      }
      Collections.sort(links,
          new Comparator<SimpleEntry<Integer, Integer>>() {
            @Override
            public int compare(SimpleEntry<Integer, Integer> se1,
                               SimpleEntry<Integer, Integer> se2) {
              if (se1.getKey() == se2.getKey()) {
                return se1.getValue() - se2.getValue();
              }
              return se1.getKey() - se2.getKey();
            }
          });
      List<String> ans = new ArrayList<String>();
      for (int i = 0; i < links.size(); i++) {
        SimpleEntry<Integer, Integer> link = links.get(i);
        ans.add(link.getKey() + " - " + link.getValue());
      }
      for (String s : ans) {
        System.out.println(s);
      }
      System.out.println();
    }
  }

}
