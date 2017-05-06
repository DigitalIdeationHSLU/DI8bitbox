#!/bin/sh

rm *.zip

[ $# -eq 0 ] && { echo "Usage: $0 projectfile.brd"; exit 1; }

echo "enter amount of boards: "
read AMOUNT

echo "enter colour of pcb: "
read COLOUR

echo "enter ordernumber: "
read ORDERNUMBER

ORDERDETAILS="_10by10_"$COLOUR"_1.6mm_ENIG_"$AMOUNT"pcs.zip"

echo "creating zip file ... yeah!!!"
file=$1

filenoext=$(basename "$file" .brd)

zip $filenoext.zip $filenoext.GTL $filenoext.GBL $filenoext.GTS $filenoext.GBS $filenoext.GTO $filenoext.GBO $filenoext.TXT $filenoext.GML $filenoext.GBP $filenoext.GTP

echo "done. Rename the $filenoext.zip to [ORDERNUMBER][DIMENSION][COLOUR][THICKNESS][SURFACE FINISH HASL][AMOUNT].zip"
echo "for example: 422214_10by10_Green_1.6mm_ENIG_10pcs.zip"

newfile=$ORDERNUMBER$ORDERDETAILS
mv $filenoext.zip $newfile 
