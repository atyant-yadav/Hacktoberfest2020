
import java.util.*;

class node
{
	node left;
	node right;
	String name;
	long phone;
	int height;
	int h;
	
	public node()
	{
		left=right=null;
		height=1;
		
	}
	
	public node(String n, long no)
	{
		left=right=null;
		name=n;
		phone=no;	
	}
}

class avl{
	
	node root;
	node ptr;
	node temp;
	
	Scanner sc=new Scanner(System.in);
	avl()
	{
		root=null;
	}
	
	int height(node localroot)
	{
		if(localroot==null)
		{
			return 0;
		}
		else
		{
			int lh=height(localroot.left);
			int rh=height(localroot.right);
			if(lh>rh)
			{
				return lh+1;
				
			}
			else
			{
				return rh+1;
			}
		}
	}
	
	
	
		node ll(node root)
		{
			ptr=root;
			temp=ptr.left;
			ptr.left=temp.right;
			temp.right=ptr;
			temp.h=height(temp);
			ptr.h=height(temp);
			System.out.println(" >>LL");
			return (temp);
		}
		
		node rr(node root)
		{
			ptr=root;
			temp=ptr.right;
			ptr.right=temp.left;
			temp.left=ptr;
			temp.h=height(temp);
			ptr.h=height(temp);
			System.out.println(" >>RR");
			return temp;
		}
		
		node lr(node root) 
		{
			ptr=root;
			ptr.left=rr(ptr.left); //rr on child
			root=ll(root); //ll on parent 
			System.out.println(ll(root));
			System.out.println(" >>LR");
			return root;
		}
		
		node rl(node root)
		{
			ptr=root;
			ptr.right=ll(ptr.right);
			root=rr(root);
			System.out.println(rr(root));
			System.out.println(" >>Rl");
			return root;
		}
		
		//Get balance factor of node N
		int Bf(node root)
		{
			if(root==null)
			{
				return 0;
			}
			else
			{
				return height(root.left) -height(root.right);
			}
		}
		
		void accept()
		{
			int ch=1;
			String name;
			long no;
			do {
				System.out.println("NAME::");
				name=sc.next();
				System.out.println("Contact::");
				no=sc.nextLong();
				
				root=insert(root,name,no);
				System.out.println("ADD MORE CONTACTS?");
				ch=sc=nextInt();
			}while(ch==0);
		}
		
		node insert(node localroot, String name, long no)
		{
			node temp;
			if(localroot == null)
			{
				temp=new node(name,no);
			   return temp;
			}
			
			else 
			{
				if(localroot.name.compareToIgnorecase(name) <0)
				{
					localroot.right=insert(localroot.right,name,no);
				}
				else if(localroot.name.compareToIgnoreCase(name)>0)
				{
					localroot.left=insert(localroot.left,name,no);
				}
							
			}
			
			if(Bf(localroot)>1)
			{
				if(n.compareToIgnore(localroot.left.name)<0)
				{
					return ll(localroot);
				}
				else
				{
					return lr(localroot);
				}
			}
			else if(Bf(localroot)<-1)
			{
				if(n.compareToignoreCase(localroot.right.name)>0)
				{
					return rr(localroot);
				}
				else
				{
					return rl(localroot);
				}
			}
			return localroot;
		}
		
		void display(node localroot)
		{
			if(localroot!=null)
			{
				display(localroot.left);
				System.out.println(localroot.name + " - " + localroot.phone);
				display(localroot.right);
			}
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	}
