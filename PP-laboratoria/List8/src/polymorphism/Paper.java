package polymorphism;

public class Paper extends Trash{
  private double grammage;
  private boolean colorful;

  public Paper (double weight, String name, double grammage, boolean colorful) {
    super(weight, name);
    this.grammage = grammage;
    this.colorful = colorful;
  }

  @Override
  public String toString () {
    return "Paper: {\n" +
      super.toString() +
      "Grammage: " + grammage + "g," + '\n' +
      "Colorful: " + colorful
      + "\n}";
  }
}
