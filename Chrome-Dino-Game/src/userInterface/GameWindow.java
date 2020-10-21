package userInterface;

import javax.swing.JFrame;

public class GameWindow extends JFrame {

	private GameScreen gameScreen;
	
	public GameWindow() {
		super("Java T-Rex Game");
		setSize(800,300);
		setLocation(400, 400);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		gameScreen = new GameScreen();
		add(gameScreen);
		addKeyListener(gameScreen);
	}
	
	public void startGame() {
		gameScreen.startGame();
	}
	
	public static void main(String args[]) {
		GameWindow gw = new GameWindow();
		gw.setVisible(true);
		gw.startGame();
	} 
}
