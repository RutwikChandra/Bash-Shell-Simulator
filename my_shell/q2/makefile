all:	main.o fn_ls.o fn_cp.o fn_sort.o fn_mv.o fn_grep.o fn_add_clr.o fn_ps.o	 
	gcc main.o -lreadline fn_ls.o fn_cp.o fn_sort.o fn_mv.o fn_grep.o fn_add_clr.o fn_ps.o -o out.o
     
main.o:	main.c
	gcc -c main.c -lreadline -o main.o
       
fn_sort.o:	fn_sort.c
	gcc -c fn_sort.c -o fn_sort.o

fn_ls.o:	fn_ls.c
	gcc -c fn_ls.c -o fn_ls.o
	
fn_cp.o:	fn_cp.c	
	gcc -c fn_cp.c -o fn_cp.o
	
fn_mv.o:	fn_mv.c
	gcc -c fn_mv.c -o fn_mv.o	
	
fn_grep.o:	fn_grep.c
	gcc -c 	fn_grep.c -o fn_grep.o
	
fn_add_clr.o:	fn_add_clr.c	
	gcc -c 	fn_add_clr.c -o fn_add_clr.o
	
fn_ps.o:	fn_ps.c
	gcc -c fn_ps.c -o fn_ps.o	
