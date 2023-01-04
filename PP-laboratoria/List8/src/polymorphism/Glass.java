package polymorphism;

public class Glass extends Trash{
  private double transparencyLevel;
  private boolean returnableBottle;

  public Glass (double weight, String name, double transparencyLevel, boolean returnableBottle) {
    super(weight, name);
    this.transparencyLevel = transparencyLevel;
    this.returnableBottle = returnableBottle;
  }

  @Override
  public String toString () {
    return "Glass: {\n" +
      super.toString() +
      "Transparency level: " + transparencyLevel + "%," + '\n' +
      "Returnable bottle: " + returnableBottle
      + "\n}";
  }
}
