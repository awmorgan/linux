# open the file
# read it in and remove all lines that start with # or are blank
# write it back out

import os
import sys

def main():
    if len(sys.argv) != 2:
        print("Usage: cleanup_pp.py <filename>")
        sys.exit(1)
    filename = sys.argv[1]
    if not os.path.exists(filename):
        print("File %s does not exist" % filename)
        sys.exit(1)
    with open(filename, "r") as f:
        lines = f.readlines()
    with open(filename, "w") as f:
        for line in lines:
            if line[0] != "#" and line.strip():
                f.write(line)


if __name__ == "__main__":
    main()
