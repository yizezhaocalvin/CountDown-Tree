fp:	main.o Control.o ReportGenerator.o Record.o View.o RegionReportGenerator.o FemaleReportGenerator.o YearReportGenerator.o UnemploymentReportGenerator.o GradsReportGenerator.o
	g++ -o fp main.o Control.o ReportGenerator.o Record.o View.o RegionReportGenerator.o FemaleReportGenerator.o YearReportGenerator.o UnemploymentReportGenerator.o GradsReportGenerator.o

main.o:	main.cc Control.h
	g++ -c main.cc

Control.o: Control.cc Control.h ReportGenerator.h Property.h Record.h
	g++ -c Control.cc

Record.o: Record.cc Record.h
	g++ -c Record.cc

ReportGenerator.o: ReportGenerator.cc ReportGenerator.h Record.h Property.h
	g++ -c ReportGenerator.cc

View.o: View.cc View.h
	g++ -c View.cc

RegionReportGenerator.cc: ReportGenerator.h
	g++ -c RegionReportGenerator.cc

FemaleReportGenerator.cc: ReportGenerator.h
	g++ -c FemaleReportGenerator.cc

YearReportGenerator.cc: ReportGenerator.h
	g++ -c YearReportGenerator.cc

UnemploymentReportGenerator.cc: ReportGenerator.h
	g++ -c UnemploymentReportGenerator.cc

GradsReportGenerator.cc: ReportGenerator.h
	g++ -c GradsReportGenerator.cc

clean:
	rm -f *.o fp
