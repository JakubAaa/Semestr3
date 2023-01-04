package polymorphism;

import java.util.ArrayList;

public class SortingPlantTest {
  public static void main (String[] args) {
    Trash trash1 = new Metal(89.5, "Can of poppy seed mass", "Steel", false);
    Trash trash2 = new Metal(20.25, "Watch", "Gold", true);
    Trash trash3 = new Glass(123.23, "Beer bottle", 50, true);
    Trash trash4 = new Glass(178.89, "Milk bottle", 100, false);
    Trash trash5 = new Paper(121.32, "Cookie box", 160, true);
    Trash trash6 = new Paper(89.9, "Milk carton", 120, true);
    Trash trash7 = new Paper(198, "Old newspaper", 80, false);
    Trash trash8 = new Plastic(13.32, "Old sandwich box", 5, true);
    Trash trash9 = new Plastic(13.32, "A cones bag", 8, true);

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