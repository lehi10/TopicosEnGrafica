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


"""
while(1):
    cv2.imshow("Transformacion Afin",dst)
    if cv2.waitKey(20) & 0xFF == 27:
        break
       
"""
       
import matplotlib.pyplot as plt
import numpy as np
import string
import cv2




# 3x3 Identity transformation matrix
I = np.eye(3)

# create the scaling transformation matrix
T_s = np.array([[2, 0, 0], [0, 2, 0], [0, 0, 1]])

# create the rotation transformation matrix
T_r = np.array([[0, 1, 0], [-1, 0, 0], [0, 0, 1]])

# create the rotation transformation matrix
T_k = np.array([[1, 0, 0], [-0, -1, 0], [0, 0, 1]])

#MAtrix espejo
T_m= np.array([[-1, 0, 0], [0, -1, 0], [0, 0, 1]])

T_sk= np.array([[1, 1, 0], [0, 1, 0], [0, 0, 1]])

T_sks= np.array([[0, 1, 0], [1, 1, 0], [0, 0, 1]])
# create combined tranformation matrix
T = T_s @ T_r


#angle 45
Tangle=np.array([[0, 1.5, 0], [-1, 0, 0], [0, 0, 1]])

# Escala
img = plt.imread('lena.png')
#img=plt.imread('letterR.jpg')
#img=plt.imread('dice.png')
#img.shape#(600, 900, 3)

img_transformed = np.empty((510, 510, 3), dtype=np.uint8)
for i, row in enumerate(img):
    for j, col in enumerate(row):
        pixel_data = img[i, j,:]
        input_coords = np.array([i, j,1])
        i_out, j_out, _ = T_s @ input_coords
        img_transformed[i_out, j_out] = pixel_data

plt.figure(figsize=(5, 5))
plt.imshow(img_transformed)
cv2.imwrite('lenaOut.png', img_transformed)

