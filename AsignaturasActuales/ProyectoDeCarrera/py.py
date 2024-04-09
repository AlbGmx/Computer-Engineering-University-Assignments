#! python3.8

import time
import psutil

# psutil functions
print(psutil.cpu_percent(interval=1))
print("\n")
print(psutil.cpu_times())
print("\n")
print(psutil.cpu_count())
print("\n")
print(psutil.cpu_stats())
print("\n")
print(psutil.virtual_memory())
print("\n")
print(psutil.disk_usage('/'))
print("\n")
print(psutil.net_io_counters(pernic=True))
print("\n")
print(psutil.net_if_addrs())
print("\n")
print(psutil.net_if_stats())
print("\n")


def verifyProcInList(name):
    print("New process detected")
    print(p.name)

old_set = set(list(psutil.process_iter()))
while True:
    new_set = set(list(psutil.process_iter()))
    added = new_set - old_set
    for p in added:
        verifyProcInList(p)
    old_set = new_set
    time.sleep(5.0)