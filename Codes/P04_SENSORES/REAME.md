# Práctica sensores

## 01 - Sensor de humedad

1. Conecte el sensor que se muestra en la imagen como se en indica en texto de conexiones

<img src="Images/01.png"/>

Conexiones
GND Sensor -> GND ARDUINO <br>
5V Sensor -> 5V ARDUINO	<br>
Signal -> A0 (SCL)<br>

2. Cargue en el Arduino el codigo en la carpeta P01\_SensorDHT11\_Humidiy\_Temperature.


3. Cambie el valor del delay para verificar que se puedan realizar lecturas más rapidas.

4. Reto: Encienda un led cuando la temperatura exceda los 30 Grados.

## 02 -  Sensor MQ2
Es un sensor de gas analógico. Su conductividad disminuye cuando el el aire está limpio.

1. Conecte el sensor como se muestra en la imagen

<img src="Images/02.png"/>

Conexiones 
GND Sensor -> GND ARDUINO
5V Sensor -> 5V ARDUINO
A0 Sensor -> A0
D0 Sensor -> D4

2. Suba el código 