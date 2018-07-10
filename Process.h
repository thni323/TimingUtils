#ifndef PROCESS_H
#define PROCESS_H

#include <LinkedList.h>

class Process {
    public:
        Process();
        virtual ~Process();
        static void init();
        static void process();

    protected:
        virtual void onInit() = 0;
        virtual void onProcess() = 0;

    private:
        static LinkedList<Process*> processList;

};

#endif