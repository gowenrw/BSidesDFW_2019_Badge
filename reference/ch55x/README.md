# BSidesDFW_2019_Badge / Reference / CH55x

Reference Materials related to the CH55x micro-controller.

## File Structure

This is the file structure of this repository

* [/](/README.md) - Home
* [/reference/](/reference/) - Documentation pulled from other sources related to the badge components
  * [/reference/ch55x/](/reference/ch55x/) - YOU ARE HERE

## Information

Basics on the CH551:
* 8051 Kernel with most standard registers, commands etc. only 10-15x
* Integrated oscillator up to 24Mhz
* 3x timer
* 2x 8bit PWM
* 1x SPI master / slave
* 2x UART
* 4x ADC 8bit
* 6x touch input
* 16K ROM
* 1K xRAM
* 256b iRAM
* Integrated 3.3V voltage regulator
* Integrated USB device
* 5V or 3.3V operation
* i2c is no problem with bitbanging

Programming is either with Keil C51 or with SDCC (links below)

## Reference Files

* Jiangsu Qin Heng CH552G
  * Tested and CHOSEN for the badge as it's form factor and pin count works for the badge
  * [LCSC.COM Reference](./1812131556_Jiangsu-Qin-Heng-CH552G_C111292_lcsc.com.pdf)
  * [Datasheet CN](./1812131556_Jiangsu-Qin-Heng-CH552G_C111292_datasheet.pdf)
  * [Datasheet EN](./1812131556_Jiangsu-Qin-Heng-CH552G_C111292_datasheet_zh-CN-en-Translated.pdf)
* Jiangsu Qin Heng CH552T
  * Tested and NOT chosen as it's smaller form factor was not a good fit
  * [LCSC.COM Reference](./Jiangsu-Qin-Heng-CH552T_C111367_lcsc.com.pdf)
  * [Datasheet CN](./Jiangsu-Qin-Heng-CH552T_C111367_datasheet.pdf)
  * [Datasheet EN](./Jiangsu-Qin-Heng-CH552T_C111367.zh-CN.en.pdf)

## External References

* [Hackaday article on CH552](https://hackaday.com/tag/ch552/)
* [Blog site with details on CH552](http://atcnetz.blogspot.com/2019/02/ch552-020-mikrocontroller-mit-usb.html)
* [CH55X Android Programmer](https://play.google.com/store/apps/details?id=com.atcnetz.de.ch55xprogrammer)
* [ARM KEIL C51 DEV Tools](http://www.keil.com/c51/)
* [CH554 software development kit for SDCC](https://github.com/Blinkinlabs/ch554_sdcc)
* [Small Device C Compiler SDCC](https://sourceforge.net/projects/sdcc/files/latest/download?source=files)
* [WCHISPTool Firmware Uploader](http://wch.cn/download/WCHISPTool_Setup_exe.html)
* [lcsc.com WCH products](https://lcsc.com/products/WCH_11013.html)
