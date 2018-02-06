/*
 * myapp.h
 *
 * Copyright (C) 2018 - denis
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef MYAPP_H
#define MYAPP_H
#include "tor_api.h"


int torstart(tor_main_configuration_t*);
int torstop(tor_main_configuration_t *);
int torget(char*); //sends get request
int torpost(char *);//sends post request



#endif
