# Raspberry Pi Setup

How to install Raspbian and configure a headless (no keyboard, mouse, or display) Pi for our project.

---

## Install OS on MicroSD Card

1. Format your MicroSD Card
    1. Plug it into your PC
    1. Open File Explorer
    1. Right click the MicroSD Card drive
    1. Format Drive
        1. FAT32 is best

1. Download and start the OS Imager
    1. [Download Link](https://downloads.raspberrypi.org/imager/imager_latest.exe)
    1. Run the .exe to install
    1. Run the Imager

    ![Imager](https://i.imgur.com/CM1cfsU.png)

1. Click `CHOOSE OS` and select Raspberry Pi OS (32-bit)

    ![OS selection](https://i.imgur.com/gPs6S0M.png)

1. Click `CHOOSE STORAGE` and select your MicroSD Card

    ![SD Card](https://i.imgur.com/ZND9JD1.png)

1. Click `WRITE` then click `YES` to accept erasing data

    ![Accept](https://i.imgur.com/9VjMGNc.png)

1. Writing the OS will take some time. Make sure the PC doesn't sleep during this process.

    ![Wait](https://i.imgur.com/WNvD7hi.png)

1. When complete, click `CONTINUE` and close the Imager.

    ![Wait](https://i.imgur.com/1T4JHyv.png)

1. Leave the MicroSD card connected to the PC for now. We aren't done with it yet.
    1. You may need to remove and reconnect the MicroSD card if it is not accessible via the File Explorer

## Enable WiFi

This will allow the Pi to automatically connect to your WiFi network when you turn it on.

1. Open the `boot` directory on the MicroSD card.
1. Create a new file called `wpa_supplicant.conf`
    1. Windows may make the extension `.txt`. Verify the file name is correct and change it if necessary.

    ![Extension](https://i.imgur.com/sncw199.png)

1. Add the text below to the file.
1. Update the network config by putting your information inside the quotes

   ```
   ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev
   country=US
   update_config=1
   
   network={
    ssid="<Name of your wireless LAN>"
    psk="<Password for your wireless LAN>"
   }
   ```

1. Save the file

*Detailed instructions [here](https://www.raspberrypi.org/documentation/configuration/wireless/headless.md).

## Configure SSH

This will allow us to remotely access the Pi.

1. Open the `boot` directory on the MicroSD card.
1. Create a new empty file named `ssh` without a file extension.

    ![Files](https://i.imgur.com/ebB0Sza.png)

*Detailed instructions [here](https://www.raspberrypi.org/documentation/remote-access/ssh/README.md).

## Power Up

1. Remove the MicroSD from the PC and install it into the Pi
1. Turn on the Pi by connecting the USB-C power cord.
1. It should automatically connect to your WiFi and be accessible remotely via SSH.

## Configure static IP

This will ensure that your Raspberry Pi has the same IP address every startup/restart. The exact process varies for different routers. We will try to accomplish this together, as it can be complicated. A Google search for something like `static ip <router name>` should get you pointed in the right direction.

We will need the current IP of the Pi for this. There are a few ways to find this:

1. Access the admin page for your router, often as `192.168.0.0.1` or similar.
1. Install an IP scanner on your smartphone.
1. Download and run an IP scanner on your PC, such as [this free portable one](https://www.advanced-ip-scanner.com/).

    ![IP Scanner](https://i.imgur.com/jtu7QmJ.png)

We will need to set a static IP via your router anyway, so using the router admin page is best.

We will also need your public IPv4 address, which you can find [here](https://whatismyipaddress.com/)

# Remaining steps require remote access

```
username: pi
password: raspberry
```

---

## Change root password

Your Pi is now exposed to the Internet and the default password leaves it vulnerable.

1. Enter `sudo passwd`
1. Type a new password and press enter

## Update and Upgrade the OS

This will ensure the Pi OS has the most up-to-date software

1. Execute `sudo apt update && sudo apt upgrade -y`
1. This process can take a long time the first time you execute it.

    ![Update](https://i.imgur.com/aBKlrtP.png)

## Install git

This will simplify uploading the project code to the Pi.

1. Execute `sudo apt install git`
