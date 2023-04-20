#pragma once

/*Error messages*/

static const char ERROR_ALLOCATION[] = "[ERROR] :: Cannot make allocation in the memory, sorry!";
static const char ERROR_NEW_ALLOCATION[] = "[ERROR] :: Cannot make a new allocation in the memory, sorry!";
static const char ERROR_PRINT_VALUE[] = "[ERROR] :: Cannot print this value, sorry!";
static const char ERROR_FULL_LIST [] = "[ERROR] :: Cannot Add new value, list is full!";
static const char ERROR_FULL_STACK [] = "[ERROR] :: Cannot Add new list, stack is full!";
static const char ERROR_POP [] = "[ERROR] :: Cannot Remove list, This element dosent exist!";
static const char ERROR_DOESNTEXIST[] = "[ERROR] :: Cannot find value, This element dosent exist!";


/*success messages*/
static const char S_ALLOCATION[] = "[SUCCESS] :: Allocation in memory was successfuly!";
static const char S_DELETE[] = "[SUCCESS] :: Value deleting was successfuly!";
static const char S_ADDED[] = "[SUCCESS] :: Values adding was successfuly!";
static const char S_ADDED_ONE[] = "[SUCCESS] :: Value adding was successfuly!";
static const char S_UPDATING[] = "[SUCCESS] :: Updating the stack was successfuly!";
static const char S_NEW_ALLOCATION[] = "[SUCCESS] :: A new allocation in the memory was successfuly!";
static const char S_PRINT_LIST[] = "[SUCCESS] :: Printing the list was successfuly!";
static const char S_PRINT_Stack [] = "[SUCCESS] :: Printing the stack was successfuly!";

#define sms(v) printf("%s\n", v);