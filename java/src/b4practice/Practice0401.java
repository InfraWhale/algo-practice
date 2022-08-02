package b4practice;

public class Practice0401 {

  public static void main(String[] args) {
    Diet[] diet = new Diet[5];
    for (int i = 0 ; i < diet.length; i++) {
      System.out.println(diet[i]);
    }       
  }

}

class Diet{

  double weight;
  String date;

  public Diet() {}

  public Diet(double weight, String date) {
    this.setWeight(weight);
    this.setDate(date);
  }

  public double getWeight() {
    return weight;
  }

  public void setWeight(double weight) {
    this.weight = weight;
  }

  public String getDate() {
    return date;
  }

  public void setDate(String date) {
    this.date = date;
  }

}