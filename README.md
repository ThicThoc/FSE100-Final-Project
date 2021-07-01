# FSE100-Final-Project

Source Code for Electrosity's FSE 100 final project

---

## Install Code

1. Create Dev directory

    ```
    mkdir Documents/Dev
    ```

1. Install code from Github

    ```
    git clone https://github.com/ThicThoc/FSE100-Final-Project.git Documents/Dev/bot
    ```

1. Update code

    ```
    git -C Documents/Dev/bot pull origin main
    ```

## Start Server

1. Manually

   ```
   python3 Documents/Dev/bot/src/server/app.py
   ```

1. Automate with Cron

   1. Open crontab
      ```
      crontab -e
      ```
   
   1. Add to the end of the file
   
      ```
      @reboot python3 Documents/Dev/bot/src/server/app.py
      ```



## Set up the Raspberry Pi

Follow instructions [here](pi_setup.md)

## GPIOZero

- [Documentation](https://gpiozero.readthedocs.io/en/stable/index.html)

## MegaPi

- [DC Motor Control](https://gist.github.com/xeecos/5fa6cb5876a8c9449562d8026942fff1/revisions)
- [Sensor](https://gist.github.com/xeecos/ceeb8fd83cc15b4e83b713bb75a982fd)

## Actuator

- [Amazon](https://www.amazon.com/Jameco-Reliapro-PDL-50-Driven-Actuator/dp/B01MRDHWGY)
- [Jameco](https://www.jameco.com/z/PDL-50-Jameco-Valuepro-Automotive-Door-Lock-Actuator-12-VDC-Intermittent-Duty_2230221.html)
