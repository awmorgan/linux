
import os

# get a list of all directories and subdirectories in the current directory but
# ignore links
dir_list = [x[0] for x in os.walk(os.getcwd()) if not os.path.islink(x[0])]

# for each directory in the list get the list of files in the directory ignoring links
for dir in dir_list:
    file_list = [x for x in os.listdir(dir) if not os.path.islink(os.path.join(dir, x))]

    # for each file in the list check if there is a file with the same name but
    # different case in the same directory be careful to not check the file
    # against itself, and order the list so that the matching filenames are
    # together, store the result in a list
    result = []
    for file in file_list:
        if file.lower() in [x.lower() for x in file_list if x != file]:
            result.append(file)

    # case insensitive sort the list and print the result
    result.sort(key=str.lower)
    if result:
        for file in result:
            print(os.path.join(dir, file))

    # now search for any file in the current directory and subdirectories that
    # has a name that would be invalid on Windows e.g. aux, con, prn, nul, com1,
    # com2, com3, com4, com5, com6, com7, com8, com9, lpt1, lpt2, lpt3, lpt4,
    # lpt5, lpt6, lpt7, lpt8, lpt9 ignore links, and make sure to pick up files
    # that have different case, e.g. AUX, CON, PRN, etc. and match against the
    # base name of the file not the full path or the file extension
    result = []
    for file in file_list:
        if os.path.splitext(file)[0].lower() in ['aux', 'con', 'prn', 'nul', 'com1', 'com2', 'com3', 'com4', 'com5', 'com6', 'com7', 'com8', 'com9', 'lpt1', 'lpt2', 'lpt3', 'lpt4', 'lpt5', 'lpt6', 'lpt7', 'lpt8', 'lpt9']:
            result.append(file)

    # print out the result
    if result:
        for file in result:
            print(os.path.join(dir, file))
