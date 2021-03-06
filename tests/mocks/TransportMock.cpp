/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * TransportMock.cpp
 * A mock transport layer.
 * Copyright (C) 2015 Simon Newton
 */

#include "TransportMock.h"

#include <gmock/gmock.h>

namespace {
MockTransport *g_transport_mock = NULL;
}

void Transport_SetMock(MockTransport* mock) {
  g_transport_mock = mock;
}

bool Transport_Send(uint8_t token, Command command, uint8_t rc,
                    const IOVec* iovec, unsigned int iovec_count) {
  if (g_transport_mock) {
    return g_transport_mock->Send(token, command, rc, iovec, iovec_count);
  }
  return true;
}
