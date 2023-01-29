/* Name, hw2.c, CS 24000, Spring 2023
 * Last updated December 3, 2022
 */

/* Add any includes here */
// #include "hw2.h"
#include <stdio.h>
#include <string.h>

/* Define your functions here */

float average_speed_of_manufacturer(char *file_name, char *manufacturer) {
  FILE *fp = NULL;
  char buf[50] = "";

  fp = fopen(file_name, "r");
  if (fp == NULL) {
    return -1;
  }

  int count = 0;
  float total_distance = 0;
  float total_time = 0;

  while(fscanf(fp, "%[^,],", buf) == 1) {
    printf("a\n");

    count++;
    // printf("%s %d\n", "startCount: ", count);
    // printf("%d : %s\n", count, buf);

    printf("%s\n", buf);
    printf("b\n");
    printf("%i\n", count);

    if (count % 7 == 2 && (strcmp(buf, manufacturer) == 0)) { // manufacturer
      float temp;

      fscanf(fp, "%f", &temp); // read in distance
      count++;

      printf("%f\n", temp);
      printf("%d\n", count);

      total_distance += 1000 * temp;

      fscanf(fp, "%[^,], ", buf); // skip km
      fscanf(fp, "%f", &temp); // read in time
      count++;

      printf("%f\n", temp);
      printf("%d\n", count);

      total_time += temp;
    }

    printf("%s\n", buf);
    printf("%d\n", count);
  }

  float ret_value = total_distance / total_time;
  return ret_value;

  fclose(fp);
  fp = NULL;
}

float find_max_total_pitstop(char *file_name, char *manufacturer) {
  return 1;
}

int generate_expected_cost_report(char *in_file, char *out_file) {
  return 1;
}

int expected_pitstops(char *file_name, char *id) {
  return 1;
}

int main() {
  average_speed_of_manufacturer("Original_389", "Ford");
}


/* Remember, you don't need a main function!
 * It is provided by hw2_main.c or hw2_test.o
 */

