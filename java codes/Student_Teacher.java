import java.util.*;

class Person
{
    String name, des;
    int ID, ph_no;
    Person(){}
    public String toString()
    {
        return null;
    }
}

class Students extends Person
{
    String name, des;
    int ID, ph_no;
    
    Students(String name, String des, int ID, int ph_no)
    {
        this.name = name;
        this.des = des;
        this.ID =ID;
        this.ph_no = ph_no;
    }

    public String toString()
    {
        return ("Name : " + name + "\nDesignation : " + des + "\nID : " + ID + "\nPhone Number : " + ph_no);
    }
}

class Teachers extends Person
{
    String name, des;
    int ID, ph_no;
    
    Teachers(String name, String des, int ID, int ph_no)
    {
        this.name = name;
        this.des = des;
        this.ID =ID;
        this.ph_no = ph_no;
    }

    public String toString()
    {
        return ("Name : " + name + "\nDesignation : " + des + "\nID : " + ID + "\nPhone Number : " + ph_no);
    }
}

class Student_Teacher extends Person
{
    public static void main(String args[])
    {
        String name, des;
        int ID, ph_no;

        Scanner sc = new Scanner(System.in);

        Person p;

        System.out.println("\nEnter number of Students : ");
        int ns = sc.nextInt();

        Person ps[] = new Person[ns];

        for(int i = 0; i<ns; i++)
        {
            System.out.print("\nFor Student " + (i+1));
            System.out.println("\nEnter Name : ");
            name = sc.next() + sc.nextLine();
            System.out.println("Enter Designation : ");
            des = sc.next() + sc.nextLine();
            System.out.println("Enter ID : ");
            ID = sc.nextInt();
            System.out.println("Enter Phone Number : ");
            ph_no = sc.nextInt();

            ps[i] = new Students(name, des, ID, ph_no);
        }

        for(int i = 0; i<ns; i++)
        {
            System.out.println("\nStudent " + (i+1) + " :");
            System.out.println(ps[i].toString());
        }

        System.out.println("\nEnter number of Teachers : ");
        int nt = sc.nextInt();

        Teachers t[] = new Teachers[nt];

        for(int i = 0; i<nt; i++)
        {
            System.out.print("\nFor Teacher " + (i+1));
            System.out.println("\nEnter Name : ");
            name = sc.next() + sc.nextLine();
            System.out.println("Enter Designation : ");
            des = sc.next() + sc.nextLine();
            System.out.println("Enter ID : ");
            ID = sc.nextInt();
            System.out.println("Enter Phone Number : ");
            ph_no = sc.nextInt();

            t[i] = new Teachers(name, des, ID, ph_no);
        }

        for(int i = 0; i<nt; i++)
        {
            System.out.println("\nTeacher " + (i+1) + " :");
            System.out.println(t[i].toString());
        }
    }
}