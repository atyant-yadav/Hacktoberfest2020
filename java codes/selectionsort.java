import java.util.ArrayList;
import java.util.Random;

public class selectionsort {

    public static void SelectionSort(ArrayList<Integer> v){
        int size = v.size();
        Integer swap;
        
        for (int i=0; i<size-1; i++){
            for (int j=i+1; j<size; j++){
                if(v.get(j)<v.get(i)){
                    swap = v.get(i);
                    v.set(i, v.get(j));
                    v.set(j, swap);
                }
            }
        }
    }
    
    public static void main(String[] args) {
        int size = 10;
        ArrayList<Integer> v = new ArrayList<>();
        
        System.out.print("Initial vector: ");
        
        for (int i=0; i<size; i++){
            Random r = new Random();
            Integer value = r.nextInt(50);
            System.out.print(value+" ");
            v.add(value);
        }
        
        System.out.println("");
        SelectionSort(v);
        System.out.print("Ordered vector: ");
        
        for (int i=0; i<size; i++){
            System.out.print(v.get(i)+" ");
        }
        System.out.println("");
    }
    
}
