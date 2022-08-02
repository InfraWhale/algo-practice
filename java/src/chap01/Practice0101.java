package chap01;

import java.util.Scanner;

//유클리드 호제법

public class Practice0101 {

  public static void main(String[] args) {

    Scanner scn = new Scanner(System.in);
    int a, b;

    System.out.print("첫 번째 수 : ");
    a = scn.nextInt();
    System.out.print("두 번째 수 : ");
    b = scn.nextInt();
    scn.close();

    while (a != b) { // a, b가 다를 경우 계속 반복한다.
      if (a > b) {
        a -= b; // a가 b보다 크면 a에서 b를 뺀다.
      } else {
        b -= a; // b가 a보다 크면 b에서 a를 뺀다.
      }
    }

    System.out.printf("두 수의 최대공약수는 %d 입니다.\n", a);
  }

}
