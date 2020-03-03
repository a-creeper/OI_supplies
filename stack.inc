type tstackt=^tstack;
     tstack=record
               last:tstackt;
               next:tstackt;
               v:longint;
             end;
     stack=object 
             private
               main:tstackt;
               size:longint;
             public
               procedure init;
               procedure push(a:longint);
               function pop:longint;
               procedure top;
               function empty:boolean;
           end;
procedure stack.init;
begin
  size:=0;
  if main<>nil then
    dispose(main);
  new(main);
  main^.v:=0;
  main^.next:=nil;
  main^.last:=main;
end;
procedure stack.push(a:longint);
begin
  new(main^.next);
  main^.next^.v:=a;
  main^.next^.last:=main;
  main^.next^.next:=nil;
  main:=main^.next;
  inc(size);
end;
function stack.pop:longint;
begin
  exit(main^.v);
end;
procedure stack.top;
var x:tstackt;
begin
  x:=main^.last;
  dispose(main);
  main:=x;
  dec(size);
end;
function stack.empty:boolean;
begin
  exit(size<>0);
end;