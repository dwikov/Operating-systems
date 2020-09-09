
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	for(int i = 0; i < 5; i++){
		fork();
	}
	sleep(5);
}
/*
I got the following output for 3:
        ├─gnome-terminal-─┬─bash─┬─a.out─┬─a.out─┬─a.out───a.out
        │         │      │       │       │       └─a.out
        │         │      │       │       ├─a.out───a.out
        │         │      │       │       └─a.out
        │         │      │       └─pstree
        │         │      └─4*[{gnome-terminal-}]

so there're 8 process, the first one forked to 2, 1, 0 and each of them forked out like this:
	3 -> 2 -> 1 -> 0
	       -> 0
     	  -> 1 -> 0
     	  -> 0
for 5 the number of process increased a lot.
*/
