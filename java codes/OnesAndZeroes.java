public class OnesAndZeroes {
  public static void main(String[] args) {
    String[] str = {"10", "0", "1"};
    System.out.println(new OnesAndZeroes().findMaxForm(str, 1, 1));
  }

  public int findMaxForm(String[] strs, int m, int n) {
    int[][][] dp = new int[strs.length + 1][m + 1][n + 1];
    for (int i = strs.length - 1; i >= 0; i--) {
      String string = strs[i];
      int zero = 0;
      int one = 0;
      for (char c : string.toCharArray()) {
        if (c == '0') {
          zero++;
        } else {
          one++;
        }
      }
      for (int p = m; p >= 0; p--) {
        for (int q = n; q >= 0; q--) {
          dp[i][p][q] = dp[i + 1][p][q];
          if (p - zero >= 0 && q - one >= 0) {
            dp[i][p][q] = Math.max(dp[i][p][q], dp[i + 1][p - zero][q - one] + 1);
          }
        }
      }
    }
    return dp[0][m][n];
  }
}
