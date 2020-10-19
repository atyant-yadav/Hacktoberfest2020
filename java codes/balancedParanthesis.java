import java.util.*;
public class balancedParanthesis {
    public static void main(String ar[])
    {
        Scanner sc=new Scanner(System.in);
        Stack<Character> stack=new Stack<>();

        String s= sc.nextLine();
        boolean balanced=true;
        for(int i=0;i<s.length();i++)
        {
            char ch=s.charAt(i);
            if(ch=='(' || ch=='{' || ch=='[')
            {
                stack.push(ch);
                continue;
            }
            if(stack.isEmpty())
            {
                balanced=false;
                break;
            }
            if(ch==')')
            {
                if(stack.peek()=='(')
                {
                    stack.pop();
                }
                else
                {
                    balanced=false;
                    break;
                }

            }
            if(ch==']')
            {
                if(stack.peek()=='[')
                {
                    stack.pop();
                }
                else
                {
                    balanced=false;
                    break;
                }

            }
            if(ch=='}')
            {
                if(stack.peek()=='{')
                {
                    stack.pop();
                }
                else
                {
                    balanced=false;
                    break;
                }

            }


        }
        if(!stack.isEmpty())
       {
           balanced=false;
       }
       if(balanced==false)
        {
            System.out.println("not balance P");
        }
        else
        {
            System.out.println("balanced P");
        }

    }

}
