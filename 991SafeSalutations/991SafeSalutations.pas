function catalanNumber(n: integer): integer;
  begin
    if n = 1 then
      catalanNumber := 1
    else
      catalanNumber := round(double(4 * n - 2) / double(n + 1) * catalanNumber(n-1));
  end;
 
var
  number: integer;
  printBlank: boolean;

begin
  printBlank := false;
  while not eof(input) do begin
    read(number);
    if number = 0 then
      break;
    if printBlank then
      writeln('');
    printBlank := true;
    writeln(catalanNumber(number));
  end;
end.
