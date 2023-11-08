#include "PersonSet.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct _PersonSet_ {
  int capacity;
  int size;
  Person **array;
};

#define INITIAL_CAPACITY 4

PersonSet *PersonSetCreate() {
  // You must allocate space for the struct and for the array.
  // The array should be created with INITIAL_CAPACITY elements.
  // (The array will be reallocated if necessary when elements are appended.)
  // COMPLETE ...
  PersonSet *ps = (PersonSet *)malloc(sizeof(*ps));
  if (ps == NULL) {
    perror("PersonSetCreate");
    exit(2);
  }
  ps->capacity = INITIAL_CAPACITY;
  ps->size = 0;
  ps->array = (Person **)malloc(INITIAL_CAPACITY * sizeof(Person *));
  if (ps->array == NULL) {
    free(ps);
    perror("PersonSetCreate");
    exit(2);
  }

  return ps;
}

void PersonSetDestroy(PersonSet **pps) {
  assert(*pps != NULL);
  // You must free the array and the struct.
  // COMPLETE ...
  free((*pps)->array);
  free(*pps);
  *pps = NULL;
}

int PersonSetSize(const PersonSet *ps) {
  return ps->size;
}

int PersonSetIsEmpty(const PersonSet *ps) {
  return ps->size == 0;
}

void PersonSetPrint(const PersonSet *ps) {
  printf("{\n");
  for (int i = 0; i < ps->size; i++) {
    Person *p = ps->array[i];
    PersonPrintf(p, ";\n");
  }
  printf("}(size=%d, capacity=%d)\n", ps->size, ps->capacity);
}

static int search(const PersonSet *ps, int id) {
  // COMPLETE ...
  for (int i = 0; i < ps->size; i++) {
    if (ps->array[i]->id == id) {
      return i;
    }
  }
  return -1;
}

static void append(PersonSet *ps, Person *p) {
  // MODIFY the function so that if the array is full,
  // it uses realloc to double the array capacity!

  // COMPLETE ...
  if (ps->size == ps->capacity) {
    ps->capacity *= 2;
    Person **temp = (Person **)realloc(ps->array, ps->capacity * sizeof(Person *));
    if (temp == NULL) {
      free(ps->array);
      perror("append");
      exit(2);
    }
    ps->array = temp;
  }
  ps->array[ps->size] = p;
  ps->size++;
}

void PersonSetAdd(PersonSet *ps, Person *p) {
  // You may call the append function here!

  // COMPLETE ...
  if (search(ps, p->id) < 0) {
    append(ps, p);
  }
}

Person *PersonSetPop(PersonSet *ps) {
  assert(!PersonSetIsEmpty(ps));
  // It is easiest to pop and return the person in the last position!

  // COMPLETE ...
  Person *p = ps->array[ps->size - 1];
  ps->size--;

  return p;
}

Person *PersonSetRemove(PersonSet *ps, int id) {
  // You may call search here!

  // COMPLETE ...
  int index = search(ps, id);
  if (index >= 0) {
    Person *p = ps->array[index];
    ps->size--;
    for (int i = index; i < ps->size; i++) {
      ps->array[i] = ps->array[i + 1];
    }
    return p;
  } else {
    return NULL;
  }
}

Person *PersonSetGet(const PersonSet *ps, int id) {
  // You may call search here!

  // COMPLETE ...
  int index = search(ps, id);
  if (index >= 0) {
    return ps->array[index];
  } else {
    return NULL;
  }
  return NULL;
}

int PersonSetContains(const PersonSet *ps, int id) {
  return search(ps, id) >= 0;
}

PersonSet *PersonSetUnion(const PersonSet *ps1, const PersonSet *ps2) {
  PersonSet *ps = PersonSetCreate();

  // COMPLETE ...
  for (int i = 0; i < ps1->size; i++) {
    PersonSetAdd(ps, ps1->array[i]);
  }

  for (int i = 0; i < ps2->size; i++) {
    PersonSetAdd(ps, ps2->array[i]);
  }

  return ps;
}

PersonSet *PersonSetIntersection(const PersonSet *ps1, const PersonSet *ps2) {
  // COMPLETE ...
  PersonSet *ps = PersonSetCreate();
  for (int i = 0; i < ps1->size; i++) {
    if (PersonSetContains(ps2, ps1->array[i]->id)) {
      PersonSetAdd(ps, ps1->array[i]);
    }
  }

  return ps;
}

PersonSet *PersonSetDifference(const PersonSet *ps1, const PersonSet *ps2) {
  // COMPLETE ...
  PersonSet *ps = PersonSetCreate();
  for (int i = 0; i < ps1->size; i++) {
    if (!PersonSetContains(ps2, ps1->array[i]->id)) {
      PersonSetAdd(ps, ps1->array[i]);
    }
  }
  return ps;
}

int PersonSetIsSubset(const PersonSet *ps1, const PersonSet *ps2) {
  // COMPLETE ...
  for (int i = 0; i < ps1->size; i++) {
    if (!PersonSetContains(ps2, ps1->array[i]->id)) {
      return 0;
    }
  }

  return 1;
}

int PersonSetEquals(const PersonSet *ps1, const PersonSet *ps2) {
  // You may call PersonSetIsSubset here!

  // COMPLETE ...
  if (ps1->size != ps2->size) {
    return 0;
  } else {
    return PersonSetIsSubset(ps1, ps2);
  }
  return 0;
}
