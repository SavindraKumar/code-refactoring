// messy_monitor.cpp
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <cstring>

// Global configuration / magic numbers
int SPO2_ALARM = 90;
int TEMP_ALARM = 38;
int SAMPLE_MS = 1000;

// Simple C-style logger that opens file every time
void writeLog(const char* filename, const char* message) {
    FILE* f = fopen(filename, "a");
    if (f) {
        fprintf(f, "%s\n", message);
        fclose(f);
    }
}

// A very C-like Patient object using manual allocation
struct Patient {
    char* id;
    char* name;
    int age;
    Patient(const char* pid, const char* pname, int page) {
        id = (char*)malloc(strlen(pid) + 1);
        strcpy(id, pid);
        name = (char*)malloc(strlen(pname) + 1);
        strcpy(name, pname);
        age = page;
    }
    ~Patient() {
        free(id);
        free(name);
    }
};

// "Sensor" read function: uses rand and writes into pointers
void readSensors(int* spo2, double* temp) {
    *spo2 = rand() % 20 + 85;            // 85..104
    *temp = (rand() % 400) / 10.0 + 35; // 35.0 .. 74.0 (nonsense range)
}

// Mixed printing + alarm handling + logging in one function
void checkAndHandle(int spo2, double temp, Patient* p) {
    if (spo2 < SPO2_ALARM) {
        std::cout << "Alarm: Low SpO2 for " << p->name << " : " << spo2 << "\n";
        char buf[256];
        sprintf(buf, "ALARM LOW SPO2 patient=%s value=%d", p->id, spo2);
        writeLog("monitor.log", buf);
    }

    if (temp > TEMP_ALARM) {
        std::cout << "Alarm: High Temp for " << p->name << " : " << temp << "\n";
        char buf[256];
        sprintf(buf, "ALARM HIGH TEMP patient=%s value=%.1f", p->id, temp);
        writeLog("monitor.log", buf);
    }
}

// Status printing duplicates log messages
void printStatus(Patient* p, int spo2, double temp) {
    std::cout << "Patient " << p->name << " Age:" << p->age << "\n";
    std::cout << "SpO2=" << spo2 << "% Temp=" << temp << "C\n";
}

// main: allocates a patient via new, loops with blocking sleep and duplicates escalation logic
int main() {
    srand((unsigned)time(nullptr));
    Patient* patient = new Patient("P123", "Alice", 45);

    writeLog("monitor.log", "Monitor started");

    for (int i = 0; i < 20; ++i) {
        int spo2;
        double temp;
        readSensors(&spo2, &temp);

        // display
        printStatus(patient, spo2, temp);

        // check alarms and log
        checkAndHandle(spo2, temp, patient);

        // duplicated escalation logic
        if (spo2 < 80) {
            std::cout << "CRITICAL: escalate for patient " << patient->name << "\n";
            char buf[256];
            sprintf(buf, "CRITICAL patient=%s spo2=%d", patient->id, spo2);
            writeLog("monitor.log", buf);
            writeLog("server.log", buf); // simulate remote
        }

    }

    delete patient;
    writeLog("monitor.log", "Monitor stopped");
    return 0;
}

