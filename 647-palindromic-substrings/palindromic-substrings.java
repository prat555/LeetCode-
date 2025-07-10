class Solution {
    public int countSubstrings(String s) {
        StringBuilder transformedString = new StringBuilder("^#");
        for (char ch : s.toCharArray()) {
            transformedString.append(ch).append('#');
        }
        transformedString.append('$');
        String modifiedStr = transformedString.toString();
        int length = modifiedStr.length();
        int[] palindromeLengths = new int[length];
        int center = 0;
        int rightBoundary = 0;
        int countPalindromes = 0;
        for (int i = 1; i < length - 1; i++) {
            int mirror = 2 * center - i;
            palindromeLengths[i] = rightBoundary > i ? Math.min(rightBoundary - i, palindromeLengths[mirror]) : 1;
            while (modifiedStr.charAt(i - palindromeLengths[i]) == modifiedStr.charAt(i + palindromeLengths[i])) {
                palindromeLengths[i]++;
            }
            if (i + palindromeLengths[i] > rightBoundary) {
                rightBoundary = i + palindromeLengths[i];
                center = i;
            }
            countPalindromes += palindromeLengths[i] / 2;
        }
        return countPalindromes;
    }
}