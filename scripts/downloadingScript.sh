
oldDirectory= pwd
cd $3
for (( number=$1; number<=$2; number++)) do
	pathToWebsite="http://www.wykop.pl/strona/"
	pathToWebsite+=$number
	filename=$(echo $pathToWebsite | sed -e 's/[^A-Za-z0-9._-]/_/g') 
	mkdir $filename
	cd $filename
	wget "$pathToWebsite" 
	echo sciagam $pathToWebsite
	cd ../
	sleep 1
done
cd $oldDirectory
