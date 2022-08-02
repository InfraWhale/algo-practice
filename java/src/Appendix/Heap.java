package Appendix;

public class Heap {

  public static int lchild(int i) {
    return (2 * i) + 1 ;
  }

  public static int rchild(int i) {
    return (2 * i) + 2 ;
  }

  public static int parent(int i) {
    return (i - 1) / 2;
  }

  public static void makeHeap(int data[], int heap[], int hnum) {
    int i, k;

    for (i = 0; i < hnum; i++) {
      heap[i] = data[i];
      k = i;
      while(k > 0) {
        if (heap[k] > heap[parent(k)]) {
          swap(heap, k, parent(k));
          k = parent(k);
        } else {
          break;
        }
      }
    }

  }

  public static void swap(int[] heap, int i, int j) {
    int tmp;

    tmp = heap[i];
    heap[i] = heap[j];
    heap[j] = tmp;
  }

  public static void heapSort(int data[], int heap[], int hnum) {
    int last;

    makeHeap(data, heap, hnum);

    for (last = hnum - 1; last > 0; last--) {
      swap(heap, 0, last);
      downHeap(heap, last-1);
    }
  }

  public static void downHeap(int heap[], int hlast) {
    int n, tmp;

    n = 0;

    while (lchild(n) <= hlast) {
      tmp = lchild(n);
      if (rchild(n) <= hlast) {
        if(heap[tmp] <= heap[rchild(n)]) {
          tmp = rchild(n);
        }
      }
      if (heap[tmp] > heap[n]) {
        swap(heap, n, tmp);
      } else {
        return;
      }
      n = tmp;
    }
  }

  public static void showArray(int arr[], int len) {
    for (int i = 0; i < len; i++) {
      System.out.printf("[%d]", arr[i]);
    }
    System.out.println();
  }

  public static void main(String[] args) {

    //    int[] data = {60, 30, 45, 15, 5, 10, 20};
    int[] data = {5, 10, 15, 20, 30, 45, 60};
    int[] heap = new int[7];

    makeHeap(data, heap, data.length);

    showArray(heap, heap.length);

    heapSort(data, heap, heap.length);

    showArray(heap, heap.length);

  }
}
