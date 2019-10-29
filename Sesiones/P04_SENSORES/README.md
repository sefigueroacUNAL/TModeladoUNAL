# Práctica sensores

## 01 - Sensor de humedad

1) Conecte el sensor que se muestra en la imagen como se en indica en texto de conexiones

<img src="Images/01.png"/>

### Conexiones
GND Sensor -> GND ARDUINO <br>
5V Sensor -> 5V ARDUINO	<br>
Signal -> A0 (SCL)<br>

2) Cargue en el Arduino el codigo en la carpeta P01\_SensorDHT11\_Humidiy\_Temperature.


3) Cambie el valor del delay para verificar que se puedan realizar lecturas más rapidas.

4) Reto: Encienda un led cuando la temperatura exceda los 30 Grados.

## 02 -  Sensor MQ2
Tomado de <https://hetpro-store.com/TUTORIALES/sensor-de-gas-mq2/>
Es un sensor de gas analógico. Su conductividad disminuye cuando el el aire está limpio.

1) Conecte el sensor como se muestra en la imagen

<img src="Images/02.png"/>

### Conexiones 
GND Sensor -> GND ARDUINO <br>
5V Sensor -> 5V ARDUINO<br>
A0 Sensor -> A0<br>
D0 Sensor -> D4<br>

2) Suba el código 

3) Modifique el valor del potenciómetro para ajustar la sensibilidad en el pin digital.

## 03 Sensor de flama

1) Conecte el sensor que se muestra en la imagen como se en indica en texto de conexiones

<img src="Images/03.png"/>

### Conexiones
GND Sensor -> GND ARDUINO <br>
5V Sensor -> 5V ARDUINO	<br>
Analog -> A0 (SCL)<br>
digital output -> D4

2) Suba el código y abra la consola serial.
 
3) Acerque una fuente de fuego (un encendedor o una vela). <br>
Revise que valor de la lectura se modifique. <br>
En caso de que esto no ocurra debe ajustar del potenciometro (elemento azul), para ajustar la sensibilidad. <br>
También debe verificar las condiciones el luz del espacio. Si es un espacio muy iluminado, en especial con la luz del sol, la lectura se puede ver afectada.


# 04 Sensor IRemote
Tutorial básado en <https://naylampmechatronics.com/blog/36_Tutorial-Arduino-y-control-remoto-Infrarrojo.html> <br>

1) Conecte el sensor que se muestra en imagen como se indica en el texto de conexiones.

<img src="Images/04.png"/>

**Conexiones**

GND Sensor -> GND ARDUINO <br>
5V Sensor -> 5V ARDUINO	<br>
Signal -> D3 <br>

2) Suba el código y abra la consola serial.

3) Con el control remoto (puede ser cualquier que utilice infrarrojo) apunte hacia el receptor y presione una tecla del control

4) Verifique que se muestre un valor como en la imagen.
<img src="Images/04B.png"/>

5) Reto  conecte 3 Leds o un buzzer al Arduino, y encienda cada uno con una tecla diferente.

# 05 Sensor de efecto Hall






