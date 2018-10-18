Engine Monitor
---------------

Project structure is using teensy-template (https://github.com/apmorton/teensy-template) as a base.
Project is made using make instead of the Arduino IDE.

Make Targets (from tempalte_readme.txt)
------------

- `make` alias for `make hex`
- `make build` compiles everything and produces a .elf
- `make hex` converts the elf to an intel hex file
- `make post_compile` opens the launcher with the correct file
- `make upload` uploads the hex file to a teensy board
- `make reboot` reboots the teensy
