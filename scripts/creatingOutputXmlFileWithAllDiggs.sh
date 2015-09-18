#Args:
set -o nounset                              # Treat unset variables as an error

PathToWykopTopicsFetcherBinary=$1
PathToOutputXml=$2
PathToCleanedWebsitesFinderScript=$3
PathToRootDictWithCleanedWebsutes=$4

$3 $4 | $1 $2 
