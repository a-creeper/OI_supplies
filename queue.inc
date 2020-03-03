type tqueuet=^tqueue;
     tqueue=record
               next:tqueuet;
               size:longint;
               v:longint;
             end;
     queue=object 
             private
               first:tqueuet;
               last:tqueuet;
               size:longint;
             public
               procedure init;
               procedure push(a:longint);
               function pop:longint;
               procedure top;
               function empty:boolean;
           end;
procedure queue.init;
begin
  new(first);
  last:=first;
  first^.next:=last;
  first^.v:=0;
  size:=0;
end;
procedure queue.push(a:longint);
var x:tqueuet;
begin
  last^.v:=a;
  new(last^.next);
  x:=last;
  last:=last^.next;
  last^.next:=last;
  inc(size);
end;
function queue.pop:longint;
begin
  exit(first^.v);
end;
procedure queue.top;
var x:tqueuet;
begin
  dec(size);
  x:=first;
  first:=first^.next;
  dispose(x);
end;
function queue.empty:boolean;
begin
  exit(size<>0);
end;