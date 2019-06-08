import numpy as np
import matplotlib.pyplot as plt
import cv2

img = cv2.imread('lena.png')

rows,cols,ch = img.shape


#Tres puntos para la transformacion afin de la imagen original
pointsOriginalImg = [[100,400],[400,100],[100,100]]
#Tres puntos para la transformacion afin de la imagen resultante
pointsResultImg = [[50,300],[400,200],[80,150]]

pts1 = np.float32(pointsOriginalImg)
pts2 = np.float32(pointsResultImg)

M = cv2.getAffineTransform(pts1,pts2)

dst = cv2.warpAffine(img,M,(cols,rows))

print img.shape
print pointsOriginalImg
print pointsResultImg

while(1):
    cv2.imshow("Transformacion Afin",dst)
    if cv2.waitKey(20) & 0xFF == 27:
        break
