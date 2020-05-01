/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2007 University of Washington
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Adrian S.-W. Tam <adrian.sw.tam@gmail.com>
 */

#ifndef PAUSE_HEADER_H
#define PAUSE_HEADER_H

#include "ns3/header.h"

namespace ns3 {

/**
 * \ingroup qbb
 * \brief Packet header for PAUSE frame
 * 
 * Simplified PAUSE frame header, not strictly follow qbb standard.
 * This header has two fields: 1. five-tuple flow id; 2. quantized congestion level.
 * \verbatim
 |      0        |      1        |      2        |       3       |
  0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7
 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 |                              time                             |
 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 |                              qlen                             |
 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 |                              qindex                           |
 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * \endverbatim
 * 
 */

class PauseHeader : public Header
{
public:
    PauseHeader (uint32_t time, uint32_t qlen, uint8_t qindex);
    PauseHeader ();
    static TypeId GetTypeId (void);
    virtual TypeId GetInstanceTypeId (void) const; // unkown,  todo
    virtual ~PauseHeader ();

    /**
     * \param time The pause time in microseconds
     */
    void SetTime (uint32_t time);
    void SetQLen (uint32_t qlen);
    void SetQIndex (uint8_t qindex);

    /**
     * \return The pause time in microseconds
     */
    uint32_t GetTime () const;
    uint32_t GetQLen () const;
    uint8_t GetQIndex () const;

    /**
     * pure vultr function in class Header
     */
    uint32_t GetSerializedSize (void) const;
    void Serialize (Buffer::Iterator start) const;
    uint32_t Deserialize (Buffer::Iterator start);
    void Print (std::ostream &os) const;

private:
    uint32_t m_time;    // pause time
    uint32_t m_qlen;    // todo
    uint8_t m_qindex;   // 8 priority queue
};

} // namespace ns3

#endif /* PAUSE_HEADER */