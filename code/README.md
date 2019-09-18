# BSidesDFW_2019_Badge / Code

This is where all the files related to code and/or firmware for the badge.

## File Structure

This is the file structure of this repository

* [/](/README.md) - Home
* [/code/](/code/) - YOU ARE HERE
* [/code/ugly_dev_board/](/code/ugly_dev_board/) - Code for the Ugly Dev Board CH552G
* [/code/CH552T_dev_board/](/code/CH552T_dev_board/) - Code for the CH552T dev board designed by wrickert
  * Reference to his CH552T dev board here: https://github.com/wrickert/CH552
* [/code/CH552G_dev_board/](/code/CH552G_dev_board/) - Code for the CH552G dev board designed by @alt_bier
  * Reference to that CH552G dev board here: [/eda/CH552G_dev/](/eda/CH552G_dev/)



## General Notes

For now the type of code needed will be up in the air until we choose a microcontroller.

The CH552G is first up for consideration and uses a stripped down C code with SDCC to implement.

Here is a link to some good documentation on OpenSource SDCC and the CH55x SDK https://github.com/Blinkinlabs/ch554_sdcc

## How to program the CH55x Micro Controller

The CH55x series of Micro Controllers are based off of an ARM 8051 chipset and can be programmed using [Kiel C51](http://www.keil.com/c51/) or [SDCC](http://sdcc.sourceforge.net/).

I will document here how I was able to set up both a Windows and a Linux box to program this chip using SDCC.

### Windows Setup

Here are the steps I followed to get the toolchain fully set up to compile and push code to the CH55x chips on my Windows box.

* Download and Install [Git for Windows](https://gitforwindows.org/) which provides a git-bash CLI that will be used to download and compile the code.
* Download and Install [SDCC](http://sdcc.sourceforge.net/) using the [latest version here](https://sourceforge.net/projects/sdcc/files/latest/download?source=files)
* Download and Install [MinGW - Minimalist GNU compiler for Windows](https://sourceforge.net/projects/mingw/) using the [latest version here](https://downloads.sourceforge.net/project/mingw/Installer/mingw-get-setup.exe)
* Download and Install the [WCHISPTOOL from the chip manufacturer wch.cn](http://wch.cn/download/WCHISPTool_Setup_exe.html) which will be used to push compiled code to the chip over USB
* Because this is Windows, one or more of the above installs may require a reboot.
* Open a git-bash CLI window and edit or create a file named .bashrc in your home directory ~/ and add the following text.
```
# SDCC compiler tools
export PATH=$PATH:/c/Program\ Files/SDCC/bin

# Mingw tools (for Make)
export PATH=$PATH:/c/MinGW/bin

alias make=mingw32-make.exe
```
* Exit out of the git-bash CLI Window and open it up again to have it load the new .bashrc file.  It may give you a message about creating other files automatically (like .profile .bashprofile etc.)
* Next we need to download some test code to test compiling from [The Blinkinlabs CH554_SDCC github repository](https://github.com/Blinkinlabs/ch554_sdcc)
* At the git-bash CLI type the following to clone this repository:
```
git clone https://github.com/Blinkinlabs/ch554_sdcc.git
```

* This will create a directory named ch544_sdcc containing all of the files.
* Change directory to ch544_sdcc/examples/blink/
* You should see two files there, a Makefile and a main.c file.  Don't worry about modifying those files to match your development board, we are just going to try to compile it to verify out toolchain is working.
* Type ```make``` in this directory and it should compile this example.  If it does not then read the errors to see what is wrong and try again until it compiles without error.
* Upon successful compile you will have many more files in this directory including one named blink.hex which is the file we will attempt to push to the chip

At this point your compiler toolchain is complete and verified.

Next up, USB communication to push code to the micro controller.

* If you have a CH55x development board you can test pushing this code to the chip using the WCHISPTOOL.  From Windows start menu launch the WCHISPTOOL.
* Next plug in the CH55x development board into a USB port in programming mode (hold down the appropriate button while inserting the USB).
* In the WCHISPTOOL Choose the tab for the chip type you have plugged in and look for your device name listed.  If not listed try to unplug and reconnect the chip to get it to show up.  If still having issues reinstall the WCH USB Driver (included with the tool)
* In the WCHISPTOOL chip specific tab choose the file to download to the chip.  This can be the blink.hex file you created for testing or another example.  Click the download button and it will push this file to the chip.  In the dialog box you will see its progress and completion status.

At this point you can upload code to the micro controller.

### Debian Linux Setup

Here are the steps I followed to get the toolchain fully set up to compile and push code to the CH55x chips on my Ubuntu (Debian based) Linux box.

* Install the compiler tool chain with the following:
```
sudo apt install build-essential sdcc
```

* Next we need to download some test code to test compiling from [The Blinkinlabs CH554_SDCC github repository](https://github.com/Blinkinlabs/ch554_sdcc) with the following:
```
git clone https://github.com/Blinkinlabs/ch554_sdcc.git
```

* This will create a directory named ch544_sdcc containing all of the files.
* Change directory to ch544_sdcc/examples/blink/
* You should see two files there, a Makefile and a main.c file.  Don't worry about modifying those files to match your development board, we are just going to try to compile it to verify out toolchain is working.
* Type ```make``` in this directory and it should compile this example.  If it does not then read the errors to see what is wrong and try again until it compiles without error.
* Upon successful compile you will have many more files in this directory including one named blink.hex which is the file we will attempt to push to the chip

At this point your compiler toolchain is complete and verified.

Next up, USB communication to push code to the micro controller.

* Download and install the libusb 1.0 development image with the following:
```
sudo apt-get install libusb-1.0-0-dev
```

* Download the open-source implementation of the WCH ISP Tool from here: [LibreCH551 Tool](https://github.com/rgwan/librech551) with the following:
```
git clone https://github.com/rgwan/librech551.git
```

* This will create a directory named librech551 containing all of the source files.
* Change directory to librech551/usbisp/
* You should see two files there, a Makefile and a main.c file.
* Type ```make``` in this directory and it should compile the ```wchisptool``` executable.  If it does not then read the errors to see what is wrong and try again until it compiles without error (warnings are usually ok as long as the executable is produced).
* Once you have a successful compilation type ```make install``` in order to install the program. (you might have to use ```sudo``` with this if you get a permission denied error)
* To download code to the chip use the following:
```
sudo wchisptool -f mycode.bin
```

At this point you should be able to upload code to the micro controller.

NOTE: The linux wchisptool is hit or miss on working.  Have had quite a few issues with it and am looking for an alternative.
