# ifndef MAINMEMORY_H
# define MAINMEMORY_H

# include "defs.h"
# include <vector>

/* Classes which represents the main memory. Here we have an AddressDecoder,
which job is to select the appropriate memory chip based on its address,
a MemoryChip class, which is, of course, a memory chip which stores one word,
and each chip is composed of MemoryCells, each one storing one bit. */

// Forward Declarations
class ControlUnit;
class MemoryChip;
class AddressDecoder;
class MainMemory;

class MemoryCell {
    friend MemoryChip;
private:
    bool WR, CS;
    bit data;
};

class MemoryChip {
    friend AddressDecoder;
    friend MainMemory;
private:
    bool WR, CS;
    std::vector<MemoryCell> cells;

private:
    std::vector<bit> readData() const;
    void writeData(const std::vector<bit> &data);
};

class AddressDecoder {
public:
    void decode(const std::vector<bit> &address, std::vector<MemoryChip> &chips);
};

class MainMemory {
    friend ControlUnit;
public:
    // Buses input/outputs
    std::vector<bit> address;
    std::vector<bit> writeData;
    std::vector<bit> readData;

private: // Will be made private when control unit is done

    // Control lines
    bool memWrite, memRead;

    // Components
    AddressDecoder decoder;
    std::vector<MemoryChip> memChips;

    int size, chipsNum, addrLinesNum;

public:
    MainMemory(const int size); // Size in bits
    void process();
};

# endif /* end of include guard: MAINMEMORY_H */
