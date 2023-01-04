package polymorphism;

import java.util.ArrayList;

public class SortingPlant {
  private ArrayList<Metal> metalsArray = new ArrayList<>();
  private ArrayList<Glass> glassesArray = new ArrayList<>();
  private ArrayList<Paper> papersArray = new ArrayList<>();
  private ArrayList<Plastic> plasticsArray = new ArrayList<>();

  public void sortTrashes (ArrayList<Trash> trashesArray) {
    for (Trash t : trashesArray) {
      if (t instanceof Metal)
        metalsArray.add((Metal) t);
      if (t instanceof Glass)
        glassesArray.add((Glass) t);
      if (t instanceof Paper)
        papersArray.add((Paper) t);
      if (t instanceof Plastic)
        plasticsArray.add((Plastic) t);
    }
  }

  public ArrayList<Metal> getMetalsArray () {
    return metalsArray;
  }

  public ArrayList<Glass> getGlassesArray () {
    return glassesArray;
  }

  public ArrayList<Paper> getPapersArray () {
    return papersArray;
  }

  public ArrayList<Plastic> getPlasticsArray () {
    return plasticsArray;
  }
}
