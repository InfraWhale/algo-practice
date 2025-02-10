// 2024 카카오 인턴 4번

class Solution {
    
    static int sCoin;
    static int[] cardStatus;
    static int life;
    static int halfLife;
    static int N;
    
    public int solution(int coin, int[] cards) {
        int answer = 1;
        
        N = cards.length;
        sCoin = coin;
        
        cardStatus = new int [N+1];
        life = 0;
        halfLife = 0;
        
        for(int i = 0; i < N / 3; i++) {
            int card = cards[i];
            cardStatus[card] = 1;
            
            if(cardStatus[N+1-card] == 1) life++;
        }
        
        for(int i = N / 3; i < N - 1; i += 2) {
            int firstCard = cards[i];
            int secondCard = cards[i+1];
            
            checkCard(firstCard);
            checkCard(secondCard);
            
            if (life != 0) {
               life--; 
            } else {
                if(halfLife != 0 && sCoin >= 2) {
                    halfLife--; 
                    sCoin -= 2;
                } else break;
            }
            
            answer++;
        }
        
        return answer;
    }
    
    public void checkCard(int card) {
        if (cardStatus[N+1-card] == 1) {
            cardStatus[card] = 1;
            if(sCoin != 0) {
                sCoin--;
                life++;
            }
        } else {
            if(cardStatus[N+1-card] == 2) {
                halfLife++;
            }
            cardStatus[card] = 2;
        }
    }
}