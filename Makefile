CCFLAGS=gcc
TESTBARRIERNAME=testbarrier
TESTSEMAPHORENAME=testsemaphore
TESTBARRIERNAMEDLL=testbarrierdll
TESTSEMAPHORENAMEDLL=testsemaphoredll

libsynclib.so: synclib.c synclib.h
	$(CCFLAGS) -fPIC -shared -o $@ synclib.c -lc

testbarrierDLL: libsynclib.so
	$(CCFLAGS) -o $(TESTBARRIERNAMEDLL) testbarriersync.c -L. -lsynclib

testsemaphoreDLL: libsynclib.so
	$(CCFLAGS) -o $(TESTSEMAPHORENAMEDLL) testsemaphore.c -L. -lsynclib

synclib.o: synclib.c synclib.h
	$(CCFLAGS) -c synclib.c

testbarrier: synclib.o
	$(CCFLAGS) -o $(TESTBARRIERNAME) testbarriersync.c synclib.o

testsemaphore: synclib.o
	$(CCFLAGS) -o $(TESTSEMAPHORENAME) testsemaphore.c synclib.o

compilealltests: testbarrierDLL testsemaphoreDLL testbarrier testsemaphore

clearbarriertest:
	rm ${TESTBARRIERNAME}

clearsemaphoretest:
	rm ${TESTSEMAPHORENAME}

clearsemaphoredll:
	rm ${TESTSEMAPHORENAMEDLL}

clearbarrierdll:
	rm ${TESTBARRIERNAMEDLL}

clearlib:
	rm synclib.o

cleardll:
	rm libsynclib.so

clearalltests: clearbarriertest clearsemaphoretest clearbarrierdll clearsemaphoredll

clearall: clearalltests clearlib cleardll