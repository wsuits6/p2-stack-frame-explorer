#include <stdio.h>//Inlcude the standard I/O library
#include <stdint.h>//Inlcude the interger Definitions library the  <stdint.h> provides fixed  width integer types

//Stack frame  inspecter  function 
// Restrict this function to this code file alone and also this funtion is not going to  return any value  and its going to recieve  info through the name param
static void inspect_frame(const char *name) {
    // use the inbuilt GCC argument to request the frame stack frame Address
    // convert the  recieved stack frame Address into a Pointer to Pointer type
    //fp is a variable whose type is void **. It stores the address of a pointer-sized stack slot, allowing us to interpret successive slots as pointers.
    // to store the actual address
    void **fp = (void **)__builtin_frame_address(0); 
    //Print the function Name to the console
    printf("[%s]\n", name); //%s tell the printf function to print a string
    //Print the frame address
    printf(" Frame Pointer (RBP): %p\n", (void *)fp); // %p is the format specifier for printing out a pointer in Printf() , we cast the void * becuase the  %p expects a void *  sooo our fp must be cast to void * not void  **
    //inspect the saced RBP
    printf(" Saved RBP:            %p\n", fp[0]); //Print out the x86-64 stack frame Base Pointer
    //Inspect thge Return address
    printf(" Return Address:       %p\n", fp[1]);
    //when a Function calls another function using the X86-64 CALL instruction  (ASM) the CPU sacs the return address on the stack


} //close the function 
 

//creating the main function to call the Inspect frame  function
int main(void) {
    inspect_frame("main -> inspect_frame");
    return 0;
}