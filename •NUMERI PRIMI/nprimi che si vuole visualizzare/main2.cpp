import csv
import signal
import sys

np = "numeri_primi.csv"
n = 1

def handle_interrupt(signum, frame):
    print("\nInterrotto manualmente. Salvataggio dei dati...")
    sys.exit(0)

signal.signal(signal.SIGINT, handle_interrupt)

try:
    with open(np, "r") as file_csv:
        reader = csv.DictReader(file_csv)
        last_row = None
        for row in reader:
            last_row = row
        if last_row and 'c' in last_row:
            c = int(last_row['c'])
            n = int(last_row['n'])
        else:
            c = 2
except FileNotFoundError:
    c = 2

while True:
    while True:
        n += 1
        x = 1
        while True:
            x += 1
            r = n % x
            kyr = n / 2
            if not (r != 0 and x < kyr):
                break
        if r != 0:
            break
    
    c += 1
    print(f"{c}, {n}".strip())

    with open(np, "a", newline="") as file_csv:
        writer = csv.writer(file_csv)
        if last_row is None:
            writer.writerow(["c", "n"])
        writer.writerow([c, n])