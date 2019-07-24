# Eliminación de Ruido en imagenes de rostros 

El código se encuentra en el arhcivo .ipynb

[Colab Project](https://github.com/lehi10/TopicosEnGrafica/blob/master/Proyecto%20Final/Proyecto.ipynb) 

Para ejecutarlo solo se necesitan correr todas las celdas del cuaderno de Colab.

## Arquitectura de la Red Neuronal

#### Autoencoder :
```
class AutoEncoder(nn.Module):
    def __init__(self):
        super(AutoEncoder, self).__init__()
        n_features = 128
        n_out = 128
        
        self.hidden0 = nn.Sequential(
            nn.Linear(n_features, 256),
            nn.LeakyReLU(0.2)
        )
        self.hidden1 = nn.Sequential(    
            nn.Linear(256, 512),
            nn.LeakyReLU(0.2)
        )
        self.hidden2 = nn.Sequential(
            nn.Linear(512, 1024),
            nn.LeakyReLU(0.2)
        )
        
        self.out = nn.Sequential(
            nn.Linear(1024, n_out),
            nn.Tanh()
        )
```
#### DIscriminador 

```
class Discriminator(nn.Module):
    def __init__(self):
        super(Discriminator, self).__init__()
        n_features = 128
        n_out = 128
        
        self.hidden0 = nn.Sequential( 
            nn.Linear(n_features, 1024),
            nn.LeakyReLU(0.2),
            nn.Dropout(0.3)
        )
        self.hidden1 = nn.Sequential(
            nn.Linear(1024, 512),
            nn.LeakyReLU(0.2),
            nn.Dropout(0.3),
        )
        self.hidden2 = nn.Sequential(
            nn.Linear(512, 256),
            nn.LeakyReLU(0.2),
            nn.Dropout(0.3),
        )
        self.out = nn.Sequential(
            torch.nn.Linear(256, n_out),
            torch.nn.Sigmoid()
        )

```

#Resultados

![ ](https://github.com/lehi10/TopicosEnGrafica/blob/master/Proyecto%20Final/img2.png  "Results")