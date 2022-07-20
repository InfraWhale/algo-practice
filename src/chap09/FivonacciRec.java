package chap09;

public class FivonacciRec {

  public static int fibonacci(int n) {
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
      System.out.printf("%d, ", fibonacci(n));
    }
  }
}
