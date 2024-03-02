#Auteurs : PEGOURIE Benjamin / RABE Iarimbola
#Date de création : 23/02/2024
# make : Crée l'exécutable saage
#./saage pour executer


CC = clang
CFLAGS = -std=c17 -pedantic -Wall
EXEC = saage
OBJ = main.o greffe.o arbres_binaires.o serialise.o

default: $(EXEC)


$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ 

main.o: main.c arbres_binaires.h greffe.h

greffe.o : greffe.c greffe.h arbres_binaires.h

arbres_binaires.o : arbres_binaires.c arbres_binaires.h

saage.o : saage.c saage.h arbres_binaires.h

%.o: %.c 
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(EXEC)
	./$(EXEC)

clean:
	-rm -f $(OBJ)
	-rm -f $(EXEC)



