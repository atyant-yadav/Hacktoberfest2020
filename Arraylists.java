import java.util.*;  
class ArryaLists{  
   public static void main(String args[]){  
        
      ArrayList<String> city_List=new ArrayList<String>();  
      
      city_List.add("Delhi");
      city_List.add("Mumbai");
      city_List.add("Chennai");
      city_List.add("Kolkata");
      
      System.out.println("Initial ArrayList:" + city_List);
     
      city_List.add(1, "Jaipur");
     
      System.out.println("\nrrayList after adding element at index 1:" + city_List);
      
      ArrayList<String> more_Cities = new ArrayList<String>(Arrays.asList("Pune", "Hyderabad"));
     
      city_List.addAll(4,more_Cities);
     
      System.out.println("\nArrayList after adding list at index 4:" + city_List);
   }  