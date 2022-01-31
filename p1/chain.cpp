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
    //string textfile = "file";  THIS MIGHT BE HANDLED BY THE KERNEL



    ifstream helper("help");

    while ((option = getopt(argc, argv, "hp:c:s:i:")) != -1) {
        switch (option)
        {
        case 'h':
            if (helper.is_open())
                cout << helper.rdbuf();
            helper.close();
            return 0;

        case 'p':
            nprocs = atoi(optarg);
            break;

        case 'c':
            nchars = atoi(optarg);
            break;

        case 's':
            sleeptime = atoi(optarg);
            break;

        case 'i':
            niters = atoi(optarg);
            break;

        default:
            break;
        }
    }

    helper.close();
    cout << programName << endl;
    processor(nprocs, sleeptime);



    return 0;
}