 import java.util.*;

public class TestClass {

    public int minJump(int distanceArr[],long[] petrolArr, long cost[]){
        
        int []jump = new int[distanceArr.length];
        jump[0] = 0;
        for(int i=1; i < distanceArr.length ; i++){
            jump[i] = Integer.MAX_VALUE-1;
        }
        //System.out.println(arr.length);
        for(int i=1; i < distanceArr.length; i++){
            for(int j=0; j < i; j++){
                if(cost[j] + distanceArr[j] >= distanceArr[i]){
                    if((jump[i] > jump[j] + 1)  || 
                    (jump[i] == jump[j] + 1 && 
                    ((cost[j] - (distanceArr[i] - distanceArr[j]) + petrolArr[i]) > cost[i]))){
                        //result[i] = j;
                        cost[i] = petrolArr[i] + cost[j] - (distanceArr[i]-distanceArr[j]);
                        jump[i] = jump[j] + 1;
                    }
                }
            }
        }
        
        return jump[jump.length-1];
    }
  static void rvereseArray(int arr[], int start, int end)
    {
        int temp;
        if (start >= end)
            return;
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        rvereseArray(arr, start+1, end-1);
    }
    
    static void rvereseLongArray(long arr[], int start, int end)
    {
        long temp;
        if (start >= end)
            return;
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        rvereseLongArray(arr, start+1, end-1);
    }
    public static void main(String args[]){
        
        Scanner scanner = new Scanner(System.in);
        TestClass mj = new TestClass();
        int N = scanner.nextInt();
        int[] distanceArr = new int[N+2];
        long[] petrolArr = new long[N+2]; 
        //Map<Integer,Long> map = new HashMap<Integer,Long>();
        for(int i=0; i<N+1;i++){
            distanceArr[i] = scanner.nextInt();
            petrolArr[i] = scanner.nextLong();
        }
        
        //int D = scanner.nextInt();
        //long P = scanner.nextInt();
        /*long arr[] = new long[D+1];
        for(int i=0; i<=D;i++){
            arr[i]=0;
        }
        arr[0]= P;
         for(int i=0;i<N;i++){
            arr[D-distanceArr[i]] = petrolArr[i];
        }*/
        long c[] = new long[N+2];
        
        rvereseArray(distanceArr,0,N);
        rvereseLongArray(petrolArr,0,N);
        distanceArr[N+1] = 0;
		petrolArr[N+1] = 0;
		for(int i=0;i<c.length;i++){
            c[i] = petrolArr[i];
        }
		int result = mj.minJump(distanceArr,petrolArr, c);
        if(result >= 2000000000){
            result =  0;
        }
        System.out.println(result);
    }
}