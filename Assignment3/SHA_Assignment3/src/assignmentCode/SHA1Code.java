package assignmentCode;
import java.math.BigInteger;
import java.security.*;
import java.util.*;
import javax.management.RuntimeErrorException;
/**
 * Hashing with SHA1
 *
 * @param input String to hash
 * @return String hashed
 */
public class SHA1Code {
	private static String hashFunction(String message) {
		String hashedMessage = "";
		try {
			// gets instance of the algorithm
			MessageDigest mdigest = MessageDigest.getInstance("SHA-1");
			// Use the digest() function of the algorithm to calculate message digest
			// of input
			// Returns a byte array
			byte[] digestedMessage = mdigest.digest(message.getBytes());
			// Convert the byte array into signum representation
			BigInteger number = new BigInteger(1, digestedMessage);
			// Convert the message direct into Hex value
			hashedMessage = number.toString(16);
			// Add preceding 0 to convert to 32 bits
			while(hashedMessage.length()<32) {
				hashedMessage = "0" + hashedMessage;
			}
			// return calculated Hash Value
			return hashedMessage;
		}
		catch(Exception e) {
			System.out.println("Error!!");
		}
		return hashedMessage;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		System.out.print("Enter the string to be hashed : ");
		String message = s.next();
		String hashed = hashFunction(message);
		System.out.println("The hashed message is : "+hashed);
	}
}
