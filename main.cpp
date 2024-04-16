#include <iostream>
#include <vector>

struct Process {
    int id;
    int size;
    bool allocated;
};

void bestFit(std::vector<Process>& processes, std::vector<int>& blocks) {
    for (int i = 0; i < processes.size(); i++) {
        int bestFitIndex = -1;
        for (int j = 0; j < blocks.size(); j++) {
            if (blocks[j] >= processes[i].size && (bestFitIndex == -1 || blocks[j] < blocks[bestFitIndex])) {
                bestFitIndex = j;
            }
        }
        if (bestFitIndex != -1) {
            blocks[bestFitIndex] -= processes[i].size;
            processes[i].allocated = true;
        }
    }
}

int main() {
    int numProcesses, numBlocks;
    std::cout << "Enter the number of processes: ";
    std::cin >> numProcesses;
    std::cout << "Enter the number of memory blocks: ";
    std::cin >> numBlocks;

    std::vector<Process> processes(numProcesses);
    std::vector<int> blocks(numBlocks);

    for (int i = 0; i < numProcesses; i++) {
        std::cout << "Enter the size of process " << i + 1 << ": ";
        std::cin >> processes[i].size;
        processes[i].id = i + 1;
        processes[i].allocated = false;
    }

    for (int i = 0; i < numBlocks; i++) {
        std::cout << "Enter the size of memory block " << i + 1 << ": ";
        std::cin >> blocks[i];
    }

    bestFit(processes, blocks);

    std::cout << "Process\tBlock\tAllocated\n";
    for (const auto& process : processes) {
        std::cout << process.id << "\t";
        if (process.allocated) {
            std::cout << "Block " << process.id << "\tYes\n";
        } else {
            std::cout << "N/A\tNo\n";
        }
    }

    return 0;
}