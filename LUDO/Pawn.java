package LUDO_BUILD;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics2D;

public class Pawn {
	int x,y;
	int current;
	int height,width;
	public Pawn(int h,int w){
		current=-1;
		x=-1;
		y=-1;
		height=h;
		width=w;
	}
	public void draw(Graphics2D g, int i, int j,int play) {
		// TODO Auto-generated method stub
		if(current==-1) {
			int temp1=80+(height/2),temp2=50+(width/2);
			x=i;
			y=j;
			if(play==0) {
				g.setColor(Color.RED);
			}
			else if(play==1) {
				g.setColor(Color.GREEN);
			}
			else if(play==2) {
				g.setColor(Color.YELLOW);
			}
			else if(play==3) {
				g.setColor(Color.BLUE);
			}
			g.fillOval(temp1+5+(i*width),temp2+5+(j*height),width-10,height-10);
			g.setStroke(new BasicStroke(2));
			g.setColor(Color.BLACK);
	    	g.drawOval(temp1+5+(i*width),temp2+5+(j*height),width-10,height-10);
		}
		else
		{
			int temp1=80,temp2=50;
			x=Path.ax[play][current];
			y=Path.ay[play][current];
			if(play==0) {
				g.setColor(Color.RED);
			}
			else if(play==1) {
				g.setColor(Color.GREEN);
			}
			else if(play==2) {
				g.setColor(Color.YELLOW);
			}
			else if(play==3) {
				g.setColor(Color.BLUE);
			}
			g.fillOval(temp1+5+(x*width),temp2+5+(y*height),width-10,height-10);
			g.setStroke(new BasicStroke(2));
			g.setColor(Color.BLACK);
	    	g.drawOval(temp1+5+(x*width),temp2+5+(y*height),width-10,height-10);
		}
	}
}
