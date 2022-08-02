package chap01;

import java.util.Scanner;

//유클리드 호제법 응용

public class Practice0102 {

  public static void main(String[] args) {

    Scanner scn = new Scanner(System.in);
    int a, b;
    int answer;
    System.out.print("첫 번째 수 : ");
    a = scn.nextInt();
    System.out.print("두 번째 수 : ");
    b = scn.nextInt();
    scn.close();

    if (a == 0 || b == 0) { // a 또는 b가 0일경우
      System.out.println("첫번째 수와 두번째 수는 자연수로 입력해주세요");  // 에러 메시지를 띄운다
    } else { // a,b 둘다 0이 아닐경우

      while (true) {
        if (a > b) {
          answer = b;
          a %= b; // a를 b로 나눈 나머지 값이 0이라면 b가 최소공약수, 아니라면 다시 연산한다.
          if (a == 0) {
            break;
          }
        } else {
          answer = a;
          b %= a; // b를 a로 나눈 나머지 값이 0이라면 a가 최소공약수, 아니라면 다시 연산한다.
          if (b == 0) {
            break;
          }
        }
      }

      System.out.printf("두 수의 최대공약수는 %d 입니다.\n", answer);
    }
  }

}
