package Solution;

import java.io.*;
import java.lang.*;
import java.util.Scanner;



//******************************************************Key Generation************************************
 class KeyGenerate{
	
	 private int[] key = new int[10];
	 private int[] key1 = new int[8];
	 private int[] key2 = new int[8];
	 KeyGenerate()
	{
		
	}
	 
	 void generateKey(String inputKey)
	 {
		 int[] key = new int[10];
		 
			
			char c1;
			String ts ;
			
			try
			{
			for(int i=0;i<10;i++)
		    {
		       c1 = inputKey.charAt(i);
		       ts = Character.toString(c1);
		       key[i] = Integer.parseInt(ts);
			   
			   if(key[i] !=0 && key[i]!=1)
			   {
				System.out.println("\n .. Invalid Key ..");
				System.exit(0);
				return ;
			   }
		    }
			}
			catch(Exception e)
			{
				System.out.println("\n .. Invalid Key .. ");
				System.exit(0);
				return ;
				
			}
			
			this.key = key;
			
			
			System.out.println("Input Key : ");
			for(int i=0 ; i<10 ; i++)
			{
				System.out.print(this.key[i]);
			}
			System.out.println("\n");                          // till the input key is converted from the string to key array.
			
			
			// Applying P10 to the key
			permutationP10();
			System.out.println("After Permutation(P10) Key : ");
			for(int i=0 ; i<10 ; i++)
			{
				System.out.print(this.key[i]);
			}
			System.out.println("\n");  
			
			// Aplying the left shift 1 to the both seperate 5 parts of the key
			
			leftshiftLS1();
			System.out.println("After LeftShift LS-1 Key :  ");
			for(int i=0 ; i<10 ; i++)
			{
				System.out.print(this.key[i]);
			}
			System.out.println("\n"); 
			
			
			// the key 1 from the key is 
			
			this.key1 = permutationP8();
			System.out.println("The key1 generated is : ");
			for(int i=0 ; i<8 ; i++)
			{
				System.out.print(this.key1[i]);
			}
			System.out.println("\n"); 
			
			// now to find the key2 we need to do left shift 2 
			
			leftshiftLS2();
			
			System.out.println("After LeftShift LS-2 Key :  ");
			for(int i=0 ; i<10 ; i++)
			{
				System.out.print(this.key[i]);
			}
			System.out.println("\n"); 
			
			
			// again applying P8 for the key that gives us the key2
			
			this.key2 = permutationP8();
			System.out.println("The key2 generated is : ");
			for(int i=0 ; i<8 ; i++)
			{
				System.out.print(this.key2[i]);
			}
			System.out.println("\n"); 
			
	
	 }
	 
	 
	 // this is the permutation P10 for the key;
	 
	 /* Perform permutation P10 on 10-bit key 
	  P10(k1, k2, k3, k4, k5, k6, k7, k8, k9, k10) = (k3, k5, k2, k7, k4, k10, k1, k9, k8, k6)
	  */
	 // the above is the permutaion array for P10
	 
	  private void permutationP10()
	  {
	   
	    
	    int[] permuteArr = {2,4,1,6,3,9,0,8,7,5};

	    
	    key = permute(permuteArr , 10);
	        
	  }
	  
	  // this is the left shift 1  code
	  
	  private void leftshiftLS1()
	  {
	    int[] temp = new int[10];
	    
	    int[] leftPart = new int[5];
	    int[] rightPart = new int[5];
	    
	    for(int i =0 ; i<5 ; i++)
	    {
	    	leftPart[i] = key[i];
	    	rightPart[i] = key[i+5];
	    }
	    
	    shift(leftPart , 1);
	    shift(rightPart , 1);
	  
	    for(int i =0 ; i<5 ; i++)
	    {
	    	temp[i] = leftPart[i];
	    	temp[i+5] = rightPart[i];
	    }
	    
	    
	    key = temp;
	    
	  }
	 
	  
	  // this is the permutation P8 procedure 
	  // the following is permutaion P8 array
	  // P8[ 6 3 7 4 8 5 10 9 ]
	  
	  private int[] permutationP8()
	  {
	    int[] temp = new int[8];
	    
	    int[] permuteArr = {5,2,6,3,7,4,9,8};

	    temp = permute(permuteArr , 8);

	    return temp;
	        
	  }
	  
	  
	  // this is the left shift 2  code

	  private void leftshiftLS2()
	  {
		  int[] temp = new int[10];
		    int[] leftPart = new int[5];
		    int[] rightPart = new int[5];
		    for(int i =0 ; i<5 ; i++)
		    {
		    	leftPart[i] = key[i];
		    	rightPart[i] = key[i+5];
		    }
		    shift(leftPart , 2);
		    shift(rightPart , 2);
		    for(int i =0 ; i<5 ; i++)
		    {
		    	temp[i] = leftPart[i];
		    	temp[i+5] = rightPart[i];
		    }
		    key = temp;
	    
	  }
	  public int[] getK1()
	  {
	      return key1;
	  }

	  public int[] getK2()
	  {
		  return key2;
	  }
//    the permutator
	  public int[] permute(int[] permuteArr, int size )
	  
	  {
		  int[] temp = new int[size];
		  for (int i = 0; i< size ; i++)
		  {
			  temp[i] = key[permuteArr[i]];
		  }
		  return temp;
	  }
//    the array rotator
	  public void shift(int[] nums, int k) {
	        
		    int[] tempArr = nums.clone();
		        int len = nums.length;
		        k = k % len;
		        k=len- k;
		        for(int i = 0 ; i< len ; i++)
		        {
		            nums[i] = tempArr[(i+(len-k))%len];
		        }
		    }
	  
	  
	 
}

//******************************************************Key Generation************************************
 
 
 //**************************************************Encryption and Decryption********************************************
 
 class Encryption
 {
   private int[] key1 = new int[8];
   private int[] key2 = new int[8];
   private int[] plainText = new int[8];
   
   Encryption()
   {
	   
   }
   
   void SaveParameters(String plaintext , int[] k1, int[] k2)
   {
 	int[] plainText = new int[8];

 		
 	char c1;
 	String ts ;
 	
 	try
 	{
 	for(int i=0;i<8;i++)
     {
        c1 = plaintext.charAt(i);
        ts = Character.toString(c1);
        plainText[i] = Integer.parseInt(ts);
 	   
 	   if(plainText[i] !=0 && plainText[i]!=1)
 	   {
 		System.out.println("\n .. Invalid Plaintext ..");
 		System.exit(0);
 		return ;
 	   }
     }
 	}
 	catch(Exception e)
 	{
 		System.out.println("\n .. Invalid Plaintext .. ");
 		System.exit(0);
 		return ;
 		
 	}
 	
     this.plainText = plainText;
     
      System.out.println("Plaintext array : ");
      for(int i=0 ; i<8 ; i++)
      {
    	  System.out.print(plainText[i]);
      }
 	 System.out.println("\n");
 	
     this.key1 = k1;
     this.key2 = k2;

   }                                       ///////////////// assigned the plain text and the keys.
   
	  public int[] permute(int[] permuteArr, int size , int [] reference)
	  
	  {
		  int[] temp = new int[size];
		  for (int i = 0; i< size ; i++)
		  {
			  temp[i] = reference[permuteArr[i]];
		  }
		  return temp;
	  }
   
   
   /** perform Initial Permutation in following manner [2 6 3 1 4 8 5 7] **/
   void InitialPermutation()
   {
     int[] temp = new int[8];
     
     int[] permuteArr = {1,5,2,0,3,7,4,6};
     
     temp = permute(permuteArr, 8 , plainText);
 
     plainText = temp;
 	
 	 System.out.println("Initial Permutaion(IP) : ");
 	for(int i=0 ; i<8 ; i++)
    {
  	  System.out.print(this.plainText[i]);
    }
      System.out.println("\n");
 	
   }                                                      // function for the initial permutation IP
   
   
   void InverseInitialPermutation()
   {
     int[] temp = new int[8];
     
     
     int[] permuteArr = {3,0,2,4,6,1,7,5};
     
     temp = permute(permuteArr, 8, plainText);
 
     plainText = temp;
     
     
     System.out.println("Inverse Initial Permutaion(IIP) : ");
  	for(int i=0 ; i<8 ; i++)
     {
   	  System.out.print(this.plainText[i]);
     }
       System.out.println("\n");
 	
 	
   }														// Function for the inverse initial permutation
   
   
   /* mappingF . arguments 4-bit right-half of plaintext & 8-bit subkey */ 
   int[] mappingF(int[] R, int[] SK)
   {
     int[] temp = new int[8];
     
     int[] permuteArr = {3,0,1,2,1,2,3,0};          // EXPANSION/PERMUTATION [4 1 2 3 2 3 4 1] 
     
     temp = permute(permuteArr, 8, R);
 
     plainText = temp;

 	 System.out.println("EXPANSION/PERMUTATION on RH : ");
 	for(int i=0 ; i<8 ; i++)
    {
  	  System.out.print(temp[i]);
    }
      System.out.println("\n");
 	 
     // Bit by bit XOR with sub-key
     temp[0] = temp[0] ^ SK[0];
     temp[1] = temp[1] ^ SK[1];
     temp[2] = temp[2] ^ SK[2];
     temp[3] = temp[3] ^ SK[3];
     temp[4] = temp[4] ^ SK[4];
     temp[5] = temp[5] ^ SK[5];
     temp[6] = temp[6] ^ SK[6];
     temp[7] = temp[7] ^ SK[7];
     
     System.out.println("XOR With Key : ");
     for(int i=0 ; i<8 ; i++)
     {
   	  System.out.print(temp[i]);
     }
      System.out.println("\n");
      
      
      
   // S-Boxes
      final int[][] S0 = { {1,0,3,2} , {3,2,1,0} , {0,2,1,3} , {3,1,3,2} } ;
      final int[][] S1 = { {0,1,2,3},  {2,0,1,3}, {3,0,1,0}, {2,1,0,3}} ;
      
     
        int d11 = temp[0]; // first bit of first half 
        int d14 = temp[3]; // fourth bit of first half
        
  	  int row1 = BinaryOp.BinToDec(d11,d14); // for input in s-box S0
        
  	  
        int d12 = temp[1]; // second bit of first half
        int d13 = temp[2]; // third bit of first half      
        int col1 = BinaryOp.BinToDec(d12,d13); // for input in s-box S0
        
  	  
        int o1 = S0[row1][col1]; 
  	      
  	  int[] out1 = BinaryOp.DecToBinArr(o1);
  	 
  	System.out.print("S-Box S0: ");
  	for(int i=0 ; i<2 ; i++)
    {
  	  System.out.print(out1[i]);
    }
       System.out.print("\n");

  	 int d21 = temp[4]; // first bit of second half
        int d24 = temp[7]; // fourth bit of second half
        int row2 = BinaryOp.BinToDec(d21,d24);
  	  
  	  int d22 = temp[5]; // second bit of second half
  	  int d23 = temp[6]; // third bit of second half
  	  int col2 = BinaryOp.BinToDec(d22,d23);
  	  
  	  int o2 = S1[row2][col2];
  	  	 
  	  int[] out2 = BinaryOp.DecToBinArr(o2); 

  	System.out.print("S-Box S1: ");
  	for(int i=0 ; i<2 ; i++)
    {
  	  System.out.print(out2[i]);
    }
       System.out.print("\n");
  		
        //4 output bits from 2 s-boxes
  	  int[] out = new int[4];
  	  out[0] = out1[0];
        out[1] = out1[1];
  	  out[2] = out2[0];
  	  out[3] = out2[1];
  	  
  	  //permutation P4 [2 4 3 1]
  	  
  	  int [] O_Per = new int[4];
  	  O_Per[0] = out[1];
  	  O_Per[1] = out[3];
  	  O_Per[2] = out[2];
        O_Per[3] = out[0];
  	  
        System.out.print("Output of mappingF : ");
        for(int i=0 ; i<4 ; i++)
        {
      	  System.out.print(O_Per[i]);
        }
       System.out.print("\n");  
  	 
  	 return O_Per;
    }                                									//applied the s boxes
      
      
   /* fK(L, R, SK) = (L (XOR) mappingF(R, SK), R) .. returns 8-bit output*/
   int[] functionFk(int[] L, int[] R,int[] SK)
   {	
 	int[] temp = new int[4];
 	int[] out = new int[8];
 	
 	
 	temp = mappingF(R,SK);
 	
 	
 	//XOR left half with output of mappingF 
 	out[0] = L[0] ^ temp[0];
 	out[1] = L[1] ^ temp[1];
 	out[2] = L[2] ^ temp[2];
 	out[3] = L[3] ^ temp[3];
 	
 	out[4] = R[0];
 	out[5] = R[1];
 	out[6] = R[2];
 	out[7] = R[3];
 	
 	
 	return out;
 	
 	
   }
   
   //////
   
   /** switch function (SW) interchanges the left and right 4 bits **/
   int[] switchSW(int[] in)
   {
 	
 	int[] temp = new int[8];
 	
 	temp[0] = in[4];
 	temp[1] = in[5];
 	temp[2] = in[6];
 	temp[3] = in[7];
   
     temp[4] = in[0];
 	temp[5] = in[1];
 	temp[6] = in[2];
 	temp[7] = in[3];	
 	
 	return temp;
   }
   
   
   
   int[] encrypt(String plaintext , int[] LK, int[] RK)
   {
 	
 		
 	SaveParameters(plaintext,LK,RK);
 	
 	System.out.print("\n---------------------------------------\n");
 	InitialPermutation();
 	System.out.print("\n---------------------------------------\n");
 	//saperate left half & right half from 8-bit pt
 	int[] LH = new int[4];
 	int[] RH = new int[4];
 	LH[0] = plainText[0];
 	LH[1] = plainText[1];
 	LH[2] = plainText[2];
 	LH[3] = plainText[3];
 	

 	RH[0] = plainText[4];
 	RH[1] = plainText[5];
 	RH[2] = plainText[6];
 	RH[3] = plainText[7];
 	
 	
 	System.out.print("First Round LH : ");
 	
 	for(int i=0 ; i<4 ; i++)
    {
  	  System.out.print(LH[i]);
    }
 	
 	System.out.print("\n");
 	 
 	System.out.print("First Round RH: ");
 	for(int i=0 ; i<4 ; i++)
    {
  	  System.out.print(RH[i]);
    }
      System.out.print("\n");
 	 
 	//first round with sub-key K1
 	int[] r1 = new int[8];
 	r1 = functionFk(LH,RH,key1);
 	
 	System.out.print("After First Round : ");
 	for(int i=0 ; i<8 ; i++)
    {
  	  System.out.print(r1[i]);
    }
      System.out.print("\n");
      System.out.print("\n---------------------------------------\n");
 	//Switch the left half & right half of about output
 	int[] temp = new int[8];
 	temp = switchSW(r1);
 	
 	System.out.print("After Switch Function : ");
 	for(int i=0 ; i<8 ; i++)
    {
  	  System.out.print(temp[i]);
    }
 	System.out.print("\n---------------------------------------\n");
 	// again saperate left half & right half for second round
 	LH[0] = temp[0];
 	LH[1] = temp[1];
 	LH[2] = temp[2];
 	LH[3] = temp[3];
 	
 	RH[0] = temp[4];
 	RH[1] = temp[5];
 	RH[2] = temp[6];
 	RH[3] = temp[7];

 	
 	System.out.print("Second Round LH : ");
 	for(int i=0 ; i<4 ; i++)
    {
  	  System.out.print(LH[i]);
    }
      System.out.print("\n");
 	 
      System.out.print("Second Round RH: ");
      for(int i=0 ; i<4 ; i++)
      {
    	  System.out.print(RH[i]);
      }
      System.out.print("\n");
 	 
 	 
 	//second round with sub-key K2
 	int[] r2 = new int[8];
 	r2 = functionFk(LH,RH,key2);
 	
 	plainText = r2;
 	
 	System.out.print("After Second Round : ");
 	for(int i=0 ; i<8 ; i++)
    {
  	  System.out.print(this.plainText[i]);
    }
      System.out.print("\n");
      System.out.print("\n---------------------------------------\n");
 	 
 	InverseInitialPermutation();
 	
 	System.out.print("After Inverse IP (Result) : ");
 	for(int i=0 ; i<8 ; i++)
    {
  	  System.out.print(this.plainText[i]);
    }
      System.out.print("\n");
 	 
 	//Encryption done... return 8-bit output .
 	return plainText;
 	

 	
   }
      
   
   
 }
 	
 
 //**************************************************Encryption and Decryption ********************************************

 



public class SDES {
	

    
    public static void main(String args[]) throws NumberFormatException, IOException
    {
    	KeyGenerate KG = new KeyGenerate();
    	Encryption enc = new Encryption();
    	
    	Scanner sc = new Scanner(System.in);
    	int[] cipherText = new int[8];
    	
    	String plainText ;
    	System.out.print("Enter 8-bit Plaintext : ");
    	plainText= sc.next();
    	
        System.out.print("Enter 10-bit Key : ");
        String key = sc.next();
        
        KG.generateKey(key);
        
        cipherText = enc.encrypt( plainText ,KG.getK1(),KG.getK2());
        
        System.out.println(" \n Decryption  ");
        System.out.print("Enter 8-bit Ciphertext : ");
    	plainText = sc.next();
    	System.out.println(" \n ");
    	
    	System.out.print("Enter 10-bit Key : ");
        key = sc.next();
        
        System.out.println(" \n ");
        
        System.out.println("\n For decryption Two Sub-keys will be used in reverse order \n");
        KG.generateKey(key);
        
        cipherText = enc.encrypt( plainText ,KG.getK2(),KG.getK1());
    	
    }

}

class BinaryOp
{
  /** Gets binary digits as arguments & returns decimal number 
  for example input args [1,0,0] will return 4 **/ 
  static int BinToDec(int...bits)
  {
  
         
     int temp=0;
     int base = 1;
     for(int i=bits.length-1 ; i>=0;i--)
     {
        temp = temp + (bits[i]*base);
        base = base * 2 ;
     }
      
      return temp;
  }
  
  /** gets decimal number as argument and returns array of binary bits 
  for example input arg [10] will return  [1,0,1,0]**/
  static int[] DecToBinArr(int no)
  {
    // 13 1
    // 6  0
    // 3  1
    // 1  1
    // 0  
    
	
	if(no==0)
	{
		int[] zero = new int[2];
		zero[0] = 0;
		zero[1] = 0;
		return zero;	
	}
    int[] temp = new int[10] ;
	
    
	int count = 0 ;
    for(int i= 0 ; no!= 0 ; i++)
    {
      temp[i] = no % 2;
      no = no/2;
	  count++;
    }
    
	
	int[] temp2 = new int[count];
	
	
	for(int i=count-1, j=0;i>=0 && j<count;i--,j++)
	{
		temp2[j] = temp[i];
	}
	
	//because we requires 2-bits as output .. so for adding leading 0
    if(count<2)
	{
		temp = new int[2];
		temp[0] = 0;
		temp[1] = temp2[0];
		return temp;
	}
	 
	return temp2;
  }
}

















