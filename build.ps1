param($path, $ifile, $ofile);
$env:Path += $path;
g++ $ifile -o $ofile -lpthread --std=c++11 -fdiagnostics-color=always -g
