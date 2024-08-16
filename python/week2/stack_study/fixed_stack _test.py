from typing import Any
# 고정 길이 스택 클래스 사용

from enum import Enum
#from fixed_stack import FixedStack
from stack import Stack

Menu = Enum('Menu', ['푸시','팝','피크','검색','덤프','종료'])

def select_menu() -> Menu:
    """메뉴선택"""
    s = [f'({m.value}){m.name}' for m in Menu]
    # print(s) ['(1)푸시', '(2)팝', '(3)피크', '(4)검색', '(5)덤프', '(6)종료']
    while True: 
        print(*s, sep ='    ', end='') # * : s에 있는 각 항목 print 하는 문법인가?
        n = int(input(': ')) # ': '뒤에 입력 받는건가?
        if 1 <= n <= len(Menu):
            return Menu(n) # 메뉴에 있는 n번쨰 항목을 반환받음
        
#s = FixedStack(64)
s = Stack(64)
while True:
    print(f'현재 데이터 개수 : {len(s)} / {s.capacity}')
    menu = select_menu() # 메뉴 선택
    
    if menu == Menu.푸시: # 푸시
        x = int(input('데이터를 입력하세요.: '))
        try:
            s.push(x)
        #except FixedStack.Full:
        except Stack.Full:
            print('스택이 가득 차 있습니다.')
            
    elif menu == Menu.팝:
        try:
            x = s.pop()
            print(f'팝한 데이터는 {x}입니다.')
        #except FixedStack.Empty:
        except Stack.Empty:
            print('스택이 비어 있습니다.')
    
    elif menu == Menu.피크: # 피크
        try:
            x = s.peek()
            print(f'피크한 데이터는 {x}입니다.')
        # except FixedStack.Empty:
        except Stack.Empty:    
            print('스택이 비어 있습니다.')
            
    elif menu == Menu.검색: # 검색
        x = int(input('검색할 값을 입력하세요.: '))
        if x in s:
            print(f'{s.count(x)}개 포함되고, 맨 앞의 위치는 {s.find(x)}입니다.')
        else:
            print('검색값을 찾을 수 없습니다.')
    
    elif menu == Menu.덤프: # 덤프
        s.dump()
        
    else:
        break