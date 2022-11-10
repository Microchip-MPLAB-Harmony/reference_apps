import tkinter as tk
import os
import serial.tools.list_ports as port_list
from io import BytesIO
from urllib.request import urlopen
from zipfile import ZipFile

path = os.getcwd() + "\\samd21_azure_iot_v2_winc_provisioning"
samioturl = 'https://github.com/Microchip-MPLAB-Harmony/reference_apps/releases/latest/download/samd21_azure_iot_v2_winc_provisioning.zip'
with urlopen(samioturl) as zipresp:
    with ZipFile(BytesIO(zipresp.read())) as zfile:
        zfile.extractall(path)
        
        
mylist =["None (connect IoT Board)"]

ports = list(port_list.comports())
for p in ports:
    mylist.append(p)

cmd = "image_tool.exe -c winc1500_19.7.7\config.txt -o winc1500_19.7.7.prog -of prog"
cmd1 = "winc_programmer -p "
cmd11= " -d winc1500 -i winc1500_19.7.7.prog -if prog -w -r -pfw winc1500_19.7.7\\firmware\programmer_firmware.bin"

print(path)
os.chdir(path)
os.system(cmd)
root= tk.Tk()
root.title("Winc Provisioner")

canvas1 = tk.Canvas(root, width = 400, height = 300)
canvas1.pack()

#Set the Menu initially
menu= tk.StringVar(root)
menu.set("Select COM PORT")

#Create a dropdown Menu
drop= tk.OptionMenu(root, menu,*mylist)
drop.pack()
canvas1.create_window(200, 140, window=drop)

def getcomport ():  
    x1 = menu.get()
    x1= x1.split(' ')
    root.destroy()
    sequence = (cmd1,x1[0],cmd11)
    winc_cmd = " ".join(sequence)
    if(x1[0] != "None"):
        os.system(winc_cmd)
    else:
        print("ERROR :SELECT PROPER COM PORT")
        
button1 = tk.Button(text='Ok', command=getcomport)
canvas1.create_window(200, 180, window=button1)

root.mainloop()


