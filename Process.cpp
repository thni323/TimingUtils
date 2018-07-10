#include "Process.h"

LinkedList<Process*> Process::processList = {};

Process::Process() {
    processList.add(this);
}

Process::~Process() {
    for (int i=0; i < processList.size(); i++) {
        if (processList.get(i) == this) {
            processList.remove(i);
            break;
        }
    }
}

void Process::init() {
    for (int i=0; i < processList.size(); i++) {
        processList.get(i)->onInit();
    }
}

void Process::process() {
    for (int i=0; i < processList.size(); i++) {
        processList.get(i)->onProcess();
    }
}