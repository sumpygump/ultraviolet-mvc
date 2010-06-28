CXX        = g++
DEBUG_FLAG = -g
EXEC       = ${CXX} ${DEBUG_FLAG}
RM         = rm -f

VPATH     = ../lib/uv/cgi
CGI_PATH  = ../lib/uv/cgi
CORE_PATH = ../lib/uv/core
WEB_PATH  = ../web

PROGRAM     = index.cgi
CGI_OPTION  = -I${CGI_PATH}
CORE_OPTION = -I${CORE_PATH}

APP_OBJECTS  = index.o
CGI_OBJECTS  = Input.o Environment.o Cookie.o CookieJar.o Url.o Request.o Post.o Headers.o File.o Info.o
CORE_OBJECTS = Random.o Strlib.o
MVC_OBJECTS  = 

application : ${APP_OBJECTS} ${CGI_OBJECTS} ${CORE_OBJECTS} index
	cp index.cgi ../web/index.cgi

index : ${APP_OBJECTS} ${CGI_OBJECTS} ${CORE_OBJECTS}
	${EXEC} -o ${PROGRAM} ${APP_OBJECTS} ${CGI_OBJECTS} ${CORE_OBJECTS}
	cp index.cgi ../web/index.cgi

all : clean index

cgi : ${CGI_OBJECTS}

core : ${CORE_OBJECTS}

mvc : ${MVC_OBJECTS}

index.o : index.cpp
	${EXEC} ${CGI_OPTION} -c index.cpp

File.o : File.cpp File.h
	${EXEC} ${CGI_OPTION} -c ${CGI_PATH}/File.cpp

Headers.o : Headers.cpp Headers.h
	${EXEC} ${CGI_OPTION} -c ${CGI_PATH}/Headers.cpp

Input.o : Input.cpp Input.h
	${EXEC} ${CGI_OPTION} -c ${CGI_PATH}/Input.cpp

Post.o : Post.cpp Post.h
	${EXEC} ${CGI_OPTION} -c ${CGI_PATH}/Post.cpp

Request.o : Request.cpp Request.h
	${EXEC} ${CGI_OPTION} -c ${CGI_PATH}/Request.cpp

Url.o : Url.cpp Url.h
	${EXEC} ${CGI_OPTION} -c ${CGI_PATH}/Url.cpp

Cookie.o : Cookie.cpp Cookie.h
	${EXEC} ${CGI_OPTION} -c ${CGI_PATH}/Cookie.cpp

CookieJar.o : CookieJar.cpp CookieJar.h
	${EXEC} ${CGI_OPTION} -c ${CGI_PATH}/CookieJar.cpp

Environment.o : Environment.cpp Environment.h
	${EXEC} ${CGI_OPTION} -c ${CGI_PATH}/Environment.cpp

Info.o : Info.cpp Info.h
	${EXEC} ${CGI_OPTION} -c ${CGI_PATH}/Info.cpp

Random.o : ${CORE_PATH}/Random.cpp ${CORE_PATH}/Random.h
	${EXEC} ${CORE_OPTION} -c ${CORE_PATH}/Random.cpp

Strlib.o : ${CORE_PATH}/Strlib.cpp ${CORE_PATH}/Strlib.h
	${EXEC} ${CORE_OPTION} -c ${CORE_PATH}/Strlib.cpp

clean-app:
	${RM} ${APP_OBJECTS} ${PROGRAM}

clean-cgi:
	${RM} ${CGI_OBJECTS}

clean-core:
	${RM} ${CORE_OBJECTS}

clean-mvc:
	${RM} ${MVC_OBJECTS}

clean-web:
	${RM} ${WEB_PATH}/${PROGRAM}

clean: clean-app clean-cgi clean-web clean-core
