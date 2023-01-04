package pointers;

import java.util.ArrayList;

public class SortingPlant {
  private ArrayList<Trash> metalsArray = new ArrayList<>();
  private ArrayList<Trash> glassesArray = new ArrayList<>();
  private ArrayList<Trash> papersArray = new ArrayList<>();
  private ArrayList<Trash> plasticsArray = new ArrayList<>();

  public void sortTrashes (ArrayList<Trash> trashesArray) {
    for (Trash t : trashesArray) {
      switch (t.getTrashType()) {
        case METAL -> metalsArray.add(t);
        case GLASS -> glassesArray.add(t);
        case PAPER -> papersArray.add(t);
        case PLASTIC -> plasticsArray.add(t);
      }
    }
  }

  public ArrayList<Trash> getMetalsArray () {
    return metalsArray;
  }

  public ArrayList<Trash> getGlassesArray () {
    return glassesArray;
  }

  public ArrayList<Trash> getPapersArray () {
    return papersArray;
  }

  public ArrayList<Trash> getPlasticsArray () {
    return plasticsArray;
  }
}
