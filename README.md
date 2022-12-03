
## Hardware

* Arduino Duemilanove (ATmega328p)
* Seeed Motor Shield v2.0 (L298N)
* MG513 12V DC Motors with Hall Rotary Encoders
* Servo Motor for steering (DS3119)
* PowerBank 10000mAh with PD3.0 capability
* USB PD Trigger Board (ZY12PDN)

## Software

To build the project, you need `gcc-avr`, `avr-libc`. To flash MCU, `avrdude` is needed. When flashing, provide the port (for example, `/dev/ttyACM0` on Linux, or `COM3` on Windows).

```bash
cd src
make
make flash PORT=`<your-port>`
```