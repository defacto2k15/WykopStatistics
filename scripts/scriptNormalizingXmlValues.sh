# args: 1 - path to file to delete words in
for wordToDelete in "komentarze" "komentarzy" "komentarz"; do
	echo $wordToDelete
	sed -i "s/$wordToDelete//g" $1
done
