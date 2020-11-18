package objectgame;

import java.awt.Graphics;
import java.awt.Rectangle;
import java.awt.image.BufferedImage;


import util.Resource;

public class Cactus extends Enemy {

	private BufferedImage image;
	private int posX, posY;
	private Rectangle rect;
	private MainCharacter mainCharacter;
	private boolean isScoreGot = false;

	public Cactus(MainCharacter mainCharacter) {
		this.mainCharacter = mainCharacter;
		image = Resource.getResourceImage("data/cactus1.png");
		posX = 300;
		posY = 170;
		rect = new Rectangle();

	}

	public void update() {
		posX -= 5;
		rect.x = posX;
		rect.y = posY;
		rect.width = image.getWidth();
		rect.height = image.getHeight();
	}

	public Rectangle getBound() {
		return rect;
	}

	public void draw(Graphics g) {
		g.drawImage(image, posX, posY, null);
	}

	public void setX(int x) {
		posX = x;
	}

	public void setY(int y) {
		posX = y;
	}

	public void setImage(BufferedImage image) {
		this.image = image;
	}

	public boolean isOutOfScreen() {
		return (posX + image.getWidth() < 0);
	}

	public boolean isOver() {
		return (mainCharacter.getX() > posX);
	}

	public boolean isScoreGot() {
		return isScoreGot;
	}

	public void setIsScoreGot(boolean isScoreGot) {
		this.isScoreGot = isScoreGot;
	}
}
