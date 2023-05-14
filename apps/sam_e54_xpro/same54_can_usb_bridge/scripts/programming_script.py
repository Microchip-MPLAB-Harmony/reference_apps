# *******************************************************************************

from __future__ import print_function
from serial import Serial
from struct import *
import os
import optparse
import math

# ----------------------------------------------------------------------------

hex_array = []
packet_start = 0
packet_length = 60
packet_length1 = 4
packet_end = packet_length
number_of_packets = 0

# ------------------------------------------------------------------------

comnum = input("Enter your COM port number: ")
ser = Serial("COM{}".format(comnum), 115200)


# ------------------------------------------------------------------------


def packet_function():

    global packet_start, packet_end

    if packet_end > len(hex_array):
        packet_end1 = packet_start + packet_length1
        packed_data = pack(">{}B".format(packet_length1), *hex_array[packet_start: packet_end1])
        ser.write(packed_data)


    else:
        packed_data = pack(">{}B".format(packet_length), *hex_array[packet_start: packet_end])
        packet_start = packet_start + packet_length
        packet_end = packet_end + packet_length
        ser.write(packed_data)


# ------------------------------------------------------------------------


def bin_hex_convert(bin_file):
    global number_of_packets
    padding_data = 0xFF

    if os.path.exists(bin_file):

        binfile = open(bin_file, "rb")

        while True:
            byte = binfile.read(1)

            if byte:
                num = int.from_bytes(byte, byteorder='big')
                hex_array.append(num)

            else:
                break

        binfile.close()

        org_hexfile_size = len(hex_array)

        org_hexfile_size_pad = math.ceil(org_hexfile_size / 8192) * 8192

        number_of_packets = org_hexfile_size_pad // packet_length
        temp = org_hexfile_size_pad - (number_of_packets * packet_length)
        temp = temp // 4
        number_of_packets = number_of_packets + temp

        padding_required_data = org_hexfile_size_pad - org_hexfile_size

        for i in range(padding_required_data):
            hex_array.append(padding_data)

        hexfile_size = len(hex_array)

        ser.write(str(hexfile_size).encode())
    else:
        print("\nUnable to locate " + bin_file)


# ------------------------------------------------------------------------


def crc32_tab_gen():
    res = []

    for i in range(256):
        value = i

        for j in range(8):
            if value & 1:
                value = (value >> 1) ^ 0xedb88320
            else:
                value = value >> 1

        res += [value]

    return res


# ------------------------------------------------------------------------


def crc32(tab, data):
    crc = 0xffffffff

    for d in data:
        crc = tab[(crc ^ d) & 0xff] ^ (crc >> 8)

    return crc


# ------------------------------------------------------------------------


def main():
    global packet_start, packet_end, packet_length
    count = 1

    parser = optparse.OptionParser(usage='usage: %prog [options]')
    parser.add_option('-b', '--binfile', dest='binfile', help='binary file to convert', metavar='FILE')

    (options, args) = parser.parse_args()

    if options.binfile is None:
        error('binfile name is required (use -b option)')

    bin_hex_convert(options.binfile)
    print("Press the button SW0 in the Host Development kit.")

    while 1:

        signal = ser.read(1).decode('utf-8')

        if signal == 'X':

            if count > number_of_packets:
                packet_function()
                count = 1
                packet_start = 0
                packet_end = packet_length
                break

            else:

                packet_function()
                count += 1


        elif signal == 'C':

            crc32_tab = crc32_tab_gen()
            crc = crc32(crc32_tab, hex_array)
            ser.write(str(crc).encode())
            ser.close()
            print("New Programming image sent Successfully!!!")

            break

        else:
            print("sorry wrong signal")


# ------------------------------------------------------------------------


main()
