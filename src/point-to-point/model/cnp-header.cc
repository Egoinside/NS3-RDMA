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

#include <stdint.h>
#include <iostream>
#include "cnp-header.h"
#include "ns3/address-utils.h"
#include "ns3/log.h"

NS_LOG_COMPONENT_DEFINE ("CNPHeader");

namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED (CNPHeader);

CNPHeader::CNPHeader (uint16_t sport, uint16_t dport, uint16_t flowid, uint16_t qfb, uint16_t total,
                uint8_t qindex, uint8_t ecnbits, uint32_t seq) :
                m_sport (sport), m_dport(dport), m_flowid(flowid), m_qfb(qfb), m_total(total), 
                m_qindex(qindex), m_ecnbits(ecnbits), m_seq(seq) {}

CNPHeader::CNPHeader () : m_qfb(0), m_ecnbits(0) {}

TypeId 
CNPHeader::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::CNPHeader")
    .SetParent<Header> ()
    .AddConstructor<CNPHeader> ()
  ;
  return tid;
}

TypeId 
CNPHeader::GetInstanceTypeId (void) const
{
    return GetTypeId ();
}

CNPHeader::~CNPHeader () {}

void 
CNPHeader::SetQfb (const uint16_t qfb)
{
    m_qfb = qfb;
}

void 
CNPHeader::SetTotal (const uint16_t total)
{
    m_total = total;
}

void 
CNPHeader::SetQIndex (const uint8_t qindex)
{
    m_qindex = qindex;
}

void 
CNPHeader::SetECNBits (const uint8_t ecnbits)
{
    m_ecnbits = ecnbits;
}

void 
CNPHeader::SetSequence (const uint32_t seq)
{
    m_seq = seq;
}

uint16_t 
CNPHeader::GetFlowId () const
{
    return m_flowid;
}

uint16_t 
CNPHeader::GetQfb () const
{
    return m_qfb;
}

uint16_t 
CNPHeader::GetTotal () const
{
    return m_total;
}

uint8_t 
CNPHeader::GetQIndex () const
{
    return m_qindex;
}

uint8_t 
CNPHeader::GetECNBits () const
{
    return m_ecnbits;
}

uint32_t 
CNPHeader::GetSequence () const
{
    return m_seq;
}
/**
 * pure vultr function in class Header
 */
uint32_t 
CNPHeader::GetSerializedSize (void) const
{
    return 8; // 2+2+2+1+1
}
void 
CNPHeader::Serialize (Buffer::Iterator start) const
{
    start.WriteU16 (m_flowid);
    start.WriteU16 (m_qfb);
    start.WriteU16 (m_total);
    start.WriteU8 (m_qindex);
    start.WriteU8 (m_ecnbits);
}
uint32_t
CNPHeader::Deserialize (Buffer::Iterator start)
{
    m_flowid = start.ReadU16 ();
    m_qfb = start.ReadU16 ();
    m_total = start.ReadU16 ();
    m_qindex = start.ReadU8 ();
    m_ecnbits = start.ReadU8 ();

    return GetSerializedSize ();
}
void 
CNPHeader::Print (std::ostream &os) const
{
    os << " qFb=" << (unsigned) m_qfb << "/" << (unsigned) m_total << std::endl;
}

}

