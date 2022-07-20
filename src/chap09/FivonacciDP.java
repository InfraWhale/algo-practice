package chap09;

public class FivonacciDP {
  // 피보나치 수를 기억하는 배열(최대 100번째까지)
  public static int[] fibonacciNumbers = new int[100];

  static int count = 0;

  // 인수 n의 피보나치 수를 반환하는 메소드
  public static int fibonacci(int n) {
    // 함수가 호출된 것을 확인
    System.out.printf("fibonacci(%d)가 호출되었습니다.\n", n);
    count ++;

    for (int i = 0; i <= n; i++) {
      if (i == 0) {
        // 0번째 피보나치 수 0을 저장
        fibonacciNumbers[i] = 0;
      } else if (i == 1) {
        // 1번째 피보나치 수 1을 저장
        fibonacciNumbers[i] = 1;
      } else {
        // 이후 피보나치 수를 구해 저장
        fibonacciNumbers[i] = fibonacciNumbers[i - 1] + fibonacciNumbers[i - 2];
      }
    }
    // 피보나치 수를 반환
    return fibonacciNumbers[n];
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
