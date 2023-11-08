
// JMR, 2021

// Complete the functions (marked by ...)
// so that it passes all tests in PersonTest.

#include "Person.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Person.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int lastID = 0;

Person *PersonCreate(const char *fname, const char *lname, int yy, int mm, int dd) {
  Person *p = (Person *)malloc(sizeof(Person));
  if (p == NULL) {
    return NULL; // Alocação de memória falhou.
  }

  // Atribui um ID único à pessoa.
  lastID++;
  p->id = lastID;

  // Aloca memória para os nomes e copia-os.
  p->firstName = strdup(fname);
  p->lastName = strdup(lname);

  // Define a data de nascimento da pessoa.
  p->birthDate.year = yy;
  p->birthDate.month = mm;
  p->birthDate.day = dd;

  return p;
}

void PersonDestroy(Person **pp) {
  assert(*pp != NULL);

  free((*pp)->firstName);
  free((*pp)->lastName);
  free(*pp);
  *pp = NULL;
}

void PersonPrintf(Person *p, const char *suffix) {
  if (p == NULL)
    printf("NULL%s", suffix);
  else
    printf("(%d, %s, %s, %s)%s", p->id, p->lastName, p->firstName,
           DateFormat(&(p->birthDate), YMD), suffix);
}

int PersonCompareByBirth(const Person *p1, const Person *p2) {
  if (p1->birthDate.year != p2->birthDate.year) {
    return p1->birthDate.year - p2->birthDate.year;
  }
  if (p1->birthDate.month != p2->birthDate.month) {
    return p1->birthDate.month - p2->birthDate.month;
  }
  return p1->birthDate.day - p2->birthDate.day;
}

int PersonCompareByLastFirstName(const Person *p1, const Person *p2) {
  int lastNameComparison = strcmp(p1->lastName, p2->lastName);
  if (lastNameComparison != 0) {
    return lastNameComparison;
  }

  return strcmp(p1->firstName, p2->firstName);
}

