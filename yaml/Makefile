CC := g++ -std=c++11
FLAG := -Wall
YAML_HEADER := /usr/local/include/yaml-cpp
YAML_LIB := /usr/local/lib/yaml-cpp

SRCDIR := ./src
INCDIR := ./include
OBJDIR := ./obj
TARGET := ./bin

all: main.o session.o broker_info.o $(INCDIR)/session.h $(INCDIR)/broker_info.h
	$(CC) $(FLAG) -o $(TARGET)/main $(OBJDIR)/main.o $(OBJDIR)/session.o $(OBJDIR)/broker_info.o $(INCDIR)/session.h $(INCDIR)/broker_info.h -I$(YAML_HEADER) -L$(YAML_LIB) -lyaml-cpp

main.o: $(SRCDIR)/main.cpp /usr/local/include/yaml-cpp
	$(CC) -c $(SRCDIR)/main.cpp -I$(YAML_HEADER)
	mv main.o $(OBJDIR)

session.o: $(SRCDIR)/session.cpp
	$(CC) -c $(SRCDIR)/session.cpp
	mv session.o $(OBJDIR)

broker_info.o: $(SRCDIR)/broker_info.cpp
	$(CC) -c $(SRCDIR)/broker_info.cpp
	mv broker_info.o $(OBJDIR)

exec:
	`pwd`/bin/main `pwd`/conf

.PHONY: clean
clean:
	rm -rf $(OBJDIR)/*.o $(TARGET)/main
