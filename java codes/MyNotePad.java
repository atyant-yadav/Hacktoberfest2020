import java.io.*;
import java.util.*;

public class MyNotePad {

	public static void main(String[] args) {

		Scanner sc1 = new Scanner(System.in);
		ArrayList<MyNotePad> files = new ArrayList<MyNotePad>(10000000);

		int h = 1;
		while (h == 1) {
			System.out.println("\nEnter : \n1.CREATE NEW FILE\n2.To OPEN AND EDIT FILE\n3.EXIT");
			int op1 = sc1.nextInt();
			if (op1 == 1) {
				Scanner sc2 = new Scanner(System.in);
				System.out.println("\nEnter the Name for the new File : ");
				String name = sc2.nextLine();
				files.add(new MyNotePad(name));
				System.out.println("\nYour File Has Been Created\nEnter the INITIAL CONTENT of the file : ");
				files.get(files.size() - 1).content = sc2.nextLine();
				files.get(files.size() - 1).cursor = files.get(files.size() - 1).content.length();

			}

			else if (op1 == 2) {
				Scanner sc3 = new Scanner(System.in);
				System.out.println("\nEnter the Name of the file to open : ");
				String name = sc3.nextLine();
				int fileIndex = 0, flag = 0;

				if (files.size() == 0) {
					System.out.println("\nFirst Create a File ");
					// continue;
				}
				for (int i = 0; i < files.size(); i++) {
					if (files.get(i).fileName.equals(name)) {
						fileIndex = i;
						flag = 1;
						break;
					}
				}
				if (flag == 0) {
					System.out.println("\nFile with given name Does not exist!!\n");
					continue;
				}

				files.get(fileIndex).myContentStack1.clear();
				files.get(fileIndex).myContentStack2.clear();
				files.get(fileIndex).myCursorStack1.clear();
				files.get(fileIndex).myCursorStack2.clear();
				files.get(fileIndex).clipBoard = "";
				files.get(fileIndex).cursor = files.get(fileIndex).content.length();
				loop: while (h == 1) {
					System.out.println(
							"\nEnter : \n1.EXIT \n2.PRINT\n3.PRINT_CURSER\n4.INSERT\n5.SEEK\n6.DELETE\n7.COPY\n8.Print ClipBoard\n9.CUT\n10.PASTE\n11.UNDO\n12.REDO");
					int op2 = sc3.nextInt();
					switch (op2) {

					case 1:
						System.out.println("\nMission Accomplished!");
						break loop;

					case 2:
						files.get(fileIndex).print();
						break;

					case 3:
						files.get(fileIndex).printCursor();
						break;

					case 4:
						files.get(fileIndex).myContentStack1.push(files.get(fileIndex).content);
						files.get(fileIndex).myCursorStack1.push(files.get(fileIndex).cursor);
						Scanner sc4 = new Scanner(System.in);
						System.out.println("\nEnter an Character to Insert");
						char X = sc4.next().charAt(0);
						files.get(fileIndex).insert(Character.toString(X));
						files.get(fileIndex).cursor += 1;
						files.get(fileIndex).print();
						files.get(fileIndex).printCursor();
						files.get(fileIndex).printClipboard();
						break;

					case 5:
						files.get(fileIndex).myContentStack1.push(files.get(fileIndex).content);
						files.get(fileIndex).myCursorStack1.push(files.get(fileIndex).cursor);
						Scanner sc5 = new Scanner(System.in);
						System.out.println("\nEnter cursor value : ");
						int x = sc5.nextInt();
						if (x >= 0 && x <= files.get(fileIndex).content.length())
							files.get(fileIndex).cursor = x;
						else if (x == -1)
							files.get(fileIndex).cursor = files.get(fileIndex).content.length();
						files.get(fileIndex).print();
						files.get(fileIndex).printCursor();
						files.get(fileIndex).printClipboard();
						break;

					case 6:
						files.get(fileIndex).myContentStack1.push(files.get(fileIndex).content);
						files.get(fileIndex).myCursorStack1.push(files.get(fileIndex).cursor);
						Scanner sc6 = new Scanner(System.in);
						System.out.println("\nEnter 1 to delete Character at Cursur and -1 to delete Character at Cursur-1:  ");
						int y = sc6.nextInt();
						if (y == 1)
							files.get(fileIndex).delete(y);
						else if (y == -1) {
							files.get(fileIndex).delete(files.get(fileIndex).cursor - 1);
							files.get(fileIndex).cursor -= 1;
						}
						else
							System.out.println("\nEnter Valid Input!!");
						files.get(fileIndex).print();
						files.get(fileIndex).printCursor();
						files.get(fileIndex).printClipboard();
						break;

					case 7:
						files.get(fileIndex).myContentStack1.push(files.get(fileIndex).content);
						files.get(fileIndex).myCursorStack1.push(files.get(fileIndex).cursor);
						Scanner sc7 = new Scanner(System.in);
						System.out.println("\nEnter two Index to Copy : ");
						int x1 = sc7.nextInt();
						int y1 = sc7.nextInt();
						if (x1 >= 0 && x1 <= files.get(fileIndex).content.length() && y1 >= 0
								&& y1 <= files.get(fileIndex).content.length())
							files.get(fileIndex).copy(x1, y1);
						files.get(fileIndex).print();
						files.get(fileIndex).printCursor();
						files.get(fileIndex).printClipboard();
						break;

					case 8:
						files.get(fileIndex).printClipboard();
						break;

					case 9:
						files.get(fileIndex).myContentStack1.push(files.get(fileIndex).content);
						files.get(fileIndex).myCursorStack1.push(files.get(fileIndex).cursor);
						Scanner sc8 = new Scanner(System.in);
						System.out.println("\nEnter two Index to Cut : ");
						int x2 = sc8.nextInt();
						int y2 = sc8.nextInt();
						if (x2 >= 0 && x2 <= files.get(fileIndex).content.length() && y2 >= 0
								&& y2 <= files.get(fileIndex).content.length())
							files.get(fileIndex).cut(x2, y2);
						files.get(fileIndex).cursor = files.get(fileIndex).content.length();
						files.get(fileIndex).print();
						files.get(fileIndex).printCursor();
						files.get(fileIndex).printClipboard();
						break;

					case 10:
						files.get(fileIndex).myContentStack1.push(files.get(fileIndex).content);
						files.get(fileIndex).myCursorStack1.push(files.get(fileIndex).cursor);
						Scanner sc9 = new Scanner(System.in);
						System.out.println("\nEnter an Index to Paste : ");
						int z = sc9.nextInt();
						if (z >= 0 && z <= files.get(fileIndex).content.length())
							files.get(fileIndex).paste(z);
						files.get(fileIndex).cursor = files.get(fileIndex).cursor
								+ files.get(fileIndex).clipBoard.length();
						files.get(fileIndex).print();
						files.get(fileIndex).printCursor();
						files.get(fileIndex).printClipboard();
						break;

					case 11:
						files.get(fileIndex).myContentStack2.push(files.get(fileIndex).content);
						files.get(fileIndex).myCursorStack2.push(files.get(fileIndex).cursor);
						if (!files.get(fileIndex).myContentStack1.isEmpty()
								&& !files.get(fileIndex).myCursorStack1.isEmpty()) {
							files.get(fileIndex).content = files.get(fileIndex).myContentStack1.pop();
							files.get(fileIndex).cursor = files.get(fileIndex).myCursorStack1.pop();
						}
						files.get(fileIndex).print();
						files.get(fileIndex).printCursor();
						files.get(fileIndex).printClipboard();
						break;

					case 12:
						if (!files.get(fileIndex).myContentStack2.isEmpty()
								&& !files.get(fileIndex).myCursorStack2.isEmpty()) {
							files.get(fileIndex).myContentStack1.push(files.get(fileIndex).content);
							files.get(fileIndex).myCursorStack1.push(files.get(fileIndex).cursor);
							files.get(fileIndex).content = files.get(fileIndex).myContentStack2.pop();
							files.get(fileIndex).cursor = files.get(fileIndex).myCursorStack2.pop();
						}
						files.get(fileIndex).print();
						files.get(fileIndex).printCursor();
						files.get(fileIndex).printClipboard();
						break;

					}
				}
			}

			else if (op1 == 3)
			{
				System.out.println("\nProgram Terminated!!");
				break;
			}

		}

	}
}

class MyNotePad {
	public String content = "", fileName = "", clipBoard = "";

	public int cursor = -1;
	public Stack<String> myContentStack1 = new Stack<String>();// for Undo
	public Stack<Integer> myCursorStack1 = new Stack<Integer>();// for Undo
	public Stack<String> myContentStack2 = new Stack<String>();// for Redo
	public Stack<Integer> myCursorStack2 = new Stack<Integer>();// for Redo

	MyNotePad(String name) {
		this.fileName = name;
	}

	public void print() {
		System.out.println("\nContent : "+this.content+"\n");

	}

	public void printCursor() {
		System.out.println("\nCursor : " + this.cursor+"\n");

	}

	public void insert(String x) {
		this.content = this.content.substring(0, this.cursor ) + x + this.content.substring(this.cursor);
	}

	

	public void delete(int x) {
		this.content = this.content.substring(0, x) + this.content.substring(x + 1);
	}

	public void copy(int x, int y) {
		this.clipBoard=this.content.substring(x,y+1);
	}

	public void printClipboard() {
		System.out.println("\nClip Board : "+this.clipBoard+"\n");
	}

	public void cut(int x, int y) {
		this.clipBoard=this.content.substring(x,y+1);
		this.content = this.content.substring(0, x) + this.content.substring(y + 1);

	}

	public void paste(int x) {
		this.content = this.content.substring(0, x ) + this.clipBoard + this.content.substring(x);
	}

	

	

}
