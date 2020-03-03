const endl=chr(13);
function i2s(a:longint):ansistring;inline;
var t:ansistring;
begin
  str(a,t);
  exit(t);
end;
function s2i(a:ansistring):longint;inline;
var t:longint;
begin
  val(a,t);
  exit(t);
end;
function max(a,b:longint):longint;inline;
begin
  exit(ord(a<b)*b+ord(a>b)*a);
end;
function min(a,b:longint):longint;inline;
begin
  exit(ord(a<b)*a+ord(a>b)*b);
end;