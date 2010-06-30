CXX        = g++
DEBUG_FLAG = -g
EXEC       = ${CXX} ${DEBUG_FLAG}
RM         = rm -f

UV_PATH = ../lib/uv

CGI_PATH  = ${UV_PATH}/cgi
CORE_PATH = ${UV_PATH}/core
VIEW_PATH = ${UV_PATH}/view

VPATH     = ${CGI_PATH}:${CORE_PATH}:${VIEW_PATH}

WEB_PATH  = ../web

PROGRAM     = index.cgi
INCLUDE_PATH = -I${UV_PATH}

APP_OBJECTS  = index.o
CGI_OBJECTS  = Input.o Environment.o Cookie.o CookieJar.o Url.o Request.o Post.o Headers.o File.o Info.o
CORE_OBJECTS = Random.o Strlib.o
VIEW_OBJECTS = InternalChrome.o
MVC_OBJECTS  = 

application : index
	cp index.cgi ../web/index.cgi

index : ${APP_OBJECTS} ${CGI_OBJECTS} ${CORE_OBJECTS} ${VIEW_OBJECTS}
	${EXEC} -o ${PROGRAM} ${APP_OBJECTS} ${CGI_OBJECTS} ${CORE_OBJECTS} ${VIEW_OBJECTS}

all : clean index

cgi : ${CGI_OBJECTS}

core : ${CORE_OBJECTS}

view : ${VIEW_OBJECTS}

mvc : ${MVC_OBJECTS}

index.o : index.cpp
	${EXEC} ${INCLUDE_PATH} -c index.cpp

File.o : File.cpp File.h
	${EXEC} ${INCLUDE_PATH} -c ${CGI_PATH}/File.cpp

Headers.o : Headers.cpp Headers.h
	${EXEC} ${INCLUDE_PATH} -c ${CGI_PATH}/Headers.cpp

Input.o : Input.cpp Input.h
	${EXEC} ${INCLUDE_PATH} -c ${CGI_PATH}/Input.cpp

Post.o : Post.cpp Post.h
	${EXEC} ${INCLUDE_PATH} -c ${CGI_PATH}/Post.cpp

Request.o : Request.cpp Request.h
	${EXEC} ${INCLUDE_PATH} -c ${CGI_PATH}/Request.cpp

Url.o : Url.cpp Url.h
	${EXEC} ${INCLUDE_PATH} -c ${CGI_PATH}/Url.cpp

Cookie.o : Cookie.cpp Cookie.h
	${EXEC} ${INCLUDE_PATH} -c ${CGI_PATH}/Cookie.cpp

CookieJar.o : CookieJar.cpp CookieJar.h
	${EXEC} ${INCLUDE_PATH} -c ${CGI_PATH}/CookieJar.cpp

Environment.o : Environment.cpp Environment.h
	${EXEC} ${INCLUDE_PATH} -c ${CGI_PATH}/Environment.cpp

Info.o : Info.cpp Info.h
	${EXEC} ${INCLUDE_PATH} -c ${CGI_PATH}/Info.cpp

Random.o : Random.cpp Random.h
	${EXEC} ${INCLUDE_PATH} -c ${CORE_PATH}/Random.cpp

Strlib.o : Strlib.cpp Strlib.h
	${EXEC} ${INCLUDE_PATH} -c ${CORE_PATH}/Strlib.cpp

InternalChrome.o : InternalChrome.cpp InternalChrome.h
	${EXEC} ${INCLUDE_PATH} -c ${VIEW_PATH}/InternalChrome.cpp

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
