package b4practice;

public class Practice0403 {

  public static void main(String[] args) {
    Diet day1 = new Diet(99.7, "2022-06-04");

    Diet day2 = day1;

    System.out.println(day2.getWeight() + " & " + day2.getDate());

    day2.setWeight(99.4);
    day2.setDate("2022-06-05");

    System.out.println(day1.getWeight() + " & " + day1.getDate());

  }

}
