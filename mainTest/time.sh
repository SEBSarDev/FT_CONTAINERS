#!/bin/bash

clang++ -Wall -Werror -Wextra -std=c++98 ./mainTest/oriTimeVector.cpp -o oriTime
clang++ -Wall -Werror -Wextra -std=c++98 ./mainTest/mineTimeVector.cpp -o myTime

/usr/bin/time --format='vector personnel dure %e seconde' ./myTime > /dev/null
/usr/bin/time --format='vector originel dure %e seconde' ./oriTime > /dev/null

echo ' '
clang++ -Wall -Werror -Wextra -std=c++98 ./mainTest/oriTimeMap.cpp -o oriTime
clang++ -Wall -Werror -Wextra -std=c++98 ./mainTest/mineTimeMap.cpp -o myTime
/usr/bin/time --format='map personnelle dure %e seconde' ./myTime > /dev/null
/usr/bin/time --format='map originelle dure %e seconde' ./oriTime > /dev/null

echo ' '
clang++ -Wall -Werror -Wextra -std=c++98 ./mainTest/oriTimeStack.cpp -o oriTime
clang++ -Wall -Werror -Wextra -std=c++98 ./mainTest/mineTimeStack.cpp -o myTime
/usr/bin/time --format='stack personnelle dure %e seconde' ./myTime > /dev/null
/usr/bin/time --format='stack originelle dure %e seconde' ./oriTime > /dev/null

rm myTime oriTime
