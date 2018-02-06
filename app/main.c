/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.c
 * Copyright (C) 2018 Denis Matveev <disson@yandex.ru>
 *
 * myapp is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * myapp is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* 
 * \brief Public C API for the Tor network service.
 *
 * This interface is intended for use by programs that need to link Tor as
 * a library, and launch it in a separate thread.  If you have the ability
 * to run Tor as a separate executable, you should probably do that instead
 * of embedding it as a library.
 *
 * To use this API, first construct a tor_main_configuration_t object using
 * tor_main_configuration_new().  Then, you use one or more other function
 * calls (such as tor_main_configuration_set_command_line() to configure how
 * Tor should be run.  Finally, you pass the configuration object to
 * tor_run_main().
 *
 * At this point, tor_run_main() will block its thread to run a Tor daemon;
 * when the Tor daemon exits, it will return.  See notes on bugs and
 * limitations below.
 *
 * There is no other public C API to Tor: calling any C Tor function not
 * documented in this file is not guaranteed to be stable.
****************************************************************************
 */
/**
 * @file tor_runner.c
 * @brief Experimental module to emulate tor_run_main() API with fork+exec
 *
 * The functions here are meant to allow the application developer to
 * use the tor_run_main() API without having to care whether Tor is
 * running in-process or out-of-process.  For in-process usage, the
 * developer can link Tor as a library and call tor_run_main(); for
 * out-of-process usage, the developer can link this library instead.
 *
 * This interface is EXPERIMENTAL; please let us know if you would like
 * to depend on it.  We don't know yet whether it will be reliable in
 * practice.
 */

/* NOTE: This module is supposed to work without the standard Tor utility
 * functions.  Don't add more dependencies!
 */

#include "myapp.h"


int main(int argc, char ** argv)
{
    tor_main_configuration_t *cfg = tor_main_configuration_new();
    torstart(cfg);


    return 0;



}
