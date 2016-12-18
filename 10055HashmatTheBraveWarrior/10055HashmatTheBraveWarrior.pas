var
  numberA: real;
  numberB: real;

begin
  while not eof(input) do begin
      read(numberA);
      if eof(input) then
        break;
      read(numberB);
      writeln(Abs(Round(numberB - numberA)));
  end;
end.
