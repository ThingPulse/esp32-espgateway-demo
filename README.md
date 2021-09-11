# ThingPulse ESPGateway

The ThingPulse ESPGateway is a versatile device that comes with two ESP32-WROVER-IB modules.
The two ESP32s are connected by two lines used for inter-ESP32 communication over Serial
or other protocols. Each of the ESP32 can also control two WS2812B RGB Leds at the front 
of the device. 

The ESPGateway is available for purchase at [ThingPulse ESPGateway](https://thingpulse.com/product/espgateway/)

![Gateway](/resources/GatewayWithAntenna.jpg)

## Explanation Demo

After flashing the firmware to both modules they will start communicating to each other.
First they will negotiate which module is ESP1 and which is ESP2 by choosing a random number and
sending it over the serial connection to the other module.

After that they will increase a counter and sending it to the other module. While doing this ping-pong
they will control the addressable WS2812B RGB Leds by moving a red point from one RGB to the next.

## Pins

These are the occupied pins relevant for programming:

```
#define BUS_RXD     14
#define BUS_TXD     15
#define LED_PIN     32
```

![Labelled](/resources/GatewayInside.png)

## Photos

![Labelled](/resources/GatewayBackWithLabels.jpg)
![Back](/resources/GatewayBack.jpg)
![Perspective](/resources/GatewayPerspective.jpg)
![Top](/resources/GatewayTop.jpg)