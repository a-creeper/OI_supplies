const big_root_priority_queue=true;
      small_root_priority_queue=false;
type priority_queue=object
                      private
                        main:array of longint;
                        size:longint;
                        mode:boolean;
                      public
                        procedure init(a:boolean);
                        procedure push(a:longint);
                        function pop:longint;
                        procedure top;
                        function empty:boolean;
                      end;
procedure priority_queue.init(a:boolean);inline;
begin
  setlength(main,0);
  size:=0;mode:=a;
end;
procedure priority_queue.push(a:longint);inline;
var x,t:longint;
begin
  inc(size);
  setlength(main,size+1);
  main[size]:=a;
  x:=size;
  while x<>1 do
    if (main[x]<main[x>>1]) xor mode then
    begin
      t:=main[x];
      main[x]:=main[x>>1];
      x:=x>>1;
      main[x]:=t;
    end
    else
      break;
end;
function priority_queue.pop:longint;inline;
begin
  exit(main[1]);
end;
procedure priority_queue.top;inline;
var t,x:longint;
begin
  t:=main[1];
  main[1]:=main[size];
  main[size]:=t;
  dec(size);
  setlength(main,size+1);
  x:=1;
  while x<<1<size do
    if ((main[x]<main[x<<1])xor mode)and((main[x]<main[x<<1+1])xor mode) then
      break
    else
    if (main[x<<1]<main[x<<1+1]) xor mode then
    begin
      t:=main[x];
      main[x]:=main[x<<1];
      x:=x<<1;
      main[x]:=t;
    end
    else
    begin
      t:=main[x];
      main[x]:=main[x<<1+1];
      x:=x<<1+1;
      main[x]:=t;
    end;
  if (x<<1=size) and ((main[x]>main[x<<1]) xor mode) then
  begin
    t:=main[x];main[x]:=main[x<<1];main[x<<1]:=t;
  end;
end;
function priority_queue.empty:boolean;inline;
begin
  exit(size<>0);
end;
var a:priority_queue;
    n,x,y:longint;
begin
  a.init(small_root_priority_queue);
  readln(n);
  for n:=1 to n do
  begin
    read(x);
    if x=1 then read(y);
    case x of
      1:a.push(y);
      2:writeln(a.pop);
      3:a.top;
    end;
  end;
end.
