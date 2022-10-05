MYNAMEV = MineVector
ORINAMEV = OriginalVector
MYNAMEM = MineMap
ORINAMEM = OriginalMap
MYNAMES = MineStack
ORINAMES = OriginalStack
MYNAMEF = MineFt
ORINAMEF = OriginalFt
CC = clang++
FLAG = -Wall -Werror -Wextra -std=c++98

MYSRCSV = mainTest/myMainVector.cpp
MYOBJSV = $(MYSRCSV:.cpp=.o)
ORISRCSV = mainTest/originalMainVector.cpp
ORIOBJSV = $(ORISRCSV:.cpp=.o)
$(MYNAMEV) : $(MYOBJSV) $(ORINAMEV)
	$(CC) $(FLAG) $(MYOBJSV) -I./ -o $(MYNAMEV)
$(ORINAMEV) : $(ORIOBJSV)
	$(CC) $(FLAG) $(ORIOBJSV) -I./ -o $(ORINAMEV)

MYSRCSM = mainTest/myMainMap.cpp
MYOBJSM = $(MYSRCSM:.cpp=.o)
ORISRCSM = mainTest/originalMainMap.cpp
ORIOBJSM = $(ORISRCSM:.cpp=.o)
$(MYNAMEM) : $(MYOBJSM) $(ORINAMEM)
	$(CC) $(FLAG) $(MYOBJSM) -I./ -o $(MYNAMEM)
$(ORINAMEM) : $(ORIOBJSM)
	$(CC) $(FLAG) $(ORIOBJSM) -I./ -o $(ORINAMEM)

MYSRCSS = mainTest/myMainStack.cpp
MYOBJSS = $(MYSRCSS:.cpp=.o)
ORISRCSS = mainTest/originalMainStack.cpp
ORIOBJSS = $(ORISRCSS:.cpp=.o)
$(MYNAMES) : $(MYOBJSS) $(ORINAMES)
	$(CC) $(FLAG) $(MYOBJSS) -I./ -o $(MYNAMES)
$(ORINAMES) : $(ORIOBJSS)
	$(CC) $(FLAG) $(ORIOBJSS) -I./ -o $(ORINAMES)

MYSRCSF = mainTest/myMainFt.cpp
MYOBJSF = $(MYSRCSF:.cpp=.o)
ORISRCSF = mainTest/originalMainFt.cpp
ORIOBJSF = $(ORISRCSF:.cpp=.o)
$(MYNAMEF) : $(MYOBJSF) $(ORINAMEF)
	$(CC) $(FLAG) $(MYOBJSF) -I./ -o $(MYNAMEF)
$(ORINAMEF) : $(ORIOBJSF)
	$(CC) $(FLAG) $(ORIOBJSF) -I./ -o $(ORINAMEF)

%.o : %.cpp
	$(CC) $(FLAG) -o $@ -c $<
vector : $(MYNAMEV) $(ORINAMEV)
	./MineVector >> myRes
	./OriginalVector >> originalRes
map : $(MYNAMEM) $(ORINAMEM)
	./MineMap >> myRes
	./OriginalMap >> originalRes
stack : $(MYNAMES) $(ORINAMES)
	./MineStack >> myRes
	./OriginalStack >> originalRes
ft : $(MYNAMEF) $(ORINAMEF)
	./MineFt >> myRes
	./OriginalFt >> originalRes
all : vector stack ft map
time :
	./mainTest/time.sh
clean : 
	rm -rf $(MYOBJSV)
	rm -rf $(ORIOBJSV)
	rm -rf $(MYOBJSM)
	rm -rf $(ORIOBJSM)
	rm -rf $(MYOBJSS)
	rm -rf $(ORIOBJSS)
	rm -rf $(MYOBJSF)
	rm -rf $(ORIOBJSF)
fclean : clean
	rm -rf $(MYNAMEV)
	rm -rf $(ORINAMEV)
	rm -rf $(MYNAMEM)
	rm -rf $(ORINAMEM)
	rm -rf $(MYNAMES)
	rm -rf $(ORINAMES)
	rm -rf $(MYNAMEF)
	rm -rf $(ORINAMEF)
	rm -rf originalRes
	rm -rf myRes
re : fclean all
.PHONY : all clean fclean re

