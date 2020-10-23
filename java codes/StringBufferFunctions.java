import java.io.*; 
import java.lang.*; 
import java.util.*; 

class StringBufferFunctions
{ 
    public static void main(String args[])throws IOException 
    { 
        System.out.println("StringBufferFunctions:\n "); 
        int ch ;
        StringBuffer obj = new StringBuffer("Mukesh Ambani is the richest man."); 
       
        Scanner br = new Scanner(System.in);  
        System.out.println("Default String: " + obj);
        while(1!=0)
        { 
            System.out.println("1.Find Length"); 
            System.out.println("2.Find Capacity");
            System.out.println("3.Set Length");
            System.out.println("4.Set Char At Given Position"); 
            System.out.println("5.Append"); 
            System.out.println("6.Delete"); 
            System.out.println("7.Substring"); 
            System.out.println("8.Insert"); 
            System.out.println("9.Reverse");  
            System.out.println("10.Exit");
            System.out.println("Enter Your Choice(1-10): "); 
            //ch = Integer.parseInt(br.readLine()); 
            ch = br.nextInt();
            switch(ch)
            { 
                case 1 : System.out.println("Length is: " + obj.length()); 
                         break; 

                case 2 : System.out.println("Capacity is: " + obj.capacity()); 
                         break; 

                case 3 : System.out.println("Enter the length of the string"); 
                         obj.setLength(br.nextInt()); 
                         System.out.println(obj); 
                         break;
                        
                case 4 : System.out.println("Enter the index: "); 
                         int index = br.nextInt(); 
                         System.out.println("Enter the character");  
                         char charac = br.next().charAt(0);  
			 obj.toString();
                         obj.setCharAt(index,charac); 
                         System.out.println(obj.toString()); 
                         break; 
                        
                case 5 : br.nextLine();
                         System.out.println("Enter the string"); 
                         String word_1 = br.nextLine(); 
                         obj.append(word_1); 
                         System.out.println(obj);
                         break; 

                case 6 :
		       	 System.out.println("Enter the start index: "); 
                         int start_index_1 = br.nextInt();  
                         System.out.println("Enter the last index: "); 
                         int last_index_1 = br.nextInt();  
                         obj.delete(start_index_1,last_index_1); 
                         System.out.println(obj); 
                         break;
                        
                case 7 : System.out.println("Enter the start index: "); 
                         int start_index_2 = br.nextInt();  
                         System.out.println("Enter the last index: "); 
                         int last_index_2 = br.nextInt();   
                         System.out.println( obj.substring(start_index_2,last_index_2)); 
                         break;

                 case 8 : System.out.println("Enter the start index: "); 
                          int start_index_3 = br.nextInt();   
                          System.out.println("Enter the word"); 
                          br.nextLine(); 
                          String word_2 = br.nextLine();   
                          System.out.println(obj.insert(start_index_3 , word_2));
                          break; 

                 case 9 : obj.reverse(); 
                          System.out.println("String is " + obj); 
                          break; 

                 case 10 : System.exit(0); 

                 default : System.out.println("Invalid Entry");
                         

            }


        }

    }
}