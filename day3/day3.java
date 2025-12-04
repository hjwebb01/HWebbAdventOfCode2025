import java.util.Scanner;
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
        Scanner scanner = new Scanner(System.in);
        String line = scanner.nextLine();

    }


    /*
    dual pointers combined with sliding window
    [Left slides to highest tens slot and right iterates starting at the next index]
    */

    static public int day3_part1(String line){
        char[] arrLine = line.toCharArray();
        int l = 0;
        int r = 0;
        int maxFirstDig = arrLine[0];
        int maxSecondDig = arrLine[1];


        while(r < arrLine.length){
          if(arrLine[l] < arrLine[r]){
            maxFirstDig = arrLine[r];
          }

    }
  }
}
