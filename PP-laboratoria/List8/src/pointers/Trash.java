package pointers;

public class Trash {
  private Type trashType;
  private double weight;
  private String name;

  private String metalType;
  private boolean precious;
  private double transparencyLevel;
  private boolean returnableBottle;
  private double grammage;
  private boolean colorful;
  private double thickness;
  private boolean forFood;

  Trash (Type trashType, double weight, String name, String metalType, boolean precious) {
    this.trashType = trashType;
    this.weight = weight;
    this.name = name;
    this.metalType = metalType;
    this.precious = precious;
  }

  Trash (Type trashType, double weight, String name, double transparencyLevel, boolean returnableBottle) {
    this.trashType = trashType;
    this.weight = weight;
    this.name = name;
    this.transparencyLevel = transparencyLevel;
    this.returnableBottle = returnableBottle;
  }

  Trash (Type trashType, double weight, String name, boolean colorful, double grammage) {
    this.trashType = trashType;
    this.weight = weight;
    this.name = name;
    this.colorful = colorful;
    this.grammage = grammage;
  }

  Trash (Type trashType, double thickness, boolean forFood, double weight, String name) {
    this.trashType = trashType;
    this.weight = weight;
    this.name = name;
    this.thickness = thickness;
    this.forFood = forFood;
  }

  public Type getTrashType () {
    return trashType;
  }

  @Override
  public String toString () {
    switch (trashType) {
      case METAL -> {
        return "Metal: {\n" +
          "Weight: " + weight + "g," + '\n' +
          "Name: " + name + ',' + '\n' +
          "Type: " + metalType + ',' + '\n' +
          "Precious: " + precious
          + "\n}";
      }
      case GLASS -> {
        return "Glass: {\n" +
          "Weight: " + weight + "g," + '\n' +
          "Name: " + name + ',' + '\n' +
          "Transparency level: " + transparencyLevel + "%," + '\n' +
          "Returnable bottle: " + returnableBottle
          + "\n}";
      }
      case PAPER -> {
        return "Paper: {\n" +
          "Weight: " + weight + "g," + '\n' +
          "Name: " + name + ',' + '\n' +
          "Grammage: " + grammage + "g," + '\n' +
          "Colorful: " + colorful
          + "\n}";
      }
      case PLASTIC -> {
        return "Plastic: {\n" +
          "Weight: " + weight + "g," + '\n' +
          "Name: " + name + ',' + '\n' +
          "Thickness: " + thickness + "mm," + '\n' +
          "For food: " + forFood
          + "\n}";
      }
    }
    return "Other trash!";
  }
}
