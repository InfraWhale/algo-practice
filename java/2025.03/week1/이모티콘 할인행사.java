class Solution {
    
    int[] discountRate = {40, 30, 20, 10};
    int[] discountVal = {6, 7, 8, 9};
    int[][] discountPrice;
    int[] caseArr, sEmoticons;
    int emoLen, userLen;
    int[][] sUsers;
    int plus, cash;
    
    public int[] solution(int[][] users, int[] emoticons) {
        emoLen = emoticons.length;
        userLen = users.length;
        caseArr = new int[emoLen];
        sUsers = users;
        sEmoticons = emoticons;
        
        discountPrice = new int[emoLen][4];
        for(int i = 0; i < emoLen; i++) {
            for(int j = 0; j < 4; j++) {
                // 부동소수점 연산때문에 틀렸었음
                discountPrice[i][j] = sEmoticons[i] / 10 * discountVal[j];
            }
        }
        
        plus = 0;
        cash = 0;
        
        dfs(0);
        
        return new int[] {plus, cash};
    }
    
    public void dfs(int depth) {
        if(depth == emoLen) {
            calculate();
            return;
        }
        
        for(int i = 0; i < 4; i++) {
            caseArr[depth] = i;
            dfs(depth+1);
        }
        return;
    }
    
    public void calculate() {
        int plusNow = 0;
        int cashNow = 0;
        for(int i = 0; i < userLen; i++) {
            int userRate = sUsers[i][0];
            int userMoney = sUsers[i][1];
            int userBuy = 0;
            
            for(int j = 0; j < emoLen; j++) {
                if(userRate <= discountRate[caseArr[j]]) {
                    userBuy += discountPrice[j][caseArr[j]];
                }
                if(userBuy >= userMoney) {
                    plusNow++;
                    userBuy = 0;
                    break;
                }
            }
            cashNow += userBuy;
        }
        
        if(plus < plusNow) {
            plus = plusNow;
            cash = cashNow;
        } else if(plus == plusNow) {
            cash = Math.max(cash, cashNow);
        }
    }
}