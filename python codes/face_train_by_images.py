import os
import cv2 as cv
import numpy as np

people = ['Ben Afflek', 'Elton John', 'Jerry Seinfield', 'Madonna', 'Mindy Kaling']


DIR= r'F:\\pycodes\\opencv\\Resources\\Faces\\train'

haar_cascade = cv.CascadeClassifier('F:\pycodes\opencv\haarcascade_faces.xml')

feature=[]
labels=[]

def create_train():
    for person in people:
        path = os.path.join(DIR, person)
        label = people.index(person)

        for img in os.listdir(path):
            img_path = os.path.join(path, img)

            img_array = cv.imread(img_path)
            gray = cv.cvtColor(img_array, cv.COLOR_BGR2GRAY)
            
            face_rect = haar_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=4)

            for (x,y,w,h) in face_rect:
                face_roi = gray[y:y+h, x:x+w]
                feature.append(face_roi)
                labels.append(label)


create_train()
print('Training Done -------------------')

feature= np.array(feature, dtype= 'object')
labels = np.array(labels)

face_recognizer = cv.face.LBPHFaceRecognizer_create()

# training the recogniser

face_recognizer.train(feature,labels)

# face_recognizer.save('face_train.yml')
# np.save('features.npy', feature)
# np.save('labels.npy', labels)

