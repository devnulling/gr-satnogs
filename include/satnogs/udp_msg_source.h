/* -*- c++ -*- */
/*
 * gr-satnogs: SatNOGS GNU Radio Out-Of-Tree Module
 *
 *  Copyright (C) 2016, Libre Space Foundation <http://librespacefoundation.org/>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef INCLUDED_SATNOGS_UDP_MSG_SOURCE_H
#define INCLUDED_SATNOGS_UDP_MSG_SOURCE_H

#include <satnogs/api.h>
#include <gnuradio/block.h>

namespace gr
{
  namespace satnogs
  {

    /*!
     * \brief UDP message/command accepter.
     *
     * This block received UDP messages from localhost or other network hosts
     * and produces PMT messages.
     *
     * \ingroup satnogs
     *
     */
    class SATNOGS_API udp_msg_source : virtual public gr::block
    {
    public:
      typedef boost::shared_ptr<udp_msg_source> sptr;

      /**
       * Creates a UDP message accepter block
       * @param addr the address to bind the UDP socket
       * @param port the UDP port to wait for packets
       * @param mtu the maximum MTU. Used to pre-allocate a maximum packet size
       * @param type code of the data type of each message. 0 corresponds to raw
       * bytes, 1 to 32-bit signed integers and 2 to 3 bit unsigned integers.
       */
      static sptr
      make (const std::string& addr, uint16_t port, size_t mtu = 1500,
            size_t type = 0);
    };

  } // namespace satnogs
} // namespace gr

#endif /* INCLUDED_SATNOGS_UDP_MSG_SOURCE_H */

