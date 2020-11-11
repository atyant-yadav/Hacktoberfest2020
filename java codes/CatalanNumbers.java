public class CatalanNumbers{
    public static void main(String[] args) {
        for(int i = 0; i<10;i++){
            System.out.print(CatalanNumbers(i) + " ");
        }
    }


    public static int CatalanNumbers(int n){
        int catalan = 0;

        if(n <=1){
            catalan = 1;
        }else{
            for(int i = 0; i<n;i++){
                catalan += CatalanNumbers(i)*CatalanNumbers(n-i-1);
            }
        }
        return catalan;
    }
}