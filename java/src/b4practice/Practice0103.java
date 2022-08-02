package b4practice;

public class Practice0103 {

  public static void main(String[] args) {

    int age = -1;

    if (age <= 0) {
      System.out.println("나이를 제대로 입력해주세요.");
    } else if (age >= 20) {
      System.out.println("성인입니다.");
    } else {
      System.out.println("미성년자입니다.");
    }
  }

}
