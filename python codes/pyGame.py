import pygame, sys, os
from pygame.locals import*

red = [255, 0, 0]

# Initialize Pygame
pygame.init()

#Setup up window
DISPLAYSURF = pygame.display.set_mode((1000, 600))
pygame.display.set_caption('Slither.eat - The Snake Game')

#Setup drawing surface
screen = pygame.display.get_surface()
screen.fill(red)
pygame.display.set_caption("Snake")
pygame.display.flip()

while False:
	for event in pygame.event.get():
		print(event)
		if event.type == QUIT:
			pygame.quit()
			sys.exit()
	pygame.display.update()		
	
