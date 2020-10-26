public class patterns{
    public static void main(String[] args){
        pattern1(5);
        pattern2(5);
        pattern3(5);
        pattern4(5);
        pattern5(5);
        pattern6(5);
        pattern7(5);
        pattern8(5);
        pattern9(5);
        pattern10(5);
        pattern11(5);
        pattern12(5);
        pattern13(5);
        pattern14(5);
        pattern15(5);
        pattern16(5);
        pattern17(5);
        pattern18(5);
        pattern19(5);
        pattern20(5);
        pattern22(5);
        pattern23(5);

    }
    
    public static void pattern24(int n){
        int val1=1,o=n*n+1;
        
        int col=2*n;
        int sp=0;
        for(int i=n;i>=1;i--){
            for(int j=1;j<=sp;j++)
            System.out.print("\t");
            for(int j=1;j<=col/2;j++)
            System.out.print(val1++ + "*\t");
            int val2=o;
            for(int j=1;j<=col/2;j++)
            {if(j==col/2)
            System.out.print(val2++);
            else
            System.out.print(val2++ +"*\t");}
            o-=i-1;

            System.out.println();
            col-=2;
            sp++;

        }
    }
    public static void pattern23(int n){
        int nrows = 2*n-1;
        int nstars = n;
        int nspaces = n;
        int irows = 1;
        while(irows<=nrows){
            //print spaces
            for(int ispaces = nspaces;ispaces>=1;ispaces--){
                System.out.print("\t");
            }
            //print stars
            for(int istars=nstars;istars>=1;istars--){
                System.out.print("*\t");
            }
            //nextline
            System.out.println();
            //prep for next row
            if(irows<=nrows/2){
                nstars--;
                nspaces--;
            }
            else{
                nstars++;
                nspaces++;
            }
            irows++;
            
        }

    }
    public static void pattern1(int n){
        int nrows = n;
        int nstars = 1;
        int irows = 1;
        while(irows<=nrows){
            //print stars
            for(int istar=1;istar<=nstars;istar++){
                System.out.print("*\t");
            }
            //next line
            System.out.println();
            //prep for next row
            nstars++;
            irows++;
        }
    }
    public static void pattern2(int n){
        int nrows = n;
        int nstars = n;
        int irows = 1;
        while(irows<=nrows){
            //print stars
            for(int istar=1;istar<=nstars;istar++){
                System.out.print("*\t");

            }
            //next line
            System.out.println();
            //prep for next row;
            nstars--;
            irows++;
        }
    }

    public static void pattern3(int n){
        int nrows = n;
        int nstars=1;
        int nspaces = n-1;
        int irows = 1;
        while(irows<=nrows){
            //print spaces
            for(int ispaces=1;ispaces<=nspaces;ispaces++){
                System.out.print("\t");
            }
            //print stars
            for(int istars=1;istars<=nstars;istars++){
                System.out.print("*\t");
            }
            //next line
            System.out.println();
            //prep for next row
            nspaces--;
            nstars++;
            irows++;
        }
    }

    public static void pattern4(int n){
        int nrows = n;
        int nstars = n;
        int nspaces = 0;
        int irows = 1;
        while(irows<=nrows){
            //print spaces
            for(int ispaces = 0;ispaces<nspaces;ispaces++){
                System.out.print("\t");
            }
            //print stars
            for(int istars =1;istars<=nstars;istars++){
                System.out.print("*\t");
            }
            //next line
            System.out.println();
            //prep for next row
            nspaces++;
            nstars--;
            irows++;

        }
    }

    public static void pattern5(int n){
        int nrows = n;
        int nstars = 1;
        int nspaces = n/2;
        int irows = 1;
        while(irows<=nrows){
                //print spaces
                for(int ispaces =0;ispaces<nspaces;ispaces++){
                    System.out.print("\t");
                }
                //print stars
                for(int istar=1;istar<=nstars;istar++){
                    System.out.print("*\t");
                }
                if(irows<n/2+1){
            
                nspaces--;
                nstars+=2;
            
            }
            else{
                nspaces++;
                nstars-=2;
                }
            System.out.println();
            irows++;

        }
            
    }

    public static void pattern6(int n){
        int nrows = n;
        int nstars = n/2+1;
        int irows = 1;
        int nspaces = 1;
        while(irows<=nrows){
            //print stars
            for(int istars = 1;istars<=nstars;istars++){
                System.out.print("*\t");
            }
            //print space
            for(int ispaces = 1;ispaces<=nspaces;ispaces++){
                System.out.print("\t");
            }
            //print stars
            for(int istars = 1;istars<=nstars;istars++){
                System.out.print("*\t");
            }
            //next line
            System.out.println();
            //prep for next row
            if(irows<=nrows/2){
                nspaces+=2;
                nstars--;    
            }
            else{
                nspaces-=2;
                nstars++;
            }
            
            irows++;

        }
    
    }

    public static void pattern7(int n){
        int nrows = n;
        int nstars = 1;
        int nspaces = 0;
        int irows = 1;
        while(irows<=nrows){
            //print space
            for(int ispaces=0;ispaces<nspaces;ispaces++){
                System.out.print("\t");
            }
            //print star
            System.out.print("*\t");
            //next line
            System.out.println();
            //prep for next row
            nspaces++;
            irows++;
        }
    }

    public static void pattern8(int n){
       int nrows = n;
       int nstars = 1;
       int nspaces = n;
       int irows = 1;
       while(irows<=nrows){
           //print spaces
           for(int ispace=1;ispace<nspaces;ispace++){
               System.out.print("\t");
           }
           //print stars
           System.out.print("*\t");
           //next line
           System.out.println();
           //prep for next row
           nspaces--;
           irows++;
       }
   }

   public static void pattern9(int n){
       for(int i=1;i<=n;i++){
           for(int j=1;j<=n;j++){
               if(i==j||i+j==n+1){
                   System.out.print("*\t");
               }
               else{
                   System.out.print("\t");
               }
           }
           System.out.println();
       }
   }

   public static void pattern10(int n){
       int nrows = n;
       int nstars = 1;
       int nspaces = n/2;
       int irows = 1;
       while(irows<=nrows){
        //print spaces
        for(int ispaces = 1; ispaces<=nspaces;ispaces++){
            System.out.print("\t");
        }
        //print stars
        for(int istar = 1;istar<=nstars;istar++){
            if(irows>1&&irows<nrows+1&&istar>1&&istar<nstars){
                System.out.print("\t");
            }
            else{
                System.out.print("*\t");
            }
            
        }
        if(irows<=nrows/2){
            nspaces--;
            nstars+=2;
        }
        else{
            nspaces++;
            nstars-=2;
        }
        //next line
        System.out.println();
        //prep for next row
        
        irows++;
       }
   }

   public static void pattern11(int n){ //floyds triangle
       int nrows =  n;
       int nstars = 1;
       int irows = 1;
       int val = 1;
       while(irows<=nrows){
           //prit stars
           for(int istar=1;istar<=nstars;istar++){
               System.out.print(val+"\t");
               val++;
           }
           //next line
           System.out.println();
           //prep for next row
           nstars++;
           irows++;
       }
   }


   public static void pattern12(int n){ 
    int nrows =  n;
    int nstars = 1;
    int irows = 1;
    int a = 0;
    int b = 1;
    int c = 0;
    while(irows<=nrows){
        //prit stars
        for(int istar=1;istar<=nstars;istar++){
            System.out.print(a+"\t");
            c = a+b;
            a=b;
            b=c; 
        }
        //next line
        System.out.println();
        //prep for next row
        nstars++;
        irows++;
    }
}

    public static void pattern13(int n){  //floyds triangle
        int nrows = n+1;
        int nstars = 1;
        int irows = 1;
        int r=1;
        while(irows<=nrows){
            for(int istars=1; istars<=nstars;istars++){
                //nf
                int res=1;
                int nf = 1;
                for(int i=1;i<=istars;i++){
                    nf = nf*i;
                }
                //rf
                int rf = 1;
                for(int i=1;i<=r;i++){
                    rf = rf*i;
                }
                //nMrf
                int nMrf = 1;
                for(int i=1;i<=(n-r);i++){
                    nMrf = nMrf*i;
                }
                res = (int)nf/(rf*nMrf);
                System.out.print(res+"\t");
            }
            System.out.println();
            nstars++;
            irows++;
        }

    }

    public static void pattern14(int n){
        for(int i =1;i<=10;i++){
            int res = n*i;
            System.out.println(n+" * "+i+" = "+res);
        }
    }

    public static void pattern15(int n){
        int nrows = n;
        int nspaces = n/2;
        int nstars = 1;
        int irows = 1; 
        int val = 1;
        int c = 1;
        while(irows<=nrows){
            //print spaces
            for(int ispaces=1;ispaces<=nspaces;ispaces++){
                System.out.print("\t");
            }
            //print star
            int temp=val;
            for(int istars=0;istars<nstars;istars++){
               
                System.out.print(temp+"\t"); 
                if(irows<=nrows/2){
                    
                   
                    temp++;  
                }
                else{
                    
                    temp--;

                }
                
            }
            //next line
            
            //prep for next row
            if(irows<=nrows/2){
                val++;
                nspaces--;
                nstars+=2;
            }
            else{
                val--;
                nspaces++;
                nstars-=2;
            }
            System.out.println();
            irows++;
        }
    }
    public static void pattern16(int n){
        int nrows = n;
        int nstars = 1;
        int nspaces = 2*n-3;
        int irows = 1;
        int var_size = nstars;
        while(irows<=nrows){
            int val = 1;
            //print star
            for(int istar=1;istar<=nstars;istar++){
                System.out.print(val+"\t");
                val++;
            }
            
            //print spaces
            for(int ispaces=1;ispaces<=nspaces;ispaces++){
                System.out.print("\t");
            }
            //handling last row
            var_size = irows == nrows ? nstars-2 : nstars;
            val = irows == nrows ? val-2 : val-1;
            
            
            //print star
            for(int istar=1;istar<=nstars;istar++){
                System.out.print(val+"\t");
                val--;
            }
            
            //next line
            System.out.println();
            //prep for next row
            nspaces-=2;
            nstars++;;  
            irows++;

        }
    }
    public static void pattern17(int n){
        int nrows = n;
        int nstars = 1;
        int nspaces = n/2;
        int irows = 1;
        while(irows<=nrows){
            //print spaces
            for(int ispaces = 1; ispaces<=nspaces;ispaces++){
                if(irows==n/2+1){
                    System.out.print("*\t");
                }
                else{
                    System.out.print("\t");
                }
                
            }
            //print stars
            for(int istars = 1; istars<=nstars;istars++){
                System.out.print("*\t");
            }
            //next line
            System.out.println();
            //prep for next row
            
            if(irows<=nrows/2){
                nstars++;
            }
            else{
                nstars--;
            }
            irows++;

        }
    }
    public static void pattern18(int n){
        int nrows = n;
        int nstars = n;
        int nspaces = 0;
        int irows = 1;
        while(irows<=nrows){
            //print spaces
            for(int ispaces=0;ispaces<nspaces;ispaces++){
                
                System.out.print("\t");
            }
            //print stars
            for(int istars=1;istars<=nstars;istars++){
                if(irows>1 && irows<=n/2+1 && istars>1 && istars<nstars){
                    System.out.print("\t");
                }
                else{
                    System.out.print("*\t");
                }
                
            }
            //next line 
            System.out.println();
            //prep for next row
            if(irows<n/2+1){
                nstars-=2;
                nspaces++;
            }
            else{
                nstars+=2;
                nspaces--;
            }
            irows++;
        }
    }
    public static void pattern19(int n){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==1){
                   if(j<=n/2+1 || j==n){
                       System.out.print("*\t");
                   }
                   else{
                       System.out.print("\t");
                   }
                }
                else if(i<n/2+1){
                    if(j==n/2+1 || j==n){
                        System.out.print("*\t");
                    }
                    else{
                        System.out.print("\t");
                    }
                }
                else if(i==n/2+1){
                    System.out.print("*\t");
                }
                else if(i>n/2+1 && i!=n ){  //doubt
                    if(j==n/2+1 || j==1){
                        System.out.print("*\t");
                    }
                    else{
                        System.out.print("\t");
                    }
                }
                else if(i==n){
                    if(j==1 || j>=n/2+1){
                        System.out.print("*\t");
                    }
                    else{
                        System.out.print("\t");
                    }
                }

            }
            System.out.println();
        }
    }
        
    public static void pattern20(int n){
        for(int i=1;i<=n;i++){
            for(int j=1; j<=n;j++){
                if(i==j || i+j == n+1){
                    if(i>1 && i<=n/2){
                        System.out.print("\t");
                    }
                    else{
                        System.out.print("*\t");
                    }
                    
                }
                else{
                    if(j==1 || j==n){
                        System.out.print("*\t");
                    }
                    else{
                        System.out.print("\t");
                    }
                    
                }
            }
            System.out.println();
        }
    }


    public static void pattern21(int n){
        int nrows = n;
        int nspaces = n-2;
        int nstars = 1;
        int irows = 1;
        while(irows<=nrows){
            //print star
           if(irows==n/2+1){
            for(int istar=1;istar<=n;istar++){
                System.out.print("*\t");
            } 
           }
           else{ 
            for(int istar=1;istar<=nstars;istar++){
                System.out.print("*\t");
            }
            //print spaces
            for(int ispace  = 1;ispace<=nspaces;ispace++){
                System.out.print("\t");
            }
            //print star
            for(int istar=1;istar<=nstars;istar++){
                System.out.print("*\t");
            }
        }
            //print next line
            System.out.println();
            //prep for next row
            if(irows<=n/2){
                nspaces-=2;
                nstars+=1;
            }
            else{
                nspaces+=2;
                nstars-=1;
            }
            irows++;
        }
    }

    public static void pattern22(int n){
        int nrows = n;
        int nstars = n;
        int nspaces = 0;
        int irows = 1;
        int val = 1;
        while(irows<=nrows){
            //print stars
            for(int istars = 1; istars<=nstars;istars++){
                System.out.print(val+"\t");
                val++;
            }
            //print spaces
            for(int ispaces = 0; ispaces<=nspaces;ispaces++){
                System.out.print("\t");
            }
            //print stars
            for(int istars = 1; istars<=nstars;istars++){
                System.out.print(val+"\t");
                val--;
            }
            //nextline
            System.out.println();
            //prep for next row
            if(irows<nrows/2){
                nstars++;
                nspaces--;
            }
            else{
                nstars--;
                nspaces++;
            }
            irows++;
        }

    }
        
}
