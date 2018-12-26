/* Copyright (C) 2009-2018 Greenbone Networks GmbH
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/**
 * @file gmpd.h
 * @brief Headers for the GMP daemon.
 */

#ifndef _GVMD_GMPD_H
#define _GVMD_GMPD_H

#include "types.h"
#include <gvm/util/serverutils.h>
#include <glib.h>
#include <netinet/in.h>
#include <gnutls/gnutls.h>

/**
 * @brief Maximum number of seconds spent trying to read the protocol.
 */
#ifndef READ_PROTOCOL_TIMEOUT
#define READ_PROTOCOL_TIMEOUT 300
#endif

/**
 * @brief Size of \ref from_client and \ref from_scanner data buffers, in bytes.
 */
#define FROM_BUFFER_SIZE 1048576

extern buffer_size_t from_buffer_size;

extern char from_client[];
extern buffer_size_t from_client_start;
extern buffer_size_t from_client_end;
extern char *from_scanner;
extern buffer_size_t from_scanner_start;
extern buffer_size_t from_scanner_end;

extern struct sockaddr_in scanner_address;

int
init_gmpd (GSList*, int, const gchar*, int, int, int, int,
           int (*) (gvm_connection_t *, gchar *),
           int);

void
init_gmpd_process (const gchar *, gchar **);

int
serve_gmp (gvm_connection_t*, const gchar*, gchar**);

#endif /* not _GVMD_GMPD_H */
