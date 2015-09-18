Zbieracz danych statystycznych o głównej wykopu :
Kilka programów i skryptów do ściągania i przetwarzania stron głównych wykopu by 
interesujące dane wyeksportować do arkusza w formacie csv.

Napisany w c++ i bashu, z użyciem biblioteki pugi do obsługi xml

Jak używać:

Aby otrzymać statystyki dotyczące znalezisk na głównej przede wszystkim potrzeba pliku xml opisującego te znaleziska. Można go ściągnąć z internetu, link: http://www.filedropper.com/outxml_1 , albo też samemu wygenerować. 
W przypadku jak nie chce ci się generować przejdź do punktu 2.

1) Tworzenie pliku ze znaleziskami
Potrzebne: linux ze standardowymi programami typu cd, sed, ...
cmake, gcc, boost, wget
a) Należy ściągnąć wszystkie  "odsłony" głównej, czyli kolejne strony wykop.pl/strona/1, wykop.pl/strona/2 ..... 
Aby moje skrypty potrafily to je przetworzć wszystkie ściągnięte strony HTML muszą znajdować się w jednym folderze lub w podfolderach jednego folderu, w którym nie mogą się znajdować pliki o nazwach kończoncych się na ".xml". Ściągać strony można samemu albo użyć odpowiedniego skryptu: 
	Aby ściągnąć wszystkie główne między 1 i 100 i zapisać w folderze ~/wykop/ używamy skryptu z argumentami: 
	./scripts/downloadingScript.sh 1 100 "~/wykop" 

b)Teraz należy każdą z tych stron "naprawić" ponieważ kilka nielegalnych elementów w stronie wykopu uniemożliwia interpretacje ich jako XML przez pugi. 
Robimy to skryptem:
	./scripts/AllWebsiteFilesReparingScript.sh $1 gdzie 
		$1 to root folder ze stronami, czyli np "~/.wykop"
		Uwaga: ścierzkę trzeba podać jako "bezpośrednią" czyli np ~/folder/Wykop/WykopWebsites a nie po prostu WykopWebsites
Co więcej skrypt wykonuje się strasznie długo

c) Należy skompilować program "WykopTopicsFetcher": przykładowe komendy
cd WykopTopicsFetcher/build
cmake ../
make

d) Otrzymany program działa w ten sposób, że otrzymuje liste ścierzek do plików xml do standardowago wejścia i nazwe pliku wyjściowego jako argument. Uruchamiamy go za pomocą komendy:
	./scripts/scriptFindingAllWebsitesAfterCleaning.sh ~/.wykop |  ./WykopTopicsFetcher/build/WykopTopicsFetcher outXml.xml
	gdzie outXml.xml to przykładowy wyjściowy plik który będzie miał dane wszystkich znalezisk na głównej
Czasami pojawia się błąd "Error while loading /path/to/file.xml" najłatwiej naprawić go kasując ten błędny plik

e) Należy usunąć z pliku słowa "komentarz" "komentarze" "komentarzy". Robimy to skryptem
	./scripts/scriptNormalizingXmlValues.sh $1 gdzie
	$1 to nazwa pliku z opisem znalezisk (outXml.xml)

2) Tworzenie pliku csv ze danymi statystycznymi
a) Należy skompilować program WykopMainDataAlanyzer
cd WykopMainDataAlanyzer/build
cmake ../
make

b) Program ten dziala tak, że wszystkie "charakterystyki" ( na razie tylko liczba znalezisk i liczba wykopów ) sumuje osobno dla każdej "kategorii". Znaleziska przypisuje bądz nie do kategorii sprawdzając czy w tytule bądz opisie znaleziska występują słowa kluczowe. Nazwy kategorii i słowa kluczowe wczytuje z pliku konfiguracyjnego w formacie xml. Dodałem przykladowy plik nazwamy "categories.xml". Sposób jego konstrukcji jest bardzo prosty

Uwaga: jeżeli dla kategorii brakuje tagu keywords to wszystkie znaleziska dodawane są do tej kategorii

c) Odpalamy program WykopMainDataAlanyzer za pomocą komendy 
./WykopMainDataAlanyzer/build/WykopMainDataAlanyzer $1 $2 $3 gdzie:
	$1 - plik wejściowy ze informacją o wykopaliskach (outXml.xml)
	$2 - plik konfiguracyjny (categories.xml)
	$3 - plik wyjściowy (outCsv.csv)

d) Opis poszczególnych kolumn znajduje się na dole pliku csv zamiast na górze
