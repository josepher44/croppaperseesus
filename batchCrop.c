#include <stdio.h>
#include <stdlib.h>
#include "grades.h"
#define IMAGE_WIDTH (1920)
#define IMAGE_HEIGHT (1080)
/*
 * Program which takes an arbitrary series of images, and crops out regions
 * which do not closely match a given "control" background, to highlight regions
 * of interest with the minimum size possible, regardless of their scale or
 * positioning relative to the background. Some noise tolerance in the
 * background is tolerated by using weighted averaging which increases in
 * tolerance away from regions of interest
 * Author: Joe Gallagher
 * joedgallagher@wpi.edu
 * Last modified: 5/19/2018
 */
int main (int argc, const char* argv[])
{
    // Declare variables
    int all_grades[MAX_GRADES]; // Array to store all input arguments
    int grade_count; // Number of grades to be processed
    int i; // Loop incrementor

    if(argc != 2)
    {
        printf("Usage: ./batchCrop \"<path>\"\n");
        return 1;
    }

    struct dirent *de;
    DIR *dir = opendir(argv[1]);
    if(!dir)
    {
        printf("opendir() failed! Does it exist?\n");
        return 1;
    }

    unsigned long count=0;
        while(de = readdir(dir))
     {
          ++count;
     }

    closedir(dir);
    printf("%lu\n", count);

    return 0;
}
