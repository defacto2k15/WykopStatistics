#sed -i 's/\<time>/\<div\ class=\"time\"\>/g' $1
#sed -i 's/\<\/time>/\<\/div\>/g' $1
sed -i 's/<time/<div/g' $1
sed -i 's/<\/ime/<\/div/g' $1
sed -i 's/\<article/\<div/g' $1
sed -i 's/\<header/\<div/g' $1

tidy  -asxml -utf8 -f err.txt -q -o $2  $1

sed -i 's/\&nbsp\;//g' $2
