/*

Create a passenger reservation system for an airline using linked lists. Create one linked list for each flight, which will have its unique flight number. Each node of a linked list will have passenger name. You have to develop code  i) To enter passenger data for a specified flight. ii) To have a provision of adding new passengers on the list. iii) To enable passengers to cancel their flights. iv) To indicate number of passengers for each flight. v) To print names of passengers for each flight. The first line of input data file will have an integer indicating number of flights followed by names of flights. Each line of the file after that will contain an operation to be carried out on a specified flight. Operation codes are indicated below: 1 – Booking a reservation. This will be followed by flight number, number of passengers to be booked, names of passengers (first names only). 2 - Cancelling a reservation. This will be followed by flight number, number of passengers to be cancelled, names of passengers. 3-printing names of passengers on specified flight, if there is no passenger, then Print ‘No Passenger’ 4- Print number of passengers on specified flight, if there is no passenger, then Print ‘0’.  Each operation code will be followed by flight number (and name of passenger if needed) Sample input file (input.txt) 
2 A1 A2 1 A1 4 Raja Mohan Phalguni  Mahima 1 A2 3 Sunder Rashmi Srikant 3 A1 2 A1 1 Phalguni 1 A2 1 Mohit 4 A2 2 A1 1 Raja 3 A1 
 
Sample Output (output.txt) 
Raja Mohan Phalguni  Mahima 4 Mohan Mahima …
*/

import java.util.Scanner;

public class PRS  {
	static Scanner in=new Scanner(System.in);
	
	
	static class passnode
	{

		String passname;
		passnode next;
		
		passnode(String name)
		{
	
			passname=name;
			next=null;
		}
		passnode()
		{
			
		}
		
		
	}
	
	
	static void insert(passnode fn[],String flights[])
	{
		System.out.println("ENTER FLIGHT NAME");
        String f=in.next();
		System.out.println("ENTER PASSENEGER NAME");
	    String name=in.next();
	    int flag=0;
	    
	 
	    for(int i=0;i<fn.length;i++)
	    {
	    	
	    	if(flights[i].equals(f))
	    	{
	    		
	    		 passnode p=new passnode(name);
	    		    if(fn[i]==null)
	    		    {
	    		    	fn[i]=p;
	    		    }
	    		    else
	    		    {
	    		    	passnode cur=new passnode();
	    		    	cur=fn[i];
	    		    	while(cur.next!=null)
	    		    	{
	    		    		cur=cur.next;
	    		    	}
	    		    	
	    		    	cur.next=p;
	    		    	  	
	    		    	
	    		    }
	    		    flag=1;
	    		break;
	    	}
	    	
	    
	    	
	    	
	    }
		if(flag==0)
    	{
			System.out.println("FlIGHT NOT FOUND");
    		
    	}
	    
	    
	   
	    
	    
	}
	
	
	static void cancel(passnode fn[],String flights[])
	{
		System.out.println("ENTER FLIGHT NAME");
        String f=in.next();
		System.out.println("ENTER PASSENEGER NAME TO BE CANCELLED");
	    String name=in.next();
	    
	    int flag=0;

		for(int i=0;i<fn.length;i++)
		{
			if(flights[i].equals(f))
			{
				              if(fn[i]==null)
				              {
				            	  System.out.println("NO PASSENEGR IN FLIGHT CANNOT CANCEL");
				              }
				              
				              else
				              {
				            	  
				            
		    	
		    	             if(fn[i].passname.equals(name) )
		    	                 {
		    		                    fn[i]=fn[i].next;
		    		                    flag=1;
		    		                    
		    	                 }
		    	             
		    	             else
		    	             {
		    	         		passnode cur=new passnode();
		    	        		passnode prev=new passnode();
		    	  	             cur=fn[i].next;
			    			     prev=fn[i];
					while(true)
					{
						if(cur.passname.equals(name) && cur.next!=null)
						{
							prev.next=cur.next;
							
							flag=1;
							break;
							
							
						}
						
						else if(cur.passname.equals(name) && cur.next==null)
						{
							prev.next=null;
							flag=1;
							break;
						}
						else
						{
							if(cur.next!=null)
							{
							prev=cur;
							cur=cur.next;
							}
							
						}
						
						
						
					  }
					
					
		    	            	 
		    	             }
		    	
		  
				
				              }
				
				
			}//if
			
			
			
			
			
			
			
		}       //for
    	
		
		if(flag==0)
		{
			System.out.println("FLIGHT AND PASSENEGR DETAILS NOT FOUND");
		}
		
		
		
		
	}
	
	
	
	static void noofpassen(passnode fn[],String flights[])
	{
		System.out.println("ENTER FLIGHT NAME");
        String f=in.next();
          int count=0;
	    int flag=0;
	    for(int i=0;i<fn.length;i++)
	    {
	    	if(flights[i].equals(f))
	    	{
	    		 passnode cur=new passnode();
	    		 cur=fn[i];
	    		 if(fn[i]==null)
	    		 {
	    			 System.out.println("NO PASSENGER");
	    		 }
	    		 else
	    		 {
	    		 while(cur.next!=null)
	    		 {
	    			 count++;
	    			 cur=cur.next;
	    		 }
	    		 
	    		 
	    		 System.out.println(count+1);
	    		 }
	    		    flag=1;
	    		break;
	    	}
	    	
	    
	    	
	    	
	    }
		if(flag==0)
    	{
			System.out.println("FlIGHT NOT FOUND");
    		
    	}
	    
	    
	   
		
		
		
		
	}
	
	
	static void passenname(passnode fn[],String flights[])
	{
		System.out.println("ENTER FLIGHT NAME");
        String f=in.next();
         
	    int flag=0;
	    for(int i=0;i<fn.length;i++)
	    {
	    	if(flights[i].equals(f))
	    	{
	    		 passnode cur=new passnode();
	    		 cur=fn[i];
	    		 
	    		 if(cur==null)
	    		 {
	    			 System.out.println("NO PASSENGERS");
	    		 }
	    		 else
	    		 {
	    			 
	    		 
	    		 while(true)
	    		 {
	    			 System.out.println(cur.passname);
	    			 
	    			 if(cur.next==null)
	    			 {
	    				 break;
	    			 }
	    	         
	    			 cur=cur.next;
	    			 
	    			 
	    		 }
	    		 
	    		 
	    		 }
	    		    flag=1;
	    		break;
	    	}
	    	
	    
	    	
	    	
	    }
		if(flag==0)
    	{
			System.out.println("FlIGHT NOT FOUND");
    		
    	}
	    
	    
	   
		
		
		
		
	}
	
	
	
	
	
	
	
	


	public static void main(String[] args) {
		
		System.out.println("ENETR THE NO OF FLIGHTS");
		int n=in.nextInt();
		
		while(n<=0)
		{
			System.out.println("WRONG INPUT TYPE PLEASE TRY AGAIN ");
			n=in.nextInt();
		}
		
		passnode headnodes[]=new passnode[n];
		String flights[]=new String[n];
		System.out.println("ENTER THE NAME OF FLIGHTS");
		for(int i=0;i<n;i++)
		{
			flights[i]=in.next();
		}
		
	
		
		
		
		System.out.println("FLIGHTS ADDED");
	
		while(true)
		{
			System.out.println("1: BOOK FLIGHT TICKET");
			System.out.println("2: CANCEL FLIGHT TICKET");
			System.out.println("3: SHOW NO OF PASSENGERS IN FLIGHT");
			System.out.println("4: SHOW NAME OF PASSENGERS IN FLIGHT");
			System.out.println("0: EXIT");
			int ch=in.nextInt();
			int f=1;
			switch(ch)
			{
			
			case 1:
				insert(headnodes,flights);
			break;
			
			case 2:cancel(headnodes,flights);
			break;
			
			case 3:noofpassen(headnodes,flights);
			break;
			
			case 4:
				passenname(headnodes,flights);
			break;
			
			case 0:f=0;
					break;
			
			
			default:System.out.println("WRONG INPUT");
			
			
			
			}
			if(f==0)
			{
				
				System.out.println("XXX  PORGRAM STOPPED XXX");
				break;
				
			}
			
		}

	
		

		
		
			

	}

}
