package b4practice;

public class Practice0402 {

  public static void main(String[] args) {
    Diet[] diet = new Diet[5];

    diet[0] = new Diet(99.7, "2022-06-04");
    diet[1] = new Diet(99.4, "2022-06-05");
    diet[2] = new Diet(99.1, "2022-06-06");
    diet[3] = new Diet(98.8, "2022-06-07");
    diet[4] = new Diet(98.5, "2022-06-08");

    for (int i = 0 ; i < diet.length; i++) {
      System.out.println(diet[i]);
    }       

    System.out.println("---------------------------------------------------");

    for (int i = 0 ; i < diet.length; i++) {
      System.out.println(diet[i].getWeight() + " & " + diet[i].getDate());
    }

  }

}
