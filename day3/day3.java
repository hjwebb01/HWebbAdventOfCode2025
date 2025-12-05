import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
/*
The batteries are arranged into banks; each line of digits in your input
corresponds to a single bank of batteries. Within each bank, you need to
turn on exactly two batteries; the joltage that the bank produces is equal
to the number formed by the digits on the batteries you've turned on. For
example, if you have a bank like 12345 and you turn on batteries 2 and 4,
the bank would produce 24 jolts. (You cannot rearrange batteries.)
*/
public class day3 {
    static public void main(String[] args) {
        try (Scanner scanner = new Scanner(new File("day3/input.txt"))) {
            int sum = 0;
            while(scanner.hasNextLine()){
                String line = scanner.nextLine();
                sum += day3_part1(line);
            }
            System.out.println(sum);
        } catch (FileNotFoundException e) {
            System.err.println("Error: File not found - day3/input.txt");
        }
    }

    static public int day3_part1(String line){
        char[] arr = line.toCharArray();
        int n = arr.length;
        if(n < 2) {
            return 0;
        }
        
        char[] suffixMax = new char[n];
        suffixMax[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; i--){
            suffixMax[i] = arr[i] > suffixMax[i+1] ? arr[i] : suffixMax[i+1]; // max of current and next
        }
        
        int maxResult = 0;
        for(int i = 0; i < n-1; i++){
            int firstDigit = arr[i] - '0';
            int secondDigit = suffixMax[i+1] - '0';
            int twoDigit = firstDigit * 10 + secondDigit;
            if(twoDigit > maxResult){
                maxResult = twoDigit;
            }
        }
        
        return maxResult;
    }
}
