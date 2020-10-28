public class FlipACoin {

    public static final String ANSI_BLUE = "\u001B[34m";
    public static final String ANSI_RED  = "\u001B[31m";

    public static void main(String[] args) {
        int i = (int)(Math.random()*10);
        if(i%2==0){
            System.out.println("Its a "+ANSI_BLUE+"HEADS"+ANSI_BLUE);
        }else{
            System.out.println("Its a "+ANSI_RED +"TAILS"+ANSI_RED );
        }
    }
}
