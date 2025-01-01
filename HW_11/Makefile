all: report

report: report.o sensor.o temp_api.o
	gcc -o report report.o sensor.o temp_api.o

report.o: report.c
	gcc -c -o report.o report.c

sensor.o: sensor.c
	gcc -c -o sensor.o sensor.c

temp_api.o: temp_api.c
	gcc -c -o temp_api.o temp_api.c

clean:
	rm *.o
	rm report.exe
	