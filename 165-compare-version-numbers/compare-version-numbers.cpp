class Solution {
public:
    int compareVersion(string version1, string version2) {
        int version1Length = version1.size();
        int version2Length = version2.size();
      
        int index1 = 0;
        int index2 = 0;
      
        while (index1 < version1Length || index2 < version2Length) {
            int revision1 = 0;
            while (index1 < version1Length && version1[index1] != '.') {
                revision1 = revision1 * 10 + (version1[index1] - '0');
                index1++;
            }
          
            int revision2 = 0;
            while (index2 < version2Length && version2[index2] != '.') {
                revision2 = revision2 * 10 + (version2[index2] - '0');
                index2++;
            }
          
            if (revision1 < revision2) {
                return -1;
            }
            if (revision1 > revision2) {
                return 1;
            }
          
            if (index1 < version1Length) {
                index1++;
            }
            if (index2 < version2Length) {
                index2++;
            }
        }
      
        return 0;
    }
};