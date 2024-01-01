#!/usr/bin/env python3

import subprocess
import requests
import cv2
import numpy as np

webhook_url = "https://discord.com/api/webhooks/********************"

# Use the tail command to monitor the auth.log file in real-time
tail_command = "tail -f -n 0 /var/log/auth.log"

# Start the tail process
tail_process = subprocess.Popen(tail_command.split(), stdout=subprocess.PIPE)

# Read the output of the tail process line by line
for line in iter(tail_process.stdout.readline, b''):
    # Check if the line contains a failed login attempt
    if "authentication failure" in line.decode("utf-8"):
        # Capture a photo from the webcam
        capture = cv2.VideoCapture(0)
        ret, frame = capture.read()
        capture.release()

        # Save the captured photo
        photo_path = "/tmp/photo.jpg"
        cv2.imwrite(photo_path, frame)

        # Send the captured photo via webhook
        message = "Failed login attempt detected"
        data = {"content": message}
        files = {"image": open(photo_path, "rb")}
        response = requests.post(webhook_url, data=data, files=files)
