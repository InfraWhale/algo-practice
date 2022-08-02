package chap02; // 배열의 최댓값과 최솟값을 구하기

public class Practice0101 {
  public static void main(String[] args) {
    int[] a = { 72, 68, 92, 88, 41, 53, 97, 84, 39, 55 };
    int max, min, i;
    max = a[0];
    min = a[0];

    for (i = 1; i < 10; i++) {
      if (a[i] > max) {
        max = a[i];
      } else if (a[i] < min) {
        min = a[i];
      }
    }

    System.out.printf("최댓값은 %d 입니다.\n", max);
    System.out.printf("최솟값은 %d 입니다.\n", min);

  }

}
