import java.util.*;

class Solution {
    public int solution(String str1, String str2) {
        Map<String, int[]> biGramMap = new HashMap<>();
        
        addBiGrams(str1.toLowerCase(), biGramMap, 0);
        addBiGrams(str2.toLowerCase(), biGramMap, 1);

        int intersection = 0;
        int union = 0;

        for (int[] counts : biGramMap.values()) {
            intersection += Math.min(counts[0], counts[1]);
            union += Math.max(counts[0], counts[1]);
        }

        if (union == 0) return 65536;

        return 65536 * intersection / union;
    }

    private void addBiGrams(String str, Map<String, int[]> map, int index) {
        for (int i = 0; i < str.length() - 1; i++) {
            char c1 = str.charAt(i);
            char c2 = str.charAt(i + 1);
            if (Character.isLetter(c1) && Character.isLetter(c2)) {
                String biGram = "" + c1 + c2;
                map.putIfAbsent(biGram, new int[2]);
                map.get(biGram)[index]++;
            }
        }
    }
}
