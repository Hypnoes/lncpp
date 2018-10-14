param($path, $ifile, $ofile);

$env:Path += $path;
if (-not (Test-Path ($path += "\\target"))) { mkdir $path; }
&g++ $ifile -o $ofile -lpthread --std=c++17 -fdiagnostics-color=always -g;
