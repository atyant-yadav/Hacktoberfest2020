package objectgame;

import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.util.ArrayList;
import java.util.List;

import util.Resource;

public class Clouds {

	private BufferedImage cloudImage;
	private List<Cloud> clouds;

	public Clouds() {
		cloudImage = Resource.getResourceImage("data/cloud.png");
		clouds = new ArrayList<Cloud>();

		Cloud cloud1 = new Cloud();
		cloud1.posX = 100;
		cloud1.posY = 10;
		clouds.add(cloud1);

		cloud1 = new Cloud();
		cloud1.posX = 200;
		cloud1.posY = 20;
		clouds.add(cloud1);

		cloud1 = new Cloud();
		cloud1.posX = 450;
		cloud1.posY = 45;
		clouds.add(cloud1);

		cloud1 = new Cloud();
		cloud1.posX = 600;
		cloud1.posY = 60;
		clouds.add(cloud1);

		cloud1 = new Cloud();
		cloud1.posX = 700;
		cloud1.posY = 70;
		clouds.add(cloud1);

		cloud1 = new Cloud();
		cloud1.posX = 950;
		cloud1.posY = 95;
		clouds.add(cloud1);

		cloud1 = new Cloud();
		cloud1.posX = 1000;
		cloud1.posY = 100;
		clouds.add(cloud1);

	}

	public void update() {
		for (Cloud cloud : clouds) {
			cloud.posX = cloud.posX - 2;
		}
		Cloud firstCloud = clouds.get(0);
		if (firstCloud.posX + cloudImage.getWidth() < 0) {
			firstCloud.posX = 1200;
			clouds.remove(firstCloud);
			clouds.add(firstCloud);
		}

	}

	public void draw(Graphics g) {
		for (Cloud cloud : clouds)
			g.drawImage(cloudImage, (int) cloud.posX, (int) cloud.posY, null);
	}

	private class Cloud {
		float posX, posY;

	}
}
