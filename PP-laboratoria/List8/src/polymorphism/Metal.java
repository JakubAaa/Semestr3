package polymorphism;

public class Metal extends Trash {
  private String type;
  private boolean precious;

  public Metal (double weight, String name, String type, boolean precious) {
    super(weight, name);
    this.type = type;
    this.precious = precious;
  }

  @Override
  public String toString () {
    return "Metal: {\n" +
      super.toString() +
        "Type: " + type + ',' + '\n' +
        "Precious: " + precious
      + "\n}";
  }
}
