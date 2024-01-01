import os
from datetime import datetime, timedelta

def count_files(path):
    now = datetime.now()
    files = os.listdir(path)
    count = 0
    for file in files:
        file_path = os.path.join(path, file)
        file_creation_time = datetime.fromtimestamp(os.path.getctime(file_path))
        if (now - file_creation_time) > timedelta(minutes=5):
            count += 1
    return count

def write_log(log_file, descr, count_number, msg):
    timestamp = datetime.now().strftime("%b %d %Y %H:%M:%S")
    log_entry = f"{timestamp} tzur_app CEF:0|osa-mailer| | | |Alert| |msg={msg} descr={descr} num={count_number} "
    print(log_entry)
    #with open(log_file, 'w') as file:
    #    file.write(log_entry + '\n')

log_file_name = f"osa_mailer_counter_{datetime.now().strftime('%b_%d_%Y_%m.%M.%S')}.log"
logs_folder = os.path.join('G:\\AutoMail\\', log_file_name)

descr = ""
msg = ""
file_path = 'C:\\osa-mailer\\outbox'
count_number = count_files(file_path)

if count_number > 0:
    descr = f"There are {count_number} files in osa-mailer-outbox older than 10 minutes"
    msg = "overload"
else:
    descr = "The osa-mailer-outbox is fine"
    msg = "ok"

write_log(logs_folder, descr, count_number, msg)
