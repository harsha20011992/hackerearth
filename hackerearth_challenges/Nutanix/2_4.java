 import java.util.*;

public class TestClass {

    public int minJump(long arr[], long cost[]){
        
        int []jump = new int[arr.length];
        jump[0] = 0;
        cost[0] = arr[0];
        for(int i=1; i < arr.length ; i++){
            jump[i] = Integer.MAX_VALUE-1;
        }
        //System.out.println(arr.length);
        for(int i=1; i < arr.length; i++){
            for(int j=0; j < i; j++){
                if(cost[j] + j >= i){
                    if((jump[i] > jump[j] + 1)  || 
                    (jump[i] == jump[j] + 1 && 
                    ((cost[j] - (i - j) + arr[i]) > cost[i]))){
                        //result[i] = j;
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
        long[] distanceArr = new long[N];
        long[] PetrolArr = new long[N];
        Map<Integer,Long> map = new HashMap<Integer,Long>();
        for(int i=0; i<N;i++){
            int key = scanner.nextInt();
            //System.out.println(key);
            map.put(key, scanner.nextLong());
        }
        int D = scanner.nextInt();
        long P = scanner.nextInt();
        long arr[] = new long[D+1];
        for(int i=0; i<=D;i++){
            arr[i]=0;
        }
        arr[0]= P;
        Iterator<Integer> iterator = map.keySet().iterator(); 
        while(iterator.hasNext()){
            int key = iterator.next();
            arr[D-key] = map.get(key);
        }
        
        long c[] = new long[arr.length];
        for(int i=0;i<c.length;i++){
            c[i] = arr[i];
        }
        int result = mj.minJump(arr, c);
        if(result >= 2000000000){
            result =  0;
        }
        System.out.println(result-1);
    }
}