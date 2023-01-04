package pointers;

import java.util.ArrayList;

public class SortingPlantTest {
  public static void main (String[] args) {
    Trash trash1 = new Trash(Type.METAL, 89.5, "Can of poppy seed mass", "Steel", false);
    Trash trash2 = new Trash(Type.METAL, 20.25, "Watch", "Gold", true);
    Trash trash3 = new Trash(Type.GLASS, 123.23, "Beer bottle", 50, true);
    Trash trash4 = new Trash(Type.GLASS, 178.89, "Milk bottle", 100, false);
    Trash trash5 = new Trash(Type.PAPER, 121.32, "Cookie box", true, 160);
    Trash trash6 = new Trash(Type.PAPER, 89.9, "Milk carton", true, 120);
    Trash trash7 = new Trash(Type.PAPER, 198, "Old newspaper", false, 80);
    Trash trash8 = new Trash(Type.PLASTIC, 5, true, 13.32, "Old sandwich box");
    Trash trash9 = new Trash(Type.PLASTIC, 8, true, 13.32, "A cones bag");

    ArrayList<Trash> trashArray = new ArrayList<>();
    trashArray.add(trash1);
    trashArray.add(trash2);
    trashArray.add(trash3);
    trashArray.add(trash4);
    trashArray.add(trash5);
    trashArray.add(trash6);
    trashArray.add(trash7);
    trashArray.add(trash8);
    trashArray.add(trash9);

    SortingPlant plant = new SortingPlant();
    plant.sortTrashes(trashArray);
    System.out.println("Metals array: ");
    System.out.println(plant.getMetalsArray());
    System.out.println();

    System.out.println("Glasses array: ");
    System.out.println(plant.getGlassesArray());
    System.out.println();

    System.out.println("Papers array: ");
    System.out.println(plant.getPapersArray());
    System.out.println();

    System.out.println("Plastics array: ");
    System.out.println(plant.getPlasticsArray());
  }
}
