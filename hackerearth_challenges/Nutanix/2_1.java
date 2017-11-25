import java.util.*;

public class TestClass {

    public int minJump(int arr[], int cost[], int result[]){

        int []jump = new int[arr.length];
        jump[0] = 0;
        cost[0] = arr[0];
        for(int i=1; i < arr.length ; i++){
            jump[i] = Integer.MAX_VALUE-1;
        }
        //System.out.println(arr.length);
        for(int i=1; i < arr.length; i++){
            for(int j=0; j < i; j++){
                if(arr[j] + j >= i){
                    if(jump[i] > jump[j] + 1 && (cost[j] - (i - j)) >= 0){
                        result[i] = j;
                        cost[i] = arr[i] + cost[j] - (i-j);
                        jump[i] = jump[j] + 1;
                    }
                }
            }
        }

        return jump[jump.length-1];
    }


    public static void main(String args[]){

        Scanner scanner = new Scanner(System.in);
        TestClass mj = new TestClass();
        int N = scanner.nextInt();
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
        for(int i=0; i<N;i++){
            int key = scanner.nextInt();
            //System.out.println(key);
            map.put(key, scanner.nextInt());
        }
        int D = scanner.nextInt();
        int P = scanner.nextInt();
        int arr[] = new int[D+1];
        for(int i=0; i<=D;i++){
            arr[i]=0;
        }
        arr[0]= P;
        Iterator<Integer> iterator = map.keySet().iterator();
        while(iterator.hasNext()){
            int key = iterator.next();
            arr[D-key] = map.get(key);
        }
        int r[] = new int[arr.length];
        int c[] = new int[arr.length];
        int result = mj.minJump(arr, c, r);
        System.out.println(result-1);
    }
}
