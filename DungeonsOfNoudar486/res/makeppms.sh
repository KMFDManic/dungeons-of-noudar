#!bash

for f in *.png do
 convert ./"$f" -compress none ./"${f%}.ppm"
done