CCFLAGS=gcc
TESTBARRIERNAME=testbarrier
TESTSEMAPHORENAME=testsemaphore
TESTMONITORNAME=testmonitor
TESTBARRIERNAMEDLL=testbarrierdll
TESTSEMAPHORENAMEDLL=testsemaphoredll
TESTMONITORNAMEDLL=testmonitordll

libsynclib.so: synclib.c synclib.h
	$(CCFLAGS) -fPIC -shared -o $@ synclib.c -lc

testbarrierDLL: libsynclib.so
	$(CCFLAGS) -o $(TESTBARRIERNAMEDLL) testbarriersync.c -L. -lsynclib

testsemaphoreDLL: libsynclib.so
	$(CCFLAGS) -o $(TESTSEMAPHORENAMEDLL) testsemaphore.c -L. -lsynclib

testmonitorDLL: libsynclib.so
	$(CCFLAGS) -o $(TESTMONITORNAMEDLL) testmonitor.c -L. -lsynclib

synclib.o: synclib.c synclib.h
	$(CCFLAGS) -c synclib.c

testbarrier: synclib.o
	$(CCFLAGS) -o $(TESTBARRIERNAME) testbarriersync.c synclib.o

testsemaphore: synclib.o
	$(CCFLAGS) -o $(TESTSEMAPHORENAME) testsemaphore.c synclib.o

testmonitor: synclib.o
	$(CCFLAGS) -o $(TESTMONITORNAME) testmonitor.c synclib.o

compilealltests: testbarrierDLL testsemaphoreDLL testmonitorDLL testbarrier testsemaphore testmonitor

clearbarriertest:
	rm ${TESTBARRIERNAME}

clearsemaphoretest:
	rm ${TESTSEMAPHORENAME}

clearmonitortest:
	rm ${TESTMONITORNAME}

clearsemaphoredll:
	rm ${TESTSEMAPHORENAMEDLL}

clearbarrierdll:
	rm ${TESTBARRIERNAMEDLL}

clearmonitordll:
	rm ${TESTMONITORNAMEDLL}


clearlib:
	rm synclib.o

cleardll:
	rm libsynclib.so

clearalltests: clearbarriertest clearsemaphoretest clearbarrierdll clearsemaphoredll clearmonitordll clearmonitortest

clearall: clearalltests clearlib cleardll