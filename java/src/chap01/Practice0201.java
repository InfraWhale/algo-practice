package chap01;

import java.util.Scanner;

// 두 수의 최소공배수 구하기

public class Practice0201 {

  public static void main(String[] args) {

    Scanner scn = new Scanner(System.in);
    int a, aDefault, b, bDefault;
    System.out.print("첫 번째 수 : ");
    a = scn.nextInt();
    aDefault = a; // 처음에 입력한 값을 따로 저장해놓는다
    System.out.print("두 번째 수 : ");
    b = scn.nextInt();
    bDefault = b; // 처음에 입력한 값을 따로 저장해놓는다
    scn.close();


    if (a == 0 || b == 0) { // a 또는 b가 0일경우
      System.out.println("첫번째 수와 두번째 수는 자연수로 입력해주세요"); // 에러 메시지를 띄운다
    } else { // a,b 둘다 0이 아닐경우

      while (a != b) { // a와 b가 같은값이 나오면 반복문이 종료된다.
        if (a > b) {
          b += bDefault; // b가 a보다 커질때까지 처음 b에 입력된 값을 더한다.
        } else {
          a += aDefault; // a가 b보다 커질때까지 처음 a에 입력된 값을 더한다.
        }
      }

      System.out.printf("두 수의 최소공배수는 %d 입니다.\n", a);
    }
  }

}
