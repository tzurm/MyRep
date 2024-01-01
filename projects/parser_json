import os
import json

def read_json_files(folder_path, output_file):
    log_sources = set()  # Store unique log sources
    with open(output_file, 'w') as output:
        for filename in os.listdir(folder_path):
            if filename.endswith('.json'):
                file_path = os.path.join(folder_path, filename)
                with open(file_path, 'r') as file:
                    data = json.load(file)
                    log_source = None
                    timestamp = None
                    if 'table' in data['context']:
                        entries = data['context']['table']['+entries']
                        if len(entries) > 1: 
                            log_source = entries[1].get('value')   
                    if log_source is not None and log_source not in log_sources:
                        log_sources.add(log_source)
                        output.write(f"File: {filename},\t Log Source: {log_source}\n")

folder_path = 'C:\\osa-mailer\\outbox'
output_file = "json_report.txt"
read_json_files(folder_path, output_file)
