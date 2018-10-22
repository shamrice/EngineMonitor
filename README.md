Engine Monitor
---------------

Project structure is using teensy-template (https://github.com/apmorton/teensy-template) as a base.
Project is made using make instead of the Arduino IDE.

Make Targets (from template_readme.txt)
------------

- `make` alias for `make hex`
- `make build` compiles everything and produces a .elf
- `make hex` converts the elf to an intel hex file
- `make post_compile` opens the launcher with the correct file
- `make upload` uploads the hex file to a teensy board
- `make reboot` reboots the teensy

Libraries Used: (under `libraries`)
------------------------------------
- `SPI` - http://www.arduino.cc/en/Reference/SPI
- `TFT_22_ILI9225` - https://github.com/Nkawu/TFT_22_ILI9225
