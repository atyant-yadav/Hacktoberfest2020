package userInterface;

import java.applet.Applet;
import java.applet.AudioClip;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.image.BufferedImage;
import java.net.MalformedURLException;
import java.net.URL;

import javax.swing.JPanel;

import objectgame.Cactus;
import objectgame.Clouds;
import objectgame.EnemyManager;
import objectgame.Land;
import objectgame.MainCharacter;
import util.Resource;

public class GameScreen extends JPanel implements Runnable, KeyListener {

	public static final int GAME_FIRST_STATE = 0;
	public static final int GAME_PLAY_STATE = 1;
	public static final int GAME_OVER_STATE = 2;
	public static final float GRAVITY = 0.5f;
	public static final float GROUNDY = 210;

	private MainCharacter mainCharacter;
	private Thread thread;
	private Clouds cloud;
	// private Cactus cactus;
	private Land land;
	private EnemyManager enemiesManager;

	private int gameState = GAME_FIRST_STATE;

	private BufferedImage imageGameOverText;
	private BufferedImage replayButton;
	private int score;

	private AudioClip scoreUpSound;
	private AudioClip jump;
	private AudioClip dead;

	public GameScreen() {
		thread = new Thread(this);
		mainCharacter = new MainCharacter();
		mainCharacter.setX(50);
		mainCharacter.setY(150);
		land = new Land();
		cloud = new Clouds();
		// cactus = new Cactus();
		enemiesManager = new EnemyManager(mainCharacter, this);
		imageGameOverText = Resource.getResourceImage("data/gameover_text.png");
		replayButton = Resource.getResourceImage("data/replay_button.png");
		try {
			scoreUpSound = Applet.newAudioClip(new URL("file", "", "data/scoreup.wav"));
			jump = Applet.newAudioClip(new URL("file","","data/jump.wav"));
			dead = Applet.newAudioClip(new URL("file","","data/dead.wav"));
		} catch (MalformedURLException e) {
			e.printStackTrace();
		}

	}

	public void startGame() {
		thread.start();
	}

	public void run() {
		while (true) {
			try {
				update();
				// cactus.update();
				// if(cactus.getBound().intersects(mainCharacter.getBound())) {
				// System.out.println("Collision");
				// }
				repaint();
				Thread.sleep(20);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}

	public void update() {
		switch (gameState) {
		case GAME_PLAY_STATE:
			mainCharacter.update();
			land.update();
			cloud.update();
			enemiesManager.update();
			if (mainCharacter.getAlive() == false) {
				gameState = GAME_OVER_STATE;
				dead.play();
			}
			break;
		}

	}

	public void plusScore(int score) {
		this.score += score;
		if (this.score % 100 == 0) {
			scoreUpSound.play();
		}

	}

	public void paint(Graphics g) {
		g.setColor(Color.decode("#f7f7f7"));
		g.fillRect(0, 0, getWidth(), getHeight());
		g.setColor(Color.black);
		// g.drawLine(0, (int)GROUNDY, getWidth(),(int)GROUNDY);

		switch (gameState) {
		case GAME_FIRST_STATE:
			mainCharacter.draw(g);
			break;
		case GAME_PLAY_STATE:
			land.draw(g);
			cloud.draw(g);
			enemiesManager.draw(g);
			mainCharacter.draw(g);
			g.drawString("SCORE  " + String.valueOf(score), 600, 20);
			break;
		case GAME_OVER_STATE:
			land.draw(g);
			cloud.draw(g);
			enemiesManager.draw(g);
			mainCharacter.draw(g);
			g.drawImage(imageGameOverText, 300, 100, null);
			g.drawImage(replayButton, 375, 130, null);
			break;
		}

	}

	private void resetGame() {
		mainCharacter.setAlive(true);
		mainCharacter.setX(50);
		mainCharacter.setY(150);
		enemiesManager.reset();

	}

	public void keyTyped(KeyEvent e) {
	}

	public void keyPressed(KeyEvent e) {

	}

	public void keyReleased(KeyEvent e) {
		switch (e.getKeyCode()) {
		case KeyEvent.VK_SPACE:
			if (gameState == GAME_FIRST_STATE) {
				gameState = GAME_PLAY_STATE;
			} else {
				if (gameState == GAME_PLAY_STATE) {
					mainCharacter.jump();
					jump.play();

				} else {
					if (gameState == GAME_OVER_STATE) {
						resetGame();
						score = 0;
						gameState = GAME_PLAY_STATE;

					}
				}
			}
			break;
		}

	}

}
