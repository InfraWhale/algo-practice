package b4practice;

public class Practice0301 {

  public static void main(String[] args) {
    int count = 0;
    int sum = 0;

    // 1부터 100까지의 카운트를 하고 모든 수를 합한다.
    // => break 사용 전
    count = 0;
    sum = 0;
    while (count < 100) {
      count++;
      sum += count;
    }
    System.out.printf("count=%d, sum=%d\n", count, sum);

    System.out.println("------------------------");



    // 1부터 100까지의 카운트를 하는데 단 합은 50까지만 계산한다.
    // => break 사용 전
    count = 0;
    sum = 0;
    while (count < 100) {
      count++;
      if (count > 50) // 50을 넘어가면 합을 수행하지 않지만 100까지 계속 반복한다.
        continue;
      sum += count;
    }
    System.out.printf("count=%d, sum=%d\n", count, sum);

    System.out.println("------------------------");

    // => break 사용 후
    count = 0;
    sum = 0;
    while (count < 100) {
      count++;
      if (count > 50)
        break; // 즉시 반복문을 종료하고 나간다.
      sum += count;
    }
    System.out.printf("count=%d, sum=%d\n", count, sum);

  }
}
