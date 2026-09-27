all: a3 a3test

objects = main.o Control.o View.o Lab.o Entity.o LabWorkList.o LabWork.o LabTech.o Patient.o Tester.o
testobjects = test.o TestControl.o  View.o Lab.o Entity.o LabWorkList.o LabWork.o LabTech.o Patient.o Tester.o


a3: $(objects)
	g++ -o a3 $(objects) 

a3test: $(testobjects) 
	g++ -o a3test $(testobjects) 

main.o: main.cc Control.h 
	g++ -c main.cc 

test.o: test.cc TestControl.h
	g++ -c test.cc

Control.o: Control.h Control.cc
	g++ -c Control.cc

TestControl.o: TestControl.cc TestControl.h
	g++ -c TestControl.cc
	
View.o: View.cc View.h
	g++ -c View.cc
	
Lab.o: Lab.cc Lab.h Patient.h LabTech.h
	g++ -c Lab.cc

Entity.o: Entity.cc Entity.h
	g++ -c Entity.cc


LabWorkList.o: LabWorkList.h LabWorkList.cc
	g++ -c LabWorkList.cc

LabWork.o: LabWork.h LabWork.cc
	g++ -c LabWork.cc

	
LabTech.o: LabTech.cc LabTech.h Entity.h  LabWorkList.h
	g++ -c LabTech.cc 

Patient.o: Patient.cc Patient.h Entity.h LabWorkList.h
	g++ -c Patient.cc

Tester.o: Tester.cc Tester.h
	g++ -c Tester.cc
	

clean:
	rm -f a3 a3test *.o