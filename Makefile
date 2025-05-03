CXX = c++
CXXFLAGS =  -Wall -Wextra -Werror #-std=c++98  #-g3
RM = rm -rf
CXXFILES = main.cpp
OFILES = ${CXXFILES:.cpp=.o}
NAME = Fixed

all : ${NAME}

${NAME} : ${OFILES}
		${CXX} ${CXXFLAGS} ${OFILES} -o ${NAME}

%.o : %.cpp
	${CXX} -c ${CXXFLAGS}  $^ -o $@

clean :
	${RM} ${OFILES}

fclean : clean
	${RM} ${NAME}

re : fclean all