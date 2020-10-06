import java.net.*;
public class FindLocalAddress {
    public static void main(String[] args) {
        try {
            InetAddress address;
            address =  InetAddress.getLocalHost();
            System.out.println(address);
        } catch (Exception e) {
            System.out.println("Local Address not found :(");
        }
    }
}