package objectgame;

import java.applet.AudioClip;
import java.awt.Graphics;
import java.awt.Rectangle;


import util.Animation;
import util.Resource;

public class MainCharacter {

	private float x = 0;
	private float y = 0;
	private float speedY = 0;
	public static final float GRAVITY = 0.5f;
	public static final float GROUNDY = 210;
	private Animation characterRun;
	private Rectangle rect;
	private boolean isAlive = true;

	private AudioClip scoreUpSound;

	public MainCharacter() {
		characterRun = new Animation(100);
		characterRun.addFrame(Resource.getResourceImage("data/main-character1.png"));
		characterRun.addFrame(Resource.getResourceImage("data/main-character2.png"));
		rect = new Rectangle();
	}

	public void update() {
		// line code for jumping
		characterRun.update();
		if (y > GROUNDY - characterRun.getFrame().getHeight()) {
			speedY = 0;
			y = GROUNDY - characterRun.getFrame().getHeight();
		} else {
			speedY += GRAVITY;
			y += speedY;
		}
		rect.x = (int) x;
		rect.y = (int) y;
		rect.width = characterRun.getFrame().getWidth() - 10;
		rect.height = characterRun.getFrame().getHeight() - 10;
	}

	public Rectangle getBound() {
		return rect;
	}

	public void draw(Graphics g) {
		// g.setColor(Color.white);
		// g.drawRect((int)x,(int) y,
		// characterRun.getFrame().getWidth(),characterRun.getFrame().getHeight());
		g.drawImage(characterRun.getFrame(), (int) x, (int) y, null);
	}

	public void jump() {
		speedY = -10;
		y += speedY;
	}

	public float getX() {
		return x;
	}

	public void setX(float x) {
		this.x = x;
	}

	public float getY() {
		return y;
	}

	public void setY(float y) {
		this.y = y;
	}

	public float getSpeedY() {
		return speedY;
	}

	public void setSpeedY(float speedY) {
		this.speedY = speedY;
	}

	public void setAlive(boolean alive) {
		isAlive = alive;
	}

	public boolean getAlive() {
		return isAlive;
	}

}
