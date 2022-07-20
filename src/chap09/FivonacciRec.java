package chap09;

public class FivonacciRec {
  // 인수 n의 피보나치 수를 반환하는 메소드

  static int count = 0;

  public static int fibonacci(int n) {
    // 함수가 호출된 것을 확인
    System.out.printf("fibonacci(%d)가 호출되었습니다.\n", n);
    count++;

    if (n == 0) {
      // 0번째 피보나치 수는 0
      return 0;
    } else if (n == 1) {
      // 1번째 피보나치 수는 1
      return 1;
    } else {
      // 이후는 앞의 두 수를 더한 값
      return fibonacci(n - 1) + fibonacci(n - 2);
    }
  }

  public static void main(String[] args) {
    int n;

    // 0~8번째 피보나치 수를 표시
    for (n = 0; n <= 8; n++) {
      System.out.printf("%d,\n", fibonacci(n));
    }

    System.out.printf("메소드는 %d회 호출되었습니다.", count);
  }
}
