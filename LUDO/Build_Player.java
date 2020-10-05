package LUDO_BUILD;


import java.awt.Graphics2D;

public class Build_Player {

	Player[] pl=new Player[4]; 
	int[][] initialx= {
			{1,1,3,3},
			{10,10,12,12},
			{10,10,12,12},
			{1,1,3,3}
	};
	int[][] initialy= {
			{1,3,1,3},
			{1,3,1,3},
			{10,12,10,12},
			{10,12,10,12}
	};
	public Build_Player(int height, int width) {
		// TODO Auto-generated constructor stub
		for(int i=0;i<4;i++) {
			pl[i]=new Player(height,width);
		}
	}
	public void draw(Graphics2D g) {
		// TODO Auto-generated method stub
		for(int i=0;i<4;i++) {
			for(int j=0;j<4;j++) {
				pl[i].pa[j].draw(g,initialx[i][j],initialy[i][j],i);
			}
		}
	}
	
}
