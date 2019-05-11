# Convolucion con Python y C++

Lehi Quincho M.
CUI: 20122586

## Como compilarlo

El código de la convolución fue compilado usando Colab de Google, que tiene GPUs disponibles para usar con Python.
Agregando algunas librerías se puede usar para programar en C++ aprovechando el GPU. 


Las siguientes lineas contienen las librerías y dependencias que necesitan instalarse en Colab para usar el GPU, y programar en C++ con el comando nvcc , y aprovechar esas funciones con python

Desinstalando librerias anteriores de Cuda

'''
!apt-get --purge remove cuda nvidia* libnvidia-*
!dpkg -l | grep cuda- | awk '{print $2}' | xargs -n1 dpkg --purge
!apt-get remove cuda-*
!apt autoremove
!apt-get update

'''

Instalando reposutorio de librerias de Cuda para C++

'''
!wget https://developer.nvidia.com/compute/cuda/9.2/Prod/local_installers/cuda-repo-ubuntu1604-9-2-local_9.2.88-1_amd64 -O cuda-repo-ubuntu1604-9-2-local_9.2.88-1_amd64.deb
!dpkg -i cuda-repo-ubuntu1604-9-2-local_9.2.88-1_amd64.deb
!apt-key add /var/cuda-repo-9-2-local/7fa2af80.pub
!apt-get update
!apt-get install cuda-9.2

'''

Revisando la version de Cuda que tenemos

'''
!nvcc --version 


Salida :

nvcc: NVIDIA (R) Cuda compiler driver
Copyright (c) 2005-2018 NVIDIA Corporation
Built on Sat_Aug_25_21:08:01_CDT_2018
Cuda compilation tools, release 10.0, V10.0.130
'''

Instanlando librerias para poder aplicar todos los cambios y usar nvcc

'''
!pip install git+git://github.com/andreinechaev/nvcc4jupyter.git
'''


##Capturas de pantalla

### 
![Image ortho view ](https://github.com/lehi10/TopicosEnGrafica/blob/master/Convoluci%C3%B3n%20GPU/python/capturas/colab.png)

### 
![Image perspective view](https://github.com/lehi10/TopicosEnGrafica/blob/master/Convoluci%C3%B3n%20GPU/python/capturas/img1.png)

##
![Image perspective view](https://github.com/lehi10/TopicosEnGrafica/blob/master/Convoluci%C3%B3n%20GPU/python/capturas/img2.png)

## Aplicando filtro identidad
![Image perspective view](https://github.com/lehi10/TopicosEnGrafica/blob/master/Convoluci%C3%B3n%20GPU/python/capturas/imgid.png)

## Aplicando filtro de bordes derivado en X
![Image perspective view](https://github.com/lehi10/TopicosEnGrafica/blob/master/Convoluci%C3%B3n%20GPU/python/capturas/imgv.png)

## Aplicando filtro de bordes derivado en Y
![Image perspective view](https://github.com/lehi10/TopicosEnGrafica/blob/master/Convoluci%C3%B3n%20GPU/python/capturas/imgh.png)

