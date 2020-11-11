import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class IPUtils {
	
	/**
	 * This method turns long number into IP
	 * @param ipAddress
	 * @return
	 */
	public static String longToIp(final long ipaslong) {
		return String.format("%d.%d.%d.%d", (ipaslong >>> 24) & 0xff, (ipaslong >>> 16) & 0xff, (ipaslong >>> 8) & 0xff,
				(ipaslong) & 0xff);
	}

	/**
	 * This method turns IP into long number
	 * 
	 * @param ipAddress
	 * @return
	 */
	public static long ipToLong(String ipAddress) {
		String[] ipAddressInArray = ipAddress.split("\\.");
		long result = 0;
		for (int i = 0; i < ipAddressInArray.length; i++) {
			int power = 3 - i;
			int ip = Integer.parseInt(ipAddressInArray[i]);
			result += ip * Math.pow(256, power);
		}
		return result;
	}
	
	/**
	 * This method checks IP parameter valid or not
	 * @param ipAddr
	 * @return
	 */
	public static boolean isValidIP(String ipAddr) {
        Pattern ptn = Pattern.compile("^(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})$");
        Matcher mtch = ptn.matcher(ipAddr);
        return mtch.find();
    }
}
