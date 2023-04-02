#!/usr/bin/python3
import logging
import logging.handlers

# Set up logging to syslog
logger = logging.getLogger('my_logger')
logger.setLevel(logging.WARNING)  # set the logging level to warning or higher
handler = logging.handlers.SysLogHandler(address=('10.100.102.95', 514)) # the IP address and port of the remote syslog server
logger.addHandler(handler)

# Log some messages
logger.debug('This is a debug message')
logger.info('This is an info message')
logger.warning('This is a warning message')
logger.error('This is an error message')
logger.critical('this is a critical messege')
logger.debug('This is a debug message')
logger.fatal('this is a fatal messege')