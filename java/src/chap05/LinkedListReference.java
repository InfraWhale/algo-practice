package chap05;

// reference를 이용한 linkedlist

public class LinkedListReference {
  private StationList head = null;

  static class StationList {
    String name;
    StationList next = null;

    StationList(String v) {
      name = v;
    }
  }

  public LinkedListReference() {
  }

  public String get(int index) { // 인덱스 번호에 입력된 이름 반환하는 메소드
    if (head == null) {
      return null;
    }

    StationList cur = head;
    for (int i = 0; i < index; i++) {
      if (cur.next == null) {
        return null;
      }
      cur = cur.next;
    }
    return cur.name;
  }

  public void insHead(String val) { // head 위치 바꾸는 메소드
    if (head == null) {
      head = new StationList(val);
      return;
    }

    StationList node = new StationList(val);
    node.next = head;
    head = node;
  }

  public void insTail(String val) { // 연결 리스트 마지막에 요소 삽입 (tail 위치 변경)
    if (head == null) {
      head = new StationList(val);
      return;
    }

    StationList cur = head;
    while (cur.next != null) {
      cur = cur.next;
    }
    StationList node = new StationList(val);
    cur.next = node;
  }

  public void insIndex1(int index, String val) {
    if (head == null) {
      if (index == 0) {
        head = new StationList(val);
      }
      return;
    }

    StationList prev = null;
    StationList cur = head;
    for (int i = 0; i < index; i++) {
      if (cur == null) {
        return;
      }
      prev = cur;
      cur = cur.next;
    }

    StationList node = new StationList(val);
    if (prev == null) {
      node.next = head;
      head = node;
    } else if (cur == null) {
      cur = node;
      prev.next = cur;
    } else {
      prev.next = node;
      node.next = cur;
    }
  }

  public void insIndex2(int insIndex, String val, int prevInd) {
    if (head == null) { // head에 값이 없으면 끝
      if (insIndex == 0) { // 근데 삽입하는 index가 0이면 head에 이거 삽입
        head = new StationList(val);
      }
      return;
    }

    StationList prev = null;
    StationList cur = head;
    for (int i = 0; i < prevInd; i++) { // 넣으려는 위치 prevInd로 설정
      if (cur == null) {
        return;
      }
      prev = cur;
      cur = cur.next;
    }

    StationList node = new StationList(val);
    if (prev == null) {
      node.next = head;
      head = node;
    } else if (cur == null) {
      cur = node;
      prev.next = cur;
    } else {
      prev.next = node;
      node.next = cur;
    }
  }

  public void delIndex(int index) {
    if (head == null) { // 아무 요소도 없으면 끝냄
      return;
    }

    StationList prev = null;
    StationList cur = head;
    for (int i = 0; i < index; i++) { // 삭제할 요소를 cur로 설정
      if (cur.next == null) {
        return;
      }
      prev = cur;
      cur = cur.next;
    }

    StationList next = cur.next;
    if (prev == null) { // cur이 head인 경우
      head = head.next;
    } else if (next == null) { // 마지막 요소인 경우
      prev.next = null;
    } else { // 그 외
      prev.next = next;
    }
  }

  void retrieve() {
    StationList point = head;

    while (point.next != null) {
      System.out.print(point.name + " → ");
      point = point.next;
    }
    System.out.println(point.name);
  }

  public static void main(String[] args) {
    LinkedListReference obj = new LinkedListReference();
    obj.insHead("[서울]");
    obj.insTail("[천안아산]");
    obj.insTail("[대전]");
    obj.insTail("[동대구]");
    obj.insTail("[부산]");
    obj.retrieve();
    // obj.insIndex1(1, "[광명]");
    obj.insIndex2(4, "[광명]", 1);
    obj.retrieve();
    obj.delIndex(1);
    obj.retrieve();
  }
}