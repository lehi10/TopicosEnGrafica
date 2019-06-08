import cv2
import numpy as np

start = False

def on_trackbar(value):
    pass

def on_mouse(event, x, y, flags, param):

    global start
    pt = (x, y)

    if event == cv2.EVENT_LBUTTONDOWN:
        start = True
        
    elif event == cv2.EVENT_LBUTTONUP:
        start = False
        
    elif start and event == cv2.EVENT_MOUSEMOVE:
        ventana = 'Drawing'
        grosor = cv2.getTrackbarPos('Grosor', ventana)
        
        cv2.circle(param, pt, 3, (255, 0, 255), -1)


if __name__ == "__main__":

    title = 'Drawing'
    image = np.zeros((600, 800, 3), np.uint8)
    
    cv2.namedWindow(title)

    cv2.setMouseCallback(title, on_mouse, image)

    while(1):
        cv2.imshow(title, image)
        if cv2.waitKey(20) & 0xFF == 27:
            break
        
    cv2.destroyAllWindows()
