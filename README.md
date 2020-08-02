# AREA_Maska

### Summary
As we know Corona virus is the pandemic situation, which spread very easily and we don't even know easily whose has a symptom and whose not, also we know that, one of the main symptom of it is High Temperature, so we made an new electronic mask which it can measure our temperature, and show it in screen of mask, and send it to our phone via Bluetooth, at the same time if your temperature is higher than normal temperature, the screen will be red (danger) , if not, it will be yellow (positivism).

### How We Developed This Project
If we research about type of traditional masks, we can easily see that all type of masks has no data gathering, monitoring and artificial intelligence. There is not any modern (technological) materials, and for using it more than once, we should buy it again. At the same time when we research WHO Corona-virus Map and NASA Worldview Population Density, we can ensure that if we will not prevent the Corona virus, the spreading of these virus will increase enormously again, so we started brainstorming for modern Smart Mask. We wanted to create the new type of modern mask, which can easily show us our health status (temperature), and send it our phone, basically the mask which has data gathering, monitoring. We succeed it. In the demonstrate part you can easily see that our Smart Mask is much better than traditional mask. By using our Smart Mask, we can easily identify the person having COVID-19 before it spread, it could significantly reduce the spreading the virus.

The Smart Mask was printed by 3D Printer according to the CAD, it has filter, it means, you don't need to buy the mask again  (like traditional masks), you only need to change the filter of it. The micro-controller of Smart Mask is TTGO ESP32, and temperature sensor is ds18b20. The energy source of Smart Mask is 3.7V Li-Po Battery, it can easily provide the Smart Mask with energy. The program was written with using C++ in Arduino IDE. Due to the program, the mask can also find our approximate body temperature according to the face temperature. Another advantage of Mask is that, you can see your temperature in phone as well, also you can send some commands to the mask, for instance if you want to deactivate display, and save your battery energy, you need to write in Serial Terminal 'deactivate display', after few minutes it will turn off display. Also it has other commands (activate display, face temperature, approximately body temperature etc). 

<p float="left">
  <img src="https://user-images.githubusercontent.com/56725845/89120904-fc52f980-d4ca-11ea-9ab3-68a0a5043616.jpeg" width = "333" height = "444" /> 
  <img src="https://user-images.githubusercontent.com/56725845/89120894-e3e2df00-d4ca-11ea-8376-55e547f30844.png" width = "270" height = "444"/>
  <img src="https://user-images.githubusercontent.com/56725845/89121168-aaf83980-d4cd-11ea-87f5-93b0add31e5f.jpeg" width = "333" height = "444" /> 
</p>
