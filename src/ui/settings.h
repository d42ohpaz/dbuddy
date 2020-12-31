#ifndef BASIC_ICS_SETTINGS_H
#define BASIC_ICS_SETTINGS_H

#include "src/configuration.h"

typedef int (*settings_handler)(configuration_t *);

void settings_init(configuration_t *, settings_handler);

#endif //BASIC_ICS_SETTINGS_H
