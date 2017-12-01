#ifndef MAPREDUCE_V2_MAPREDUCEOPERATION_H
#define MAPREDUCE_V2_MAPREDUCEOPERATION_H

#include <stdbool.h>

/**
 * The available states of processing for a specific file
 */
enum OperationTag {
    GetWords,
    DirectIndex,
    ReverseIndex,
    Available,
    InProgress,
    Done
};

#define ROOT 0
#define TASK_ACK 101
#define TASK_INDEX_FILE 102
#define TASK_PROCESS_WORDS 103
#define TASK_REVERSE_INDEX_FILE 104
#define TASK_KILL 999

/**
 * Struct to hold the name of the file that is processed,
 * The node that did the last processing,
 * And the last operation that was successfully completed
 */
struct Operation {
    char * filename;
    enum OperationTag lastOperation;
    enum OperationTag currentOperation;
};

bool doableOperations(struct Operation * operations, int numberOfOperations);

struct Operation * getNextOperation(struct Operation * operations, int numberOfOperations);

void changeOperationCurrentStatusByName(struct Operation *operations, int numberOfOperations, char *operationName,
                                        enum OperationTag currentStatus);

void changeOperationLastStatusByName(struct Operation *operations, int numberOfOperations, char *operationName,
                                        enum OperationTag lastStatus);

int getNextTaskForTag(enum OperationTag lastTag);

#endif
