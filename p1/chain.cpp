/*
Written by Michael Trani Jan 2022
CMP SCI 4760 Operating Systems
This program creates a chain of children processes and logs their PIDs.

*/

#include"chain.h"
using namespace std;

int main(int argc, char* argv[]){

    string programName = argv[0];
    programName.erase(0, 2);

    int option;     //getopt counter
    int nprocs = 4; // number of processes
    int nchars = 80; //number of characters read into the buffer
    int sleeptime = 3; //time to sleep in each iteration
    int niters = 1;     //number of iterations in the loop :double check for default
    string outfile = "output";  //THIS MIGHT BE HANDLED BY THE KERNEL

    ifstream helper(".help");

    while ((option = getopt(argc, argv, "hp:c:s:i:f:")) != -1) {
        switch (option)
        {
        case 'h':
            if (helper.is_open())
                cout << helper.rdbuf();
            helper.close();
            return 0;

        case 'p':
            nprocs = atoi(optarg);
            if (nprocs > 100 || nprocs < 1){
                cout << "Invalid process count.\n";
                return 1;
            }
            break;

        case 'c':
            nchars = atoi(optarg);
            cout << "NOTE: NOT USED SINCE WRITTEN IN C++\n";
            break;

        case 's':
            sleeptime = atoi(optarg);
            break;

        case 'i':
            niters = atoi(optarg);
            break;

        case 'f':
            outfile = optarg;
            break;

        default:
            break;
        }
    }

    helper.close();

    if (!(pFile = fopen(outfile.c_str(), "w"))){
        perror("chain: output file open error.");
        return 1;

    }
    processor(nprocs, sleeptime);

    return 0;
}