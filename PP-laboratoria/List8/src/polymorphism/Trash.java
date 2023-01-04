package polymorphism;

public abstract class Trash {
  protected double weight;
  protected String name;

  public Trash (double weight, String name) {
    this.weight = weight;
    this.name = name;
  }

  @Override
  public String toString () {
    return "Weight: " + weight + "g," + '\n' +
      "Name: " + name + ',' + '\n';
  }
}
