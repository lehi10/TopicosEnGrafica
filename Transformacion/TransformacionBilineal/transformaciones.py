import numpy as np
import cv2
from matplotlib import pyplot as plt
from numpy import linalg

start = False


img = cv2.imread("lena.png")

if img.size == 0:
    sys.exit("Error: the image has not been correctly loaded.")

height, width, channels = img.shape


RGB=[0,0,0]
type(RGB)
img2=img.copy()
for i in range(height):
    for j in range(width):
        img2[i,j]=RGB


X=[(width//2)*0,(width//2)*1,(width//2)*2]
Y=[(height//2)*0,(height//2)*1,(height//2)*2]



def TransformacionBilineal(A,Bx,By,ImgO,ImgR,height1,width1,height2,width2):
    Solutions2=np.linalg.solve(A,By)
    Solutions1=np.linalg.solve(A,Bx)#cramer(A,B)
    for i in range(height1,height2):
        for j in range(width1,width2):
            vector=[j,i,i*j,1]
            vector=np.array(vector)
            vector=vector.astype(np.float)
            Solutions1=np.array(Solutions1)
            x=int(round(sum(vector*Solutions1)))
            Solutions2=np.array(Solutions2)
            y=int(round(sum(vector*Solutions2)))
            ImgR[y,x]=ImgO[i,j]
    return
    

def setPoints(XR,YR):
	
	Xr=[[(width//2)*0,(width//2)*1,XR,(width//2)*0],
		[(width//2)*1,(width//2)*2,(width//2)*2,XR],
		[(width//2)*0,XR,(width//2)*1,(width//2)*0],
		[XR,(width//2)*2,(width//2)*2,(width//2)*1]]
	Yr=[[(height//2)*0,(height//2)*0,YR,(height//2)*1],
		[(height//2)*0,(height//2)*0,(height//2)*1,YR],
		[(height//2)*1,YR,(height//2)*2,(height//2)*2],
		[YR,(height//2)*1,(height//2)*2,(height//2)*2]]


	for i in range(2):
		for j in range(2):
		    A=[
		    [X[j],Y[i],Y[i]*X[j],1],
		    [X[j+1],Y[i],Y[i]*X[j+1],1],
		    [X[j+1],Y[i+1],Y[i+1]*X[j+1],1],
		    [X[j],Y[i+1],Y[i+1]*X[j],1],
		    ]

		    Bx=[Xr[j+(i*2)][0],Xr[j+(i*2)][1],Xr[j+(i*2)][2],Xr[j+(i*2)][3]]
		    By=[Yr[j+(i*2)][0],Yr[j+(i*2)][1],Yr[j+(i*2)][2],Yr[j+(i*2)][3]]

		    A=np.array(A)
		    Bx=np.array(Bx)
		    By=np.array(By)
		    TransformacionBilineal(A,Bx,By,img,img2,Y[i],X[j],Y[i+1],X[j+1])




def on_trackbar(value):
    pass




def on_mouse(event, x, y, flags, param):

    global start
    pt = (x, y)
    print x , y

    if event == cv2.EVENT_LBUTTONDOWN:
        start = True
        
    elif event == cv2.EVENT_LBUTTONUP:
        start = False
        
    elif start and event == cv2.EVENT_MOUSEMOVE:
        
        setPoints(x,y)
        #cv2.circle(param, pt, 3, (255, 0, 255), -1)


	

	







title = 'Transformacion'
#image = np.zeros((width,height, 3), np.uint8)

cv2.namedWindow(title)

cv2.setMouseCallback(title, on_mouse, img)


while(1):
    cv2.imshow(title, img2)
    if cv2.waitKey(20) & 0xFF == 27:
        break
    
cv2.destroyAllWindows()
if cv2.waitKey(20):
    

