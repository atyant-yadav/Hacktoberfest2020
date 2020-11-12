import java.uti;.*;

pulbic class SelectionSort {
    public static void main(String args[]) {
        Scanner in = new Scanner (System.in);
        int i,j,t,min;
        int m[] = new int[10];
        System.out.println("enter 10 elements of the array");
        for(i=0;i<10;i++)
            m[i] = in.nextint();
        for(i=0;i<9;i++)
        {
            min = i;
            for(j=i+1;j<10;j++)
            {
                if(m[j]<m[min])
                    min = j;
            }
            t = m[i];
            m[i] = m[min];
            m[min] = t;
        }
        System.out.println("The sorted array is")
        for(i=0;i<10;i++)
            System.out.println(m[i]);
    }
}