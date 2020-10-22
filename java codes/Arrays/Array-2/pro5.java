import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class pro5 {

    public static List findDuplicate(int[] array) {
        HashMap<Integer, Integer> map = new HashMap<>();
        List<Integer> list = new LinkedList<>();
        for (int i = 0; i < array.length; i++) {
            if(!map.containsKey(array[i]))
                map.put(array[i], 0);
            map.put(array[i], map.get(array[i]) + 1);
        }
        for (var i : map.entrySet()) {
            if(i.getValue() > 1) {
                list.add(i.getKey());
            }
        }
        return list;
        
    }
    public static void main(String[] args) {
        // 1 2 3 4 5 1 find the duplicate
        Scanner scanner =  new Scanner(System.in);
        int size = scanner.nextInt();
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = scanner.nextInt();
        }
        System.out.println(findDuplicate(array));
    }
}