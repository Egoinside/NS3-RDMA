/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2005 INRIA
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
 * Author: Mathieu Lacage <mathieu.lacage@sophia.inria.fr>
 */

#ifndef CNPHEADER_H
#define CNPHEADER_H

#include "ns3/header.h"

namespace ns3 {

/**
 * \ingroup RoCEv2
 * \brief Header for CNP, congestion notification packet
 *
 * This class has two fields: The five-tuple flow id and the quantized
 * congestion level. 
 */

class CNPHeader : public Header
{
public:
    CNPHeader (uint16_t sport, uint16_t dport, uint16_t flowid, uint16_t qfb, uint16_t total,
                uint8_t qindex, uint8_t ecnbits, uint32_t seq);
    CNPHeader ();
    static TypeId GetTypeId (void);
    virtual TypeId GetInstanceTypeId (void) const; // unknown, todo
    virtual ~CNPHeader ();

    void SetFlowId (const uint16_t flowid);
    /**
     * \param q The quantized feedback value
     */
    void SetQfb (const uint16_t qfb);
    void SetTotal (const uint16_t total);
    void SetQIndex (const uint8_t qindex);
    void SetECNBits (const uint8_t ecnbits);
    void SetSequence (const uint32_t seq);

    uint16_t GetFlowId () const;
    uint16_t GetQfb () const;
    uint16_t GetTotal () const;
    uint8_t GetQIndex () const;
    uint8_t GetECNBits () const;
    uint32_t GetSequence () const;

    /**
     * pure vultr function in class Header
     */
    uint32_t GetSerializedSize (void) const;
    void Serialize (Buffer::Iterator start) const;
    uint32_t Deserialize (Buffer::Iterator start);
    void Print (std::ostream &os) const;

private:
    uint16_t m_sport;   // source port
    uint16_t m_dport;   // dest port
    uint16_t m_flowid;
    uint16_t m_qfb;       // quantized feedback value
    uint16_t m_total;
    uint8_t m_qindex;   // 8 priorities  
    uint8_t m_ecnbits;
    uint32_t m_seq;     // sequence number

    // union // todo
};

} // namespace ns3

#endif /* CNP_HEADER */