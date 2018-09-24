CC     = gcc
SOURCE = sort.c sort.h
EXEC   = sort
RM     = rm -v

$(EXEC): $(SOURCE)
	@$(CC) $(SOURCE) -o $(EXEC)
	@./$(EXEC)

run:
	@./$(EXEC)

clean:
	$(RM) $(EXEC)
