//https://leetcode.com/problems/search-a-2d-matrix/
class Search2DMatrix {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0)
            return false;

        int row = matrix.length;
        int column = matrix[0].length;

        for (int i = 0; i < row; i++) {
            if (target < matrix[i][0]) {
                return false;
            } else if (target >= matrix[i][0] && target <= matrix[i][column - 1]) {
                int start = 0;
                int end = column - 1;
                while (start <= end) {
                    int mid = (start + end) / 2;
                    if (matrix[i][mid] == target)
                        return true;
                    else if (matrix[i][mid] > target)
                        end = mid - 1;
                    else
                        start = mid + 1;
                }
            } else
                continue;
        }
        return false;
    }

    public static void main(String args[]) {
        Search2DMatrix obj = new Search2DMatrix();
        int[][] matrix = { { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 50 } };
        System.out.println("Search result :" + obj.searchMatrix(matrix, 3));
    }

}