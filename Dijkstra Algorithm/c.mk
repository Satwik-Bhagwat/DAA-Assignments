a.out:PES1UG19CS438_C.o PES1UG19CS438_F.o
	gcc PES1UG19CS438_C.c PES1UG19CS438_F.c
PES1UG19CS438_C.o:PES1UG19CS438_C.c PES1UG19CS438_H.h
	gcc -c PES1UG19CS438_C.c
PES1UG19CS438_F.o:PES1UG19CS438_F.c PES1UG19CS438_H.h
	gcc -c PES1UG19CS438_F.c
