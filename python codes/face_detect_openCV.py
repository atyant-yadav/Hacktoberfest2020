import cv2 as cv
import numpy as np


def rescaleFrame(frame,scale=0.15):
    # this will work for all vids,images, live images
    width=int (frame.shape[1]* scale)
    height=int (frame.shape[0]* scale)
    dimensions= (width,height)
    return cv.resize(frame, dimensions,interpolation=cv.INTER_AREA)


img2 = cv.imread('F:\pycodes\opencv\pics\IMG_2571.JPG')

rescale = rescaleFrame(img2)
# cv.imshow('papa',rescale)


img = cv.imread('F:\pycodes\opencv\pics\\s.jpg')
# cv.imshow('anu',img)

gray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
cv.imshow('gray',gray)


haar_cascade = cv.CascadeClassifier('F:\pycodes\opencv\haarcascade_faces.xml')

faces_rect = haar_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=1)

print(f'Number of faces found = {len(faces_rect)}')

for (x,y,w,h) in faces_rect:
    cv.rectangle(rescale, (x,y), (x+w,y+h), (0,255,0), thickness=2)

cv.imshow('Detected Faces', img)



cv.waitKey(0)
