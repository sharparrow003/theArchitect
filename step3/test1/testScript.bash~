#! /bin/bash

make clean
make

listFileName="listOfFiles.txt"
testInputDir="testFiles/input"
testOutputDir="testFiles/output"

touch $listFileName
> $listFileName

touch temp1
> temp1

touch temp2
> temp2

ls $testInputDir/ > temp1

while IFS='' read -r line || [[ -n "$line" ]]; do
    x=${line%.micro}
    y=${x#test}
    echo $y >> temp2
done < temp1

sort -k1 -n temp2 > temp3

while IFS='' read -r line || [[ -n "$line" ]]; do
    echo test$line >> $listFileName
done < temp3

while IFS='' read -r line || [[ -n "$line" ]]; do
    Micro $testInputDir/$line.micro > $line.output

    if [[ $(diff -bB $line.output $testOutputDir/$line.out) ]]
    then
	echo $line Failed!
    else
	echo $line Passed!
    fi

    rm -rf $line.output

done < $listFileName


rm -rf temp1
rm -rf temp2
rm -rf temp3
rm -rf $listFileName




