/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package algorithm.hackerearth;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;

/**
 *
 * @author harsha-1916
 */
public class HackerEarthAlgo1 {
    /**
     Mr. X is performing a trick with the cards. He has N cards, lets name them 1.....N, on a round table. So card 1 is in between 2nd card and Nth card. Initially all cards are upside down. His trick involves making all cards face up.

His trick is whenever he taps on a card, it flips (if card was originally upside down, after flipping its faces up, and vice-versa), but he is no ordinary magician, he makes the two adjacent cards (if any) also to flip with the single tap. Formally, if he taps ith card, then i-1, i, i+1 cards are flipped. (Note that if he taps Nth card, then he flips (N-1)th, Nth and 1st card.)

Our magician needs a helper, to assist him in his magic tricks. He is looking for someone who can predict minimum number of taps needed to turn all the cards facing up.

Input : 
First line of input contains T, the number of test cases. Then T lines follows, each line contains N, the number of cards for that particular case.

Output : 
Print the output for each case in a single line.

Constraints : 
1 <= T <= 10^5 
0 <= N <= 10^15
     */
    public static void cardTricks(String args[] ) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        int n = Integer.parseInt(line);
        //BigInteger num = new BigInteger(s.toString());
        BigInteger bi0 = new BigInteger("0");
        BigInteger bi3 = new BigInteger("3");
        BigInteger bi1 = new BigInteger("1");
        for (int i = 0; i < n; i++) {
            String line1 = br.readLine();
            
            BigInteger numCards = new BigInteger(line1);
            BigInteger numOfFlips = numOfFlipsRequired(numCards,bi0,bi3,bi1);
            System.out.println(numOfFlips);
        }
    }
    
    private static BigInteger numOfFlipsRequired(BigInteger numOfCards,BigInteger bi0,BigInteger bi3,BigInteger bi1){
        //int numOfFlips = 0;
        
        if(numOfCards.equals(bi0)){
            return bi0;
        }else if(numOfCards.compareTo(bi3) == -1){
            return bi1;
        }else if(numOfCards.mod(bi3).compareTo(bi0) == 0){
            return numOfCards.divide(bi3);
        }else{
            return numOfCards;
        }
        
        
       // return numOfFlips;
    }
    /**
     Intelligent Girl
Max. Marks: 100Tweet
The challenge is over and this problem has been moved to practice area. You can either submit your solution here or 
Go to Practice Area. Also further submissions won't affect the leaderboard.
PROBLEM
EDITORIAL
MY SUBMISSIONS
Soumika has a string 
S
S and its starting index is 
1
1. The string 
S
S consists of characters from 
1
−
9
1−9. As she is very intelligent, she wants to test his brother Vinay Tendulkar. She asked her brother Vinay Tendulkar to count the number of even numbered characters ( i.e 
2
,
4
,
6
,
8
2,4,6,8 ) for every index 
i
i 
(
1
≤
i
≤
|
S
|
)
(1≤i≤|S|). For an index 
i
i, the result should be calculated from 
i
i to the end of the string. As Vinay doesn't know about programming, he wants you to help him find the solution.

Input:
First line contains a string 
S
S.

Output:
Print |
S
S| space-separated integers,the result of every index.

Constraints:
 1
1 ≤ |
S
S| ≤ 
10
10
4
4

SAMPLE INPUT 
574674546476
SAMPLE OUTPUT 
7 7 7 6 5 5 4 4 3 2 1 1
Explanation
Given string 
S
S is 
574674546476
574674546476.
for index 
1
1
Number of even numbers from 
5
5 to end of the string is 
7
7 so the result of index 
1
1 is 
7
7.
for index 
2
2
Number of even numbers from 
7
7 to end of the string is 
7
7 so the result of index 
2
2 is 
7
7.
for index 
3
3
Number of even numbers from 
4
4 to end of the string is 
7
7 so the result of index 
3
3 is 
7
7.
for index 
3
3
Number of even numbers from 6 to end of the string is 
6
6 so the result of index 
4
4 is 
6
6.....
     */
    
    public static void intelligentGirl(String args[] ) throws Exception {
        /*
         * Read input from stdin and provide input before running
         * Use either of these methods for input

        //BufferedReader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        int N = Integer.parseInt(line);

        //Scanner
        Scanner s = new Scanner(System.in);
        int N = s.nextInt();

        for (int i = 0; i < N; i++) {
            System.out.println("hello world");
        }
        */
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        //int N = Integer.parseInt(line);
        //System.out.println("Hello World!");
        int len = line.length();
        int[] arr = new int[len];
        int prev =0;
        for(int i=len-1;i>=0;i--){
            if(line.charAt(i) % 2 == 0){
                arr[i] = ++prev; 
            }else{
                arr[i] = prev;
            }
        }
        for(int i=0;i<len;i++){
            System.out.print(arr[i] + " ");
        }
    }
    /**
    In the race for the best Internet browser, there's now a new contender for it, this browser is called the: "The Semantic Mind-Reader!" After its promo on the world wide web, everyone's been desperately waiting for the browser to be released. And why shouldn't they be curious about it, after all, it's the new project of our very own genius "Little Jhool!" He's worked very hard for this browser, and to add new mind reading features to it.

Apart from the various security powers it possesses, it's called the mind-reader for a reason. Here's why:

You don't need to type 'www.' to open a website anymore.
Though, you still need to type '.com' to open a website.
The browser predicts ALL THE VOWELS in the name of the website. (Not '.com', though. Again!)
Obviously, this means you can type the name of a website faster and save some time.
Now to convince users that his browser will indeed save A LOT of time for users to open a particular website, Little Jhool has asked you to prepare a report on the same.

Input format:
The first line contains tc, the number of test cases.
The second line contains the name of websites, as a string.

Output format:
You have to print the ratio of characters you would have typed in Jhool's browser, to your normal browser.

Constraints:
1 <= tc <= 100
1 <= Length of the website <= 200

NOTE: You do NOT need to print the output in its lowest format. You should print in its original fraction format.
The names of all the websites will be in small case only.

Every string will start from *www. and end with *.com, so well!**

SAMPLE INPUT 
2
www.google.com
www.hackerearth.com
SAMPLE OUTPUT 
7/14
11/19
Explanation
Consider the first case:

In Jhool's browser, you'll only have to type: ggl.com (7 characters) while in a normal browser, you'll have to type www.google.com, which is 14 characters.

Time Limit:	1.0 sec(s) for each input file.
     */
    
    public static void browserMain(String args[] ) throws Exception {
     
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        int t = Integer.parseInt(line);
        //System.out.println("Hello World!");
        for(int i=0;i<t;i++){
            String website = br.readLine();
            int[] ratio = ratioCalculator(website);
            System.out.println(ratio[0] + "/" + ratio[1]);
        }
    }
    private static boolean isVowel(char currChar){
        if(currChar == 'a' || currChar == 'e' || currChar == 'i' || currChar == 'o' || currChar == 'u'){
            return true;
        }
        return false;
    }
    
     private static int[] ratioCalculator(String website){
        int numOfcharsInJhool = 4;
        int totalChars = 8;
        for(int i=4;i<=website.length()-5;i++){
            char currChar = website.charAt(i);
            if(!isVowel(currChar)){
                numOfcharsInJhool++;
            }
            totalChars++;
        }
        return new int[]{numOfcharsInJhool,totalChars};
    }
     
     
public static void main(String args[] ) throws Exception {
        /*
         * Read input from stdin and provide input before running
         * Use either of these methods for input

        //BufferedReader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        int N = Integer.parseInt(line);

        //Scanner
        Scanner s = new Scanner(System.in);
        int N = s.nextInt();

        for (int i = 0; i < N; i++) {
            System.out.println("hello world");
        }
        */

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        int n = Integer.parseInt(line);
        long[] arr = new long[n];
        line = br.readLine();
        String[] strs = line.trim().split("\\s+");
        for(int arr_i=0;arr_i<n;arr_i++){
            long newNum = Long.parseLong(strs[arr_i]);
            arr[arr_i] = newNum;
        }
        int q = Integer.parseInt(br.readLine());
        for(int q_i=0;q_i<q;q_i++){
        line = br.readLine();
        strs = line.trim().split("\\s+");
        int l = Integer.parseInt(strs[0]);
        int r = Integer.parseInt(strs[1]);
        int x = Integer.parseInt(strs[2]);
        long[] resArr = calculateZandItsCount(arr,l-1,r-1,x);
            System.out.println(resArr[0] + " " + resArr[1]);
        }
    }
    
   /* private findMinInRangeL_R(int[] arr,int l,int r){
        
    }*/
    
    private static long[] calculateZandItsCount(long[] arr,int l,int r,int x){
        long min = Long.MAX_VALUE;
        long z = arr[l];
        long count =0;
        for(int l_i=l;l_i<=r;l_i++){
            long tempZ = x ^ arr[l_i];
            if(tempZ == min){
                count++; 
            }else if(tempZ < min){
                z = arr[l_i];
                count=1;
                min = tempZ;
            }
            
        }
        return  new long[]{z,count};
    }
}
