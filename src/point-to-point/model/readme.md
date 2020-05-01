# Log for RDMA Midification

## PFC Part

1. Add new files: qbb-pause-header.cc/h 
   
   Packet header for PAUSE frame. Simplified PAUSE frame header, not strictly follow qbb standard. This header has two fields: 1. five-tuple flow id; 2. quantized congestion level.
   * compile success
  
2. Add new files: cnp-header.cc/h
   
   Packet header for CNP.
   * compile success

Some uncertain APIs are marked as "todo" in files.

