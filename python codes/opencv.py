#!/usr/local/bin/python3
'''
Change color of the image
'''

import cv2 as cv
import numpy as np

# Load the aerial image and convert to HSV colourspace
image = cv.imread("demo.png")
hsv=cv.cvtColor(image,cv.COLOR_BGR2HSV)

# Define lower and uppper limits of what we call "brown"
brown_lo=np.array([10,0,0])
brown_hi=np.array([20,255,255])

# Mask image to only select browns
mask=cv.inRange(hsv,brown_lo,brown_hi)

# Change image to red where we found brown
image[mask>0]=(0,0,255)

cv.imwrite("result.png",image)