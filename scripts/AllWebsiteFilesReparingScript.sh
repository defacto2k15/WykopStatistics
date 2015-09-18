# ARG1: root path of directory with websites PRE cleaning
FILES="$(./scripts/scriptFindingAllWebsiteFiles.sh $1)" 


for oneFile in $FILES; do
	ADDED_FILE_SUFFIX=".xml"
	CHANGED_FILE=$oneFile$ADDED_FILE_SUFFIX
	./scripts/clearingScript.sh $oneFile $CHANGED_FILE
done
