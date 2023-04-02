#!/usr/bin/python3
import logging
import logging.handlers
import subprocess

# Set up logging to syslog
logger = logging.getLogger('my_logger')
logger.setLevel(logging.WARNING)
handler = logging.handlers.SysLogHandler(address=('192.168.0.120', 514))
logger.addHandler(handler)

# Run the tail command to monitor the audit log file
p = subprocess.Popen(['tail', '-f', '-n', '0', '/var/log/audit/audit.log'], stdout=subprocess.PIPE, stderr=subprocess.PIPE)

# Read the output of the tail command line by line
for line in iter(p.stdout.readline, b''):
    # Extract the relevant information from the line
    line = line.decode('utf-8').strip()
    if "chmod" in line and "type=SYSCALL" in line:
        msg = line[line.index("type=SYSCALL"):]
        logger.critical(f"[crit] someone used chmod!, DETAILS: {msg}")

# Close the connection to the logger
logger.removeHandler(handler)
