package chap10;

public class KnapsackGA {

  public static final int KNAP_MAX = 6;          // 배낭의 최대 무게
  public static final int ITEM_NUM = 5;          // 물건의 종류
  public static final int IND_NUM = 8;           // 개체 수
  public static final double MUTATE_RATE = 0.1;  // 돌연변이 확률(10%)

  public static char[] itemname = {'A', 'B', 'C', 'D', 'E'}; // 물건의 이름
  public static int[] itemWeight = {1, 2, 3, 4, 5};          // 물건의 무게
  public static int[] itemValue = {100, 300, 350, 500, 650}; // 물건의 가치

  public static int indGeneration;                              // 개체의 세대
  public static int [][] indGene = new int[IND_NUM][ITEM_NUM];  // 개체의 유전자
  public static int[] indWeight = new int[IND_NUM];             // 개체의 무게
  public static int[] indValue = new int[IND_NUM];              // 개체의 가치
  public static int[] indFitness = new int[IND_NUM];            // 개체의 적응도

  // 개체를 무작위로 생성하는 메소드
  public static void createIndividual() {
    int ind, item; // 루프 카운터

    // 0 또는 1을 무작위로 저장
    for (ind = 0; ind < IND_NUM; ind++) {
      for (item = 0; item < ITEM_NUM; item++) {
        indGene[ind][item] = Math.random() > 0.5 ? 0 : 1;
      }
    }
  }

  // 개체의 무게, 가치, 적응도를 계산하는 메소드
  public static void calcIndividual() {
    int ind, item; // 루프 카운터

    for (ind = 0; ind < IND_NUM; ind++) {
      // 무게와 가치를 계산
      indWeight[ind] = 0;
      indValue[ind] = 0;
      for (item = 0; item < ITEM_NUM; item++) {
        if (indGene[ind][item] == 1) {
          indWeight[ind] += itemWeight[item];
          indValue[ind] += itemValue[item];
        }
      }

      // 적응도를 계산
      if (indWeight[ind] <= KNAP_MAX) {
        // 최대 무게 이하면 가치를 그대로 적응도로 삼음
        indFitness[ind] = indValue[ind];
      } else {
        // 최대 무게를 초과하면 적응도를 0으로 함
        indFitness[ind] = 0;
      }
    }
  }

  // 개체의 적응도를 표시하는 메소드
  public static void showIndividual() {
    int ind, item; // 루프 카운터

    // 세대를 표시
    System.out.printf("\n<%d세대>\n", indGeneration);

    // 유전자, 무게, 가치, 적응도를 표시
    System.out.printf("유전자\t\t무게\t가치\t적응도\n");
    for (ind = 0; ind < IND_NUM; ind++) {
      for (item = 0; item < ITEM_NUM; item++) {
        System.out.printf("[%d]", indGene[ind][item]);
      }
      System.out.printf("\t%2dkg\t%4d원\t%4d\n", indWeight[ind], indValue[ind], indFitness[ind]);
    }
    System.out.println();
  }

  // 적응도가 큰 순서대로 개체를 정렬하는 메소드
  public static void sortIndividual() {
    int pos;   // 삽입할 요소
    int ins;   // 삽입할 위치
    int item;  // 루프 카운터
    int tmp;   // 임시 변수

    // 삽입 정렬로 정렬
    for (pos = 1; pos <IND_NUM; pos++) {
      ins = pos;
      while (ins >= 1 && indFitness[ins - 1] < indFitness[ins]) {
        for (item = 0; item <ITEM_NUM; item++) {
          tmp = indGene[ins - 1][item];
          indGene[ins - 1][item] = indGene[ins][item];
          indGene[ins][item] = tmp;
        }

        tmp = indWeight[ins - 1];
        indWeight[ins -1] = indWeight[ins];
        indWeight[ins] = tmp;

        tmp = indValue[ins - 1];
        indValue[ins -1] = indValue[ins];
        indValue[ins] = tmp;

        tmp = indFitness[ins - 1];
        indFitness[ins -1] = indFitness[ins];
        indFitness[ins] = tmp;

        ins--;
      }
    }
  }

  // 프로그램 실행의 시작점인 main 메소드
  public static void main(String[] args) {

    //    //배낭에 들어있는 물건을 조사하여 정답을 표시
    //    System.out.println("<배낭에 들어 있는 물건을 조사>");
    //    totalWeight = 0;
    //    for (knap = KNAP_MAX; knap > 0; knap -= weight[item]) {
    //      item = lastItem[knap];
    //      System.out.printf("%dkg의 배낭에 마지막으로 넣은 물건은 %c입니다.\n", knap, name[item]);
    //      totalWeight += weight[item];
    //      System.out.printf(" %c, %dkg, %d원\n", name[item], weight[item], value[item]);
    //      System.out.printf(" %dkg - %dkg = %dkg입니다. \n", knap, weight[item], knap - weight[item]);
    //    }
    //    System.out.println("\n<정답을 표시>");
    //    System.out.printf("무게의 합계 = %dkg\n", totalWeight);
    //    System.out.printf("가치의 최댓값 = %d원\n", maxValue[ITEM_NUM -1][KNAP_MAX]);
  }
}
