# for each file in files.txt insert the following as the first line
# #pragma clang optimize off

for file in $(cat files.txt); do
        # if the file does not exist, skip it
        if [ ! -f $file ]; then
                continue
        fi
        echo "Processing $file"
        # open the file and insert the line
        sed -i '1i #pragma clang optimize off' $file
done
