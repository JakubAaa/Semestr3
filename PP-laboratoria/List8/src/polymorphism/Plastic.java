package polymorphism;

public class Plastic extends Trash{
  private double thickness;
  private boolean forFood;

  public Plastic (double weight, String name, double thickness, boolean forFood) {
    super(weight, name);
    this.thickness = thickness;
    this.forFood = forFood;
  }

  @Override
  public String toString () {
    return "Plastic: {\n" +
      super.toString() +
      "Thickness: " + thickness + "mm," + '\n' +
      "For food: " + forFood
      + "\n}";
  }
}
